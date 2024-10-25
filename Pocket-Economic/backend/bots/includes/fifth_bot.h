#pragma once
#include <iostream>

#include "bot.h"

class Game;

class FifthBot : virtual public Bot {
public:
	FifthBot();

	virtual void step(Game* game) override;

private:

};
