#pragma once

#include <iostream>
#include <vector>
#include "../realty/realty.h"

class Player;

class LandPlot {
public:
	virtual void setCostOfLand(const int64_t& cost);
	virtual void setOwner(Player* owner);
	virtual void setNameOfLand(const std::string& str);

	virtual int64_t getCostOfLand() const;
	virtual Player* getOwner() const;
	virtual std::string getNameOfLand() const;

protected:
	int64_t cost_of_land_ = 0;
	Player* owner_ = nullptr;
	std::string name_of_land_ = "";

};

