#pragma once

#include "RailType.h"

namespace Game::RailWay {
    class RailBase;
}

class Game::RailWay::RailBase {
private:
    RailTypes RailType;   
public:
    RailBase();
    RailBase(RailTypes type);

    RailTypes getType() const;
};
