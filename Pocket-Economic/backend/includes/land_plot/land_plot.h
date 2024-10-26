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
	virtual void setOwner(Player* owner);
	virtual void setNameOfLand(const std::string& str);
	virtual void updateSupply();
	virtual void setCoords(const std::pair<int, int>& coords);
	

	virtual int64_t getIncome() const;
	virtual Player* getOwner() const;
	virtual std::string getNameOfLand() const;
	virtual std::pair<int, int> getCoords() const;

protected:
	Player* owner_ = nullptr;
	std::string name_of_land_ = "";
	std::pair<int, int> coords_;

};
