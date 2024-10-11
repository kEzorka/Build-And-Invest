#pragma once

#include "building_land.h"
#include "resort.h"

class LandAgency {
public:
	void buyBuildingLand(Player* player, const int& size_x, const int& size_y) const;
	void buyResort(Player* player) const;

private:
	int64_t cost_of_cell_;
	int64_t cost_of_resort_;

};
