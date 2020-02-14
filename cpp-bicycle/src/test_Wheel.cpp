#include "Wheel.h"
#include "gtest/gtest.h"

using namespace std;
using namespace go;

// https://github.com/google/googletest/blob/master/googletest/docs/primer.md
TEST(Wheel, Defaults) {
  Wheel wheel;
  ASSERT_EQ(wheel.getPressure(),Wheel::DEFAULT_PRESSURE);  
  ASSERT_EQ(wheel.getDiameter(),Wheel::DEFAULT_DIAMETER);
  ASSERT_EQ(wheel.hasBurst(), false);
  ASSERT_EQ(wheel.isFlat(), Wheel::DEFAULT_PRESSURE == 0.0);
}

TEST(Wheel, NegativePressure) {
  double testDiameter = 22.0;
  double testPressure = -1.0;
  ASSERT_THROW(Wheel(testDiameter,testPressure), std::invalid_argument);
}

TEST(Wheel, Specific) {
  double testDiameter = 22.0;
  double testPressure = Wheel::BURST_PRESSURE/2.0;
  Wheel wheel(testDiameter, testPressure);

  ASSERT_EQ(wheel.getPressure(),testPressure);
  ASSERT_EQ(wheel.getDiameter(),testDiameter);
  ASSERT_EQ(wheel.hasBurst(), false);
  ASSERT_EQ(wheel.isFlat(), false);
}

TEST(Wheel, Flat) {
  double testPressure = Wheel::BURST_PRESSURE / 2.0;
  Wheel wheel;
  wheel.setPressure(testPressure);
  ASSERT_EQ(wheel.getPressure(), testPressure);
  ASSERT_EQ(wheel.isFlat(), false);
  wheel.setPressure(0.0);
  ASSERT_EQ(wheel.isFlat(), true);
}

TEST(Wheel,Burst) {
  Wheel wheel;
  
  wheel.setPressure(Wheel::BURST_PRESSURE / 2.0);
  ASSERT_EQ(wheel.isFlat(), false);
  ASSERT_EQ(wheel.hasBurst(), false);
  wheel.setPressure(Wheel::BURST_PRESSURE);
  ASSERT_EQ(wheel.getPressure(), 0.0);
  ASSERT_EQ(wheel.isFlat(), true);
  ASSERT_EQ(wheel.hasBurst(), true);
  wheel.setPressure(Wheel::BURST_PRESSURE / 2.0);
  ASSERT_EQ(wheel.getPressure(), 0.0);
  ASSERT_EQ(wheel.isFlat(), true);
  ASSERT_EQ(wheel.hasBurst(), true);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
