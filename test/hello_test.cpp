#include "ShuntingYard.h"
#include <gtest/gtest.h>
#include "math.h"

TEST(HelloTest, simple) {
  ShuntingYard mycalc;
  EXPECT_EQ(mycalc.calc("9+3"), (9 + 3));
  EXPECT_EQ(mycalc.calc("15-7"), (15 - 7));
  EXPECT_EQ(mycalc.calc("40*5"), (40 * 5));
  EXPECT_EQ(mycalc.calc("50/20"), double(50) / 20);
}

TEST(HelloTest, trigonometry) {
  ShuntingYard mycalc;
  EXPECT_NEAR(mycalc.calc("sin(-0.978)"), sin(-0.978), 0.2);
  EXPECT_NEAR(mycalc.calc("cos(-0.910)"), cos(-0.910), 0.2);
  EXPECT_NEAR(mycalc.calc("asin(-0.284)"), asin(-0.284), 0.2);
  EXPECT_NEAR(mycalc.calc("acos(0.608)"), acos(0.608), 0.2);
  EXPECT_NEAR(mycalc.calc("tg(0.700)"), tan(0.700), 0.2);
  EXPECT_NEAR(mycalc.calc("atg(0.1)"), atan(0.1), 0.2);
}

TEST(HelloTest, ln) {
  ShuntingYard mycalc;
  EXPECT_NEAR(mycalc.calc("ln(10)"), log(10), 0.1);
  EXPECT_NEAR(mycalc.calc("ln(346)"), log(346), 0.2);
  EXPECT_NEAR(mycalc.calc("ln(431)"), log(431), 0.5);
  EXPECT_NEAR(mycalc.calc("ln(945)"), log(945), 1);
}

TEST(HelloTest, complex) {
  ShuntingYard mycalc;
  EXPECT_EQ(mycalc.calc("3+5 - 10   *  15/ 3"), 3+5-10*15/3);
  EXPECT_NEAR(mycalc.calc("ln(5) + asin(0.5) + 10"), log(5) + asin(0.5) + 10, 0.1);
  EXPECT_NEAR(mycalc.calc("asin(-0.15) / cos(0.75) * 5 + 10"), asin(-0.15) / cos(0.75) * 5 + 10, 0.1);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
