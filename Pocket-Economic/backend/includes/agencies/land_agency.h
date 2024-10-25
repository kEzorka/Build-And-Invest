#pragma once

#include "../land_plot/building_land.h"
#include "../land_plot/resort.h"

class LandAgency {
public:
	void buyBuildingLand(Player* player_owner, const int& size_x, const int& size_y) const;
	void buyResort(Player* player_owner) const;

	void setCostOfCell(const int64_t& cost);
	void setCostOfResort(const int64_t& cost);

	int64_t getCostOfCell() const;
	int64_t getCostOfResort() const;

private:
	int64_t cost_of_cell_ = 300'000;
	int64_t cost_of_resort_ = 10'000'000;
	int64_t base_income_of_resort_ = 1'500'000;

};
