#pragma once

class Game;

class MainGameWindow {
public:
	friend Game;

private:
	std::uniform_real_distribution<> distrib_calamity_ = std::uniform_real_distribution<>(1.0, 100.0);
	std::uniform_int_distribution<> distrib_calamity_type_ = std::uniform_int_distribution<>(1, 100);
	double calamity_chance_ = 3; //in percents
	std::vector<Calamity*> calamities_;

};