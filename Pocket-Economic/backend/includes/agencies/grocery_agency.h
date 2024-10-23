#pragma once

#include "../player.h"

class GroceryAgency {
public:
	virtual void setDefaultSupermarketDemand(const double& demand) final;
	virtual void setDefaultHypermrkaetDemand(const double& demand) final;

	int64_t getIncome(Player* player, BuildingLand* building_land, const int& month);

private:
	double getCoefByMonth(const int& month);

	double default_supermarket_demand_ = 30;
	double default_hypermarket_demand_ = 25;

};