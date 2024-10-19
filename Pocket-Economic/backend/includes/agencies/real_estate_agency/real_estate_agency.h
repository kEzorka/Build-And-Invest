#pragma once

#include "../../realty/house.h"
#include "../../realty/supermarket.h"
#include "../../realty/non_build_realty.h"

class RealEstateAgency {
public:
	virtual void setMonoliticHouseDemand(const int& demand);
	virtual void setMonoliticHouseDemand(int&& demand);
	virtual void setPanelHouseDemand(const int& demand);
	virtual void setPanelHouseDemand(int&& demand);
	virtual void setBrickHouseDemand(const int& demand);
	virtual void setBrickHouseDemand(int&& demand);

	virtual void setMonoliticHouseSupply(const int& supply);
	virtual void setMonoliticHouseSupply(int&& supply);
	virtual void setPanelHouseSupply(const int& supply);
	virtual void setPanelHouseSupply(int&& supply);
	virtual void setBrickHouseSupply(const int& supply);
	virtual void setBrickHouseSupply(int&& supply);


	int64_t getIncome();

private:
	int monolithic_house_demand_;
	int monolithic_house_supply_;
	int panel_house_demand_;
	int panel_house_supply_;
	int brick_house_demand_;
	int brick_house_supply_;

};

