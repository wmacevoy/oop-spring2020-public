#include <stdexcept>
#include "Car.h"
namespace go
{
const double Car::DEFAULT_FUEL = 1.0;
Car::Car(double _diameter)
    : Transportation(false), wheels(4), fuel(DEFAULT_FUEL)
{
  wheels[FRONT_LEFT] = std::shared_ptr<Wheel>(new Wheel(_diameter));
  wheels[FRONT_RIGHT] = std::shared_ptr<Wheel>(new Wheel(_diameter));
  wheels[REAR_LEFT] = std::shared_ptr<Wheel>(new Wheel(_diameter));
  wheels[REAR_RIGHT] = std::shared_ptr<Wheel>(new Wheel(_diameter));
}

double Car::getFuel() const { return fuel; }
void Car::setFuel(const double value)
{
  if (value < 0 || value > 1.0)
  {
    throw std::invalid_argument("invalid fuel amount");
  }
  fuel = value;
}

Wheel &Car::getFrontRight() { return *wheels[FRONT_RIGHT]; }
const Wheel &Car::getFrontRight() const { return *wheels[FRONT_RIGHT]; }

Wheel &Car::getRearRight() { return *wheels[REAR_RIGHT]; }
const Wheel &Car::getRearRight() const { return *wheels[REAR_RIGHT]; }

Wheel &Car::getFrontLeft() { return *wheels[FRONT_LEFT]; }
const Wheel &Car::getFrontLeft() const { return *wheels[FRONT_LEFT]; }

Wheel &Car::getRearLeft() { return *wheels[REAR_LEFT]; }
const Wheel &Car::getRearLeft() const { return *wheels[REAR_LEFT]; }
bool Car::isFlat() const
{
  bool ans = false;
  for (auto wheel : wheels)
  {
    ans = ans || wheel->isFlat();
  }
  return ans;
}

bool Car::isGoing() const { return isStarted() && !isFlat() && fuel > 0.0; }

} // namespace go
