#include "Transportation.h"
#include "Car.h"
#include "Bicycle.h"
#include "gtest/gtest.h"

#include <iostream>

#include <memory>
using namespace std;
using namespace go;

// https://github.com/google/googletest/blob/master/googletest/docs/primer.md
TEST(Transportation, CastAsObjects)
{
    Transportation transportation;
    Car car;
    car.start();
    car.setFuel(0.0);
    ASSERT_EQ(car.isGoing(), false);
    transportation = car;                       // copy the transportation parts of car to transportation
    ASSERT_EQ(transportation.isGoing(), false); // fails
}

TEST(Transportation, UpcastAsPointers)
{
    TransportationPtr transportationPtr = TransportationPtr(new Transportation());
    CarPtr carPtr = CarPtr(new Car());
    carPtr->start();
    carPtr->setFuel(0.0);
    ASSERT_EQ(carPtr->isGoing(), false);
    transportationPtr = carPtr; // transportation is now an alias for car
    // refcounted transportation is deleted
    ASSERT_EQ(transportationPtr->isGoing(), false);
    // refcounted car is deleted
}

TEST(Transportation, DowncastAsPointers)
{
    std::cout << "test here." << std::endl;
    try
    {
        // upcast (easy for pointers)
        TransportationPtr transportationPtr(new Bicycle("red"));

        // downcast (may be incorrect, depnding on what transportationPtr has)
        CarPtr carPtr=(dynamic_pointer_cast<Car>(transportationPtr));
        // dynamic pointer does not throw an execption, it returns
        // a null pointer (!carPtr is true) if the cast fails....
        if (transportationPtr && !carPtr) {
            throw bad_cast();
        }
        std::cout << "bad here." << std::endl;
        carPtr->start();
        carPtr->setFuel(0.0);
        ASSERT_EQ(carPtr->isGoing(), false);
        transportationPtr = carPtr; // transportation is now an alias for car
        // refcounted transportation is deleted
        ASSERT_EQ(transportationPtr->isGoing(), false);
        // refcounted car is deleted
    }
    catch (bad_cast &ex)
    {
        std::cout << "ex: " << ex.what() << std::endl;
    }
}
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
