#pragma once

#include "framework.h"

namespace Game::RailWay {
    class RailBase;
}

class Game::RailWay::RailBase {
private:
    POINT point{};
public:
    virtual ~RailBase()
    {}

    RailBase()
    {}

    RailBase(const POINT& point): point(point)
    {}

    virtual void Draw() = 0;

    
};
