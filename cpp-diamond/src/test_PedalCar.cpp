#include "Wheel.h"
#include "PedalCar.h"
#include "gtest/gtest.h"

using namespace std;
using namespace go;

// https://github.com/google/googletest/blob/master/googletest/docs/primer.md
TEST(PedalCar, Defaults) {
  PedalCar pedalCar("blue");
  ASSERT_EQ(pedalCar.getColor(),"blue");
  ASSERT_EQ(pedalCar.getFront().getDiameter(),Wheel::DEFAULT_DIAMETER);
  ASSERT_EQ(pedalCar.getRear().getDiameter(),Wheel::DEFAULT_DIAMETER);    
}


int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
