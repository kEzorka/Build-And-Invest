#pragma once
#include <iostream>

#include "bot.h"

class Game;

class SecondBot : virtual public Bot {
public:
	SecondBot();

	virtual void step(Game* game) override;

private:

};
