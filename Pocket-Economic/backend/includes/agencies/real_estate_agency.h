#pragma once

#include "../realty/house.h"
#include "../realty/supermarket.h"
#include "../realty/non_build_realty.h"

class RealEstateAgency {
public:
	virtual void setMonoliticHouseDemand(const double& demand) final;
	virtual void setMonoliticHouseDemand(double&& demand) final;
	virtual void setPanelHouseDemand(const double& demand) final;
	virtual void setPanelHouseDemand(double&& demand) final;
	virtual void setBrickHouseDemand(const double& demand) final;
	virtual void setBrickHouseDemand(double&& demand) final;

	virtual void setMonoliticHouseSupply(const double& supply) final;
	virtual void setMonoliticHouseSupply(double&& supply) final;
	virtual void setPanelHouseSupply(const double& supply) final;
	virtual void setPanelHouseSupply(double&& supply) final;
	virtual void setBrickHouseSupply(const double& supply) final;
	virtual void setBrickHouseSupply(double&& supply) final;


	int64_t getIncome();

private:
	double monolithic_house_demand_ = 0;
	double monolithic_house_supply_ = 0;
	double panel_house_demand_ = 0;
	double panel_house_supply_ = 0;
	double brick_house_demand_ = 0;
	double brick_house_supply_ = 0;

	double defualt_monolitic_house_supply_ = 0.5;
	double defualt_panel_house_supply_ = 1;
	double defualt_brick_house_supply_ = 1;
};

