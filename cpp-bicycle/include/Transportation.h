#pragma once

namespace go {

    class Transportation {
    private: bool started;

    public: Transportation(bool _started = false);
    public: virtual void start();
    public: virtual void stop();

    public: virtual bool isStarted() const;
    public: virtual bool isGoing() const;
    };
 }

