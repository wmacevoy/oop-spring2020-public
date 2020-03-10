#pragma once

#include "Transportation.h"

#include <vector>
#include <memory>
#include "Wheel.h"

namespace go
{

class Car : public Transportation
{

public:
    static const double DEFAULT_FUEL;
    enum WHEEL_INDEX
    {
        FRONT_LEFT,
        FRONT_RIGHT,
        REAR_LEFT,
        REAR_RIGHT
    };

private:
    std::vector<std::shared_ptr<Wheel>> wheels;

private:
    double fuel;

public:
    Car(double _diameter = Wheel::DEFAULT_DIAMETER);

public:
    double getFuel() const;

public:
    void setFuel(double value);

public:
    Wheel &getFrontLeft();

public:
    const Wheel &getFrontLeft() const;

public:
    Wheel &getRearLeft();

public:
    const Wheel &getRearLeft() const;

public:
    Wheel &getFrontRight();

public:
    const Wheel &getFrontRight() const;

public:
    Wheel &getRearRight();

public:
    const Wheel &getRearRight() const;

public:
    bool isFlat() const;

public:
    bool isGoing() const override;
};
} // namespace go
