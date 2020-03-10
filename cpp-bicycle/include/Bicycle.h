#pragma once

#include "Transportation.h"

#include <vector>
#include <memory>
#include "Wheel.h"

namespace go
{

class Bicycle : public Transportation
{
private:
    std::vector<std::shared_ptr<Wheel>> wheels;

private:
    std::string color;

public:
    Bicycle(const std::string &_color, double _diameter = Wheel::DEFAULT_DIAMETER);

public:
    const std::string &getColor() const;

public:
    void setColor(const std::string &value);

public:
    Wheel &getFront();

public:
    const Wheel &getFront() const;

public:
    Wheel &getRear();

public:
    const Wheel &getRear() const;

public:
    bool isFlat() const;

public:
    bool isGoing() const override;
};
} // namespace go
