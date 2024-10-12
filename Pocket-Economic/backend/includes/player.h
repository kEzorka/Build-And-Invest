#pragma once

#include "realty/real_estate_agency.h"
#include "land_plot/land_agency.h"
#include "realty/building_agency.h"

#include <iostream>
#include <vector>

class Player {
public:
	void setNickname(const std::string& nickname);
	void setMoney(const int64_t& money);



	void giveSupermarket(Supermarket* supermarket);
	void giveHouses(House* house);
	void giveLandPlot(LandPlot* land_plot);
	Supermarket* buildSupermarket(const BuildingAgency& real_estate_agency);
	House* buildHouse(const BuildingAgency::HouseType& house_type, const BuildingAgency& real_estate_ageny);
	void buyBuildingLand(BuildingLand* land_plot, const LandAgency& land_agency);
	void buyResort(Resort* land_plot, const LandAgency& land_agency);



	std::string getNickname() const;
	std::vector<Supermarket*> getSupermarketsArr() const;
	std::vector<House*> getHousesArr() const;
	std::vector<LandPlot*> getLandPlotsArr() const;
	int64_t getMoney() const;
	int64_t getIncome() const;

private:
	std::string nickname_;

	std::vector<House*> house_arr_;
	std::vector<Supermarket*> supermarket_arr_;
	std::vector<LandPlot*> land_plot_arr_;
	int64_t money_ = 0;

};
