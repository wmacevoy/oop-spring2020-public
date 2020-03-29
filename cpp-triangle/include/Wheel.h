#pragma once

#include <stdexcept>

namespace go {

    class Wheel {
        public: static const double BURST_PRESSURE;
        public: static const double DEFAULT_DIAMETER;
        public: static const double DEFAULT_PRESSURE;
        public: const double diameter;
        private: double pressure;
        private: bool burst;
        public: Wheel(double _diameter = DEFAULT_DIAMETER, double _pressure = DEFAULT_PRESSURE);
        
        public: double getDiameter() const;

        public: void setPressure(double value);

        public: double getPressure() const;

        public: bool isFlat() const;

        public: bool hasBurst() const;

        public: void inflate(double additional);
    };
 }

