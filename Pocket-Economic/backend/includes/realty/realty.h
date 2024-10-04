#pragma once

#include <iostream>

class Realty {
public:
	void setBuildingCost(const int64_t& cost) { building_cost = cost; }
	int64_t getBuildingCost() const { return building_cost; }

protected:
	int64_t building_cost;

};
