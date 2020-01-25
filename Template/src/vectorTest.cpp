#include "gtest/gtest.h"
#include "vector.h"
//#include <vector>

using std::cout;
using std::endl;
using tutorial::vector;
//using std::vector;

TEST(vectorTest, size) {
  vector<int> v;
  EXPECT_EQ(v.size(), 0);
}
TEST(vectorTest, size1) {
  vector<int> v(8,10);
  EXPECT_EQ(v.size(), 8);
}
TEST(vectorTest, front_back_push_pop) {
  vector<int> v;
  EXPECT_EQ(v.size(), 0);

  v.push_back(0);
  EXPECT_EQ(v.size(), 1);
  EXPECT_EQ(v.front(), 0);
  EXPECT_EQ(v.back(), 0);

  v.push_back(1);
  EXPECT_EQ(v.size(), 2);
  EXPECT_EQ(v.front(), 0);
  EXPECT_EQ(v.back(), 1);
  
  v.push_back(2);
  EXPECT_EQ(v.size(), 3);
  EXPECT_EQ(v.front(), 0);
  EXPECT_EQ(v.back(), 2);

  v.pop_back();
  EXPECT_EQ(v.size(), 2);
  EXPECT_EQ(v.front(), 0);
  EXPECT_EQ(v.back(), 1);

  v.pop_back();
  EXPECT_EQ(v.size(), 1);
  EXPECT_EQ(v.front(), 0);
  EXPECT_EQ(v.back(), 0);
}
TEST(vectorTest, operator_bracket) {
  vector<int> v;

  v.push_back(0);
  v.push_back(3);
  v.push_back(2);
  v.push_back(1);
  EXPECT_EQ(v[0], 0);
  EXPECT_EQ(v[1], 3);
  EXPECT_EQ(v[2], 2);
  EXPECT_EQ(v[3], 1);
}
TEST(vectorTest, operator_eq) {
  vector<int> v;
  EXPECT_EQ(v.size(), 0);
  vector<int> j(8,10);
  j[6] = 7;
  v = j;
  EXPECT_EQ(v.size(), 8);
  EXPECT_EQ(v[3], 10);
  EXPECT_EQ(v[5], 10);
  EXPECT_EQ(v[6], 7);
  EXPECT_EQ(v[7], 10);
}
TEST(vectorTest, iterator) {
  vector<int> v;
  v.push_back(0);
  v.push_back(1);
  v.push_back(2);
  vector<int>::iterator it = v.begin();
  EXPECT_EQ(*it, 0);
  it++;
  EXPECT_EQ(*it, 1);
  it++;
  EXPECT_EQ(*it, 2);
  it++;
  EXPECT_EQ(it, v.end());
  
  it = v.end();
  it--;
  EXPECT_EQ(*it, 2);
  it--;
  EXPECT_EQ(*it, 1);
  it--;
  EXPECT_EQ(*it, 0);
  EXPECT_EQ(it, v.begin());
}
