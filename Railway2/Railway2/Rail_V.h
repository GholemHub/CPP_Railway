#pragma once

#include "RailBase.h"

namespace Game::RailWay {
	class Rail_V;
}


class Game::RailWay::Rail_V : public RailBase {

public:
	Rail_V();                       // default constructor
	Rail_V(RailTypes type);
};

