#pragma once

#include <iostream>
#include <vector>
#include "realty.h"

class Player;

class LandPlot {
public:
	void setCostOfLand(const int64_t& cost);
	void setSquare(const size_t& x, const size_t& y);
	void setOwner(Player* owner);
	void setNameOfLand(const std::string& str);

	int64_t getCostOfLand() const;
	size_t getSquareOfLand() const;
	Player* getOwner() const;
	std::string getNameOfLand() const;

private:
	int64_t cost_of_land_ = 0;
	std::vector<std::vector<Realty*>> cells_;
	Player* owner_ = nullptr;
	std::string name_of_land_ = "";

};

