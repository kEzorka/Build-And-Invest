#pragma once

#include "../../includes/player.h"

class Game;

class Bot : virtual public Player {
public:
	Bot();
	virtual void step(Game* game);

protected:

};