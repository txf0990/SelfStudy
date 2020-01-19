#include "NameCalc.h"
#include "gtest/gtest.h"

namespace {

TEST(NameCalcTest, NameCalcTest) {
  
  NameCalc aNameCalc;

  EXPECT_EQ(aNameCalc.CalcName("abcd"), 6);
  EXPECT_EQ(aNameCalc.CalcName("ABCD"), 6);
  EXPECT_EQ(aNameCalc.CalcName("Xiaoming"), 84);
  EXPECT_EQ(aNameCalc.CalcName("Lisa"), 37);
}

}
