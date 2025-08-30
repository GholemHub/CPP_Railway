#pragma once

#include "RailBase.h"


namespace Game::RailWay {
	class Rail_H;
}

class Game::RailWay::Rail_H : public RailBase {

public:
	Rail_H();                       // default constructor
	Rail_H(RailTypes type);
};
