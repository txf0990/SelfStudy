#include "gtest/gtest.h"
#include <vector>

using std::cout;
using std::endl;
using std::vector;

namespace {

template<typename T> void DisplayVector(const vector<T>& v) {
  for(int i = 0; i < v.size(); i++) {
    std::cout << v[i];
    if (i != v.size() - 1) {
      std::cout << " ";
    } else {
      std::cout << std::endl;
    }
  }
}

TEST(vectorTest, size) {
  vector<int> v;
  EXPECT_EQ(v.size(), 0);
}
TEST(vectorTest, operator_eq) {
  vector<int> v = {0,1,2};
  EXPECT_EQ(v.size(), 3);

  v = {1,3,6,9};
  EXPECT_EQ(v.size(), 4);
}
TEST(vectorTest, front_back) {
  vector<int> v = {0,1,2};
  EXPECT_EQ(v.front(), 0);
  EXPECT_EQ(v.back(), 2);

  v = {3,6,9};
  EXPECT_EQ(v.front(), 3);
  EXPECT_EQ(v.back(), 9);
}
TEST(vectorTest, operator_brackets) {
  vector<int> v = {0,1,2};
  EXPECT_EQ(v[0], 0);
  EXPECT_EQ(v[1], 1);
  EXPECT_EQ(v[2], 2);

  v = {3,6,9};
  EXPECT_EQ(v[0], 3);
  EXPECT_EQ(v[1], 6);
  EXPECT_EQ(v[2], 9);
}
TEST(vectorTest, push_back) {
  vector<int> v;
  EXPECT_EQ(v.size(), 0);
  v.push_back(0);
  EXPECT_EQ(v.size(), 1);
  EXPECT_EQ(v.back(), 0);
  v.push_back(1);
  EXPECT_EQ(v.size(), 2);
  EXPECT_EQ(v.back(), 1);
  v.push_back(2);
  EXPECT_EQ(v.size(), 3);
  EXPECT_EQ(v.back(), 2);
}
TEST(vectorTest, pop_back) {
  vector<int> v = {0,1,2};
  EXPECT_EQ(v.back(), 2);
  EXPECT_EQ(v.size(),3);
  v.pop_back();
  EXPECT_EQ(v.back(), 1);
  EXPECT_EQ(v.size(),2);
  v.pop_back();
  EXPECT_EQ(v.back(), 0);
  EXPECT_EQ(v.size(),1);
}
TEST(vectorTest, iterator) {
  vector<int> v = {0,1,2};
  auto it = v.begin();
  EXPECT_EQ(*it, 0);
  it++;
  EXPECT_EQ(*it, 1);
  it++;
  EXPECT_EQ(*it, 2);
  
  it = v.end();
  it--;
  EXPECT_EQ(*it, 2);
  it--;
  EXPECT_EQ(*it, 1);
}



}
