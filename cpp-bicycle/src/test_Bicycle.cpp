#include "Wheel.h"
#include "Bicycle.h"
#include "gtest/gtest.h"

using namespace std;
using namespace go;

// https://github.com/google/googletest/blob/master/googletest/docs/primer.md
TEST(Bicycle, Defaults) {
  Bicycle bicycle("blue");
  ASSERT_EQ(bicycle.getColor(),"blue");
  ASSERT_EQ(bicycle.getFront().getDiameter(),Wheel::DEFAULT_DIAMETER);
  ASSERT_EQ(bicycle.getRear().getDiameter(),Wheel::DEFAULT_DIAMETER);    
}

TEST(Bicycle, Specific) {
  double testDiameter = 22.0;
  Bicycle bicycle("blue",testDiameter);
  ASSERT_EQ(bicycle.getColor(),"blue");
  ASSERT_EQ(bicycle.getFront().getDiameter(),testDiameter);
  ASSERT_EQ(bicycle.getRear().getDiameter(),testDiameter);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
