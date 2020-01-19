#include "Student.h"
#include "MockNameCalc.h"
#include "gtest/gtest.h"

namespace {

TEST(StudentTest, StudentTest) {
  std::shared_ptr<MockNameCalc> aMockNameCalc(new MockNameCalc);
  
  EXPECT_CALL(*aMockNameCalc, CalcName(::testing::_))
              .Times(4)
              .WillOnce(testing::Return(12345))
              .WillOnce(testing::Return(67890))
              .WillOnce(testing::Return(13579))
              .WillOnce(testing::Return(24680));

  Student Xiaoming("Xiaoming", aMockNameCalc);
  EXPECT_EQ(Xiaoming.getName(), "Xiaoming");
  EXPECT_EQ(Xiaoming.getID(), 12345);
  Xiaoming.bumpName();
  EXPECT_EQ(Xiaoming.getName(), "Yjbpnjoh");
  EXPECT_EQ(Xiaoming.getID(), 67890);

  Student Lisa("Lisa", aMockNameCalc);
  EXPECT_EQ(Lisa.getName(), "Lisa");
  EXPECT_EQ(Lisa.getID(), 13579);
  Lisa.rollBackName();
  EXPECT_EQ(Lisa.getName(), "Khr`");
  EXPECT_EQ(Lisa.getID(), 24680);
}




}
