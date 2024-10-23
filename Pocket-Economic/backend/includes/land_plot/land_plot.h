#pragma once

#include <iostream>
#include <vector>
#include "../realty/house.h"
#include "../realty/supermarket.h"

class Player;
class LandAgency;

class LandPlot {
public:
	LandPlot() = default;
	LandPlot(const int64_t& cost_of_land);
	LandPlot(int64_t&& cost_of_land);
	virtual void setCostOfLand(const int64_t& cost);
	virtual void setCostOfLand(int64_t&& cost);
	virtual void setOwner(Player* owner);
	virtual void setNameOfLand(const std::string& str);
	virtual void updateSupply();


	int64_t getIncome() const;
	virtual int64_t getCostOfLand() const;
	virtual Player* getOwner() const;
	virtual std::string getNameOfLand() const;

protected:
	int64_t cost_of_land_ = 0;
	Player* owner_ = nullptr;
	std::string name_of_land_ = "";
};
