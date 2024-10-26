#pragma once

#include "../player.h"

class GroceryAgency {
public:
	virtual void setDefaultSupermarketDemand(const double& demand) final;
	virtual void setDefaultHypermarketDemand(const double& demand) final;

	int64_t getIncome(Player* player_owner, BuildingLand* building_land, const int& month);

	double getCurSupermarketIncome() const;
	double getCurHypermarketIncome() const;
	double getDefaultSupermarketDemand() const;
	double getDefaultHypermarketDemand() const;

private:
	double getCoefByMonth(const int& month);

	double default_supermarket_demand_ = 30;
	double default_hypermarket_demand_ = 25;

	double income_supermarket = 0;
	double income_hypermarket = 0;

};