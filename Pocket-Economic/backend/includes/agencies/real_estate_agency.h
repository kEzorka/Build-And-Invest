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

	virtual void addMonoliticHouseDemand(const double& demand) final;
	virtual void addMonoliticHouseDemand(double&& demand) final;
	virtual void addPanelHouseDemand(const double& demand) final;
	virtual void addPanelHouseDemand(double&& demand) final;
	virtual void addBrickHouseDemand(const double& demand) final;
	virtual void addBrickHouseDemand(double&& demand) final;

	virtual double getDefaultMonolicticHouseDemand() const final;
	virtual double getDefaultPanelHouseDemand() const final;
	virtual double getDefaultBrickHouseDemand() const final;

	int64_t getIncome(Player* player_owner, BuildingLand* building_land, const int& month);

	void makeDemand(Player* player_owner, BuildingLand* building_land, const int& month);

	void updateDemand();
	void giveDemandForPlayer(Player* player_owner);
	void giveDemandForGlobalRealEsateAgency(RealEstateAgency& real_estate_agency);

	double getCurMonolithicIncome() const;
	double getCurPanelIncome() const;
	double getCurBrickIncome() const;

	double getCurMonolithicDemand() const;
	double getCurPanelDemand() const;
	double getCurBrickDemand() const;

private:
	inline double getCoefByMonth(const int& month) const;

	double monolithic_house_demand_ = 0;
	double panel_house_demand_ = 0;
	double brick_house_demand_ = 0;

	double default_monolitic_house_demand_ = 1.25;
	double default_panel_house_demand_ = 1.5;
	double default_brick_house_demand_ = 1;

	double income_monolithic_house_ = 0;
	double income_panel_house_ = 0;
	double income_brick_house_ = 0;
};
