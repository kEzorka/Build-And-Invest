#pragma once
#include <iostream>

#include "bot.h"

class Game;

class ThirdBot : virtual public Bot {
public:
	ThirdBot();

	virtual void step(Game* game) override;

private:

};
