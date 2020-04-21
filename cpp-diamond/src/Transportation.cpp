#include "Transportation.h"

namespace go {

    Transportation::Transportation(bool _started)
      : started(_started) 
    {
    }
    void Transportation::start() {
        started = true;
    }
    void Transportation::stop() {
        started = false;
    }

    bool Transportation::isStarted() const {
        return started;
    }
    bool Transportation::isGoing() const {
        return started;
    }

 }

