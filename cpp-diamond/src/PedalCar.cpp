#include <stdexcept>
#include "PedalCar.h"
namespace go
{

PedalCar::PedalCar(const std::string &_color, double _diameter)
    : Car(_diameter), Bicycle(_color, _diameter)
{
}

bool PedalCar::isFlat() const
{
    return Car::isFlat() || Bicycle::isFlat();
}

bool PedalCar::isGoing() const { return Car::isGoing(); }

} // namespace go
