

#include <stdexcept>
#include "Wheel.h"
namespace go
{

const double Wheel::BURST_PRESSURE = 100.0;
const double Wheel::DEFAULT_DIAMETER = 29.0;
const double Wheel::DEFAULT_PRESSURE = 0.0;

Wheel::Wheel(double _diameter, double _pressure)
    : diameter(_diameter), pressure(_pressure), burst(_pressure >= BURST_PRESSURE)
{
    if (pressure < 0)
    {
        throw std::invalid_argument("pressure cannot be negative");
    }
}

double Wheel::getDiameter() const
{
    return diameter;
}

void Wheel::setPressure(double value)
{
    if (value < 0.0)
    {
        throw std::invalid_argument("pressure cannot be negative");
    }
    if (value >= BURST_PRESSURE)
    {
        burst = true;
    }
    if (burst)
    {
        value = 0.0;
    }
    pressure = value;
}

double Wheel::getPressure() const
{
    return pressure;
}

bool Wheel::isFlat() const
{
    return pressure == 0.0;
}

bool Wheel::hasBurst() const
{
    return burst;
}

void Wheel::inflate(double additional)
{
    setPressure(getPressure() + additional);
}
} // namespace go
