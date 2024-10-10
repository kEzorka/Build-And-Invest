#pragma once

#include "realty/real_estate_agency.h"
#include "land_plot/building_land.h"
#include "land_plot/resort.h"

#include <iostream>
#include <vector>

class Player {
public:
	void setNickname(const std::string& nickname);
	void setMoney(const int64_t& money);



	void giveSupermarket(Supermarket* supermarket);
	void giveHouses(House* house);
	void giveLandPlot(LandPlot* land_plot);
	void buySupermarket();
	void buyHouse();
	void buyLandPlot();



	std::string getNickname() const;
	std::vector<Supermarket*> getSupermarketsArr() const;
	std::vector<House*> getHousesArr() const;
	std::vector<LandPlot*> getLandPlotsArr() const;
	int64_t getMoney() const;

private:
	std::string nickname_;

	std::vector<House*> house_arr_;
	std::vector<Supermarket*> supermarket_arr_;
	std::vector<LandPlot*> land_plot_arr_;
	int64_t money_ = 0;

};
