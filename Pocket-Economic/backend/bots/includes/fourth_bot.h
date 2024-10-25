#pragma once
#include <iostream>

#include "bot.h"

class Game;

class FourthBot : virtual public Bot {
public:
	FourthBot();

	virtual void step(Game* game) override;

private:

};
