#include <stdexcept>
#include "Bicycle.h"
namespace go
{

Bicycle::Bicycle(const std::string &_color, double _diameter)
    : Transportation(false), color(_color), wheels(2)
{
  wheels[0] = std::shared_ptr<Wheel>(new Wheel(_diameter));
  wheels[1] = std::shared_ptr<Wheel>(new Wheel(_diameter));
}

const std::string &Bicycle::getColor() const { return color; }
void Bicycle::setColor(const std::string &value) { color = value; }

Wheel &Bicycle::getFront() { return *wheels[0]; }
const Wheel &Bicycle::getFront() const { return *wheels[0]; }

Wheel &Bicycle::getRear() { return *wheels[1]; }
const Wheel &Bicycle::getRear() const { return *wheels[1]; }

bool Bicycle::isFlat() const { return getFront().isFlat() || getRear().isFlat(); }

bool Bicycle::isGoing() const { return isStarted() && !isFlat(); }

} // namespace go
