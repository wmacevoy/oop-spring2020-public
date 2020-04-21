#pragma once

#include <memory>

namespace go {

    class Transportation {
    private: bool started;

    public: Transportation(); // default only because of virtual inheritance
    public: virtual void start();
    public: virtual void stop();

    public: virtual bool isStarted() const;
    public: virtual bool isGoing() const;
    public: virtual ~Transportation();
    };

    typedef std::shared_ptr < Transportation > TransportationPtr;
 }

