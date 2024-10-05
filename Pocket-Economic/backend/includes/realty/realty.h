#pragma once

#include <iostream>

class Realty {
public:
	void setBuildingCost(const int64_t& cost);
	int64_t getBuildingCost() const;

protected:
	int64_t building_cost;


};
