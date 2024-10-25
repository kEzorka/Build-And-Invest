#pragma once
#include <iostream>

#include "bot.h"

class Game;

class FirstBot : virtual public Bot {
public:
	FirstBot();

	virtual void step(Game* game) override;

private:

};
