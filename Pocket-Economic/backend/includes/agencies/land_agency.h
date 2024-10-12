#pragma once

#include "../land_plot/building_land.h"
#include "../land_plot/resort.h"

class LandAgency {
public:
	void buyBuildingLand(Player* player, const int& size_x, const int& size_y) const;
	void buyResort(Player* player) const;

private:
	int64_t cost_of_cell_ = 0;
	int64_t cost_of_resort_ = 0;

};
