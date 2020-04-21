#pragma once

#include "Car.h"
#include "Bicycle.h"

#include <vector>
#include <memory>
#include "Wheel.h"

namespace go
{

class PedalCar : public Car, public Bicycle
{

public:
    static const double DEFAULT_FUEL;

public:
    PedalCar(const std::string &_color, double _diameter = Wheel::DEFAULT_DIAMETER);


public:
    bool isFlat() const override;

public:
    bool isGoing() const override;
};

typedef std::shared_ptr < PedalCar > PedalCarPtr;

} // namespace go
