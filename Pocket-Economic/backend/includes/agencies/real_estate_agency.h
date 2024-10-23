#pragma once

#include "../player.h"

class RealEstateAgency {
public:
	virtual void setDefaultMonoliticDemand(const double& demand) final;
	virtual void setDefaultPanelDemand(const double& demand) final;
	virtual void setDefaultBrickDemand(const double& demand) final;

	virtual void setMonoliticHouseDemand(const double& demand) final;
	virtual void setMonoliticHouseDemand(double&& demand) final;
	virtual void setPanelHouseDemand(const double& demand) final;
	virtual void setPanelHouseDemand(double&& demand) final;
	virtual void setBrickHouseDemand(const double& demand) final;
	virtual void setBrickHouseDemand(double&& demand) final;

	virtual void updateMonoliticHouseDemand(const double& demand) final;
	virtual void updateMonoliticHouseDemand(double&& demand) final;
	virtual void updatePanelHouseDemand(const double& demand) final;
	virtual void updatePanelHouseDemand(double&& demand) final;
	virtual void updateBrickHouseDemand(const double& demand) final;
	virtual void updateBrickHouseDemand(double&& demand) final;


	virtual void setMonoliticHouseSupply(const double& supply) final;
	virtual void setMonoliticHouseSupply(double&& supply) final;
	virtual void setPanelHouseSupply(const double& supply) final;
	virtual void setPanelHouseSupply(double&& supply) final;
	virtual void setBrickHouseSupply(const double& supply) final;
	virtual void setBrickHouseSupply(double&& supply) final;

	virtual double getDefaultMonolicticHouseDemand() const final;
	virtual double getDefaultPanelHouseDemand() const final;
	virtual double getDefaultBrickHouseDemand() const final;

	int64_t getIncome(Player* player, BuildingLand* building_land, const int& month);

private:
	inline double getCoefByMonth(const int& month) const;

	double monolithic_house_demand_ = 0;
	double monolithic_house_supply_ = 0;
	double panel_house_demand_ = 0;
	double panel_house_supply_ = 0;
	double brick_house_demand_ = 0;
	double brick_house_supply_ = 0;

	double default_monolitic_house_demand_ = 1.25;
	double default_panel_house_demand_ = 1.5;
	double default_brick_house_demand_ = 1;
};

