#include "Transportation.h"
#include "Car.h"
#include "Bicycle.h"
#include "gtest/gtest.h"

using namespace std;
using namespace go;

// https://github.com/google/googletest/blob/master/googletest/docs/primer.md
TEST(Transportation, AsObjects) {
  Transportation transportation;
  Car car;
  car.start();
  car.setFuel(0.0);
  ASSERT_EQ(car.isGoing(),false);
  transportation = car; // copy the transportation parts of car to transportation
  ASSERT_EQ(transportation.isGoing(),false);
}

TEST(Transportation, AsPointers) {
  TransportationPtr transportation = TransportationPtr(new Transportation());
  CarPtr car = CarPtr(new Car());
  car->start();
  car->setFuel(0.0);
  ASSERT_EQ(car->isGoing(),false);
  transportation = car; // transportation is now an alias for car
  // refcounted transportation is deleted
  ASSERT_EQ(transportation->isGoing(),false);
  // refcounted car is deleted
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
