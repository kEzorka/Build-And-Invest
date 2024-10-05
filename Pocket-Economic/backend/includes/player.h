#pragma once

#include "realty/real_estate_agency.h"

#include <iostream>
#include <vector>

class Player {
public:
	void setNickname(const std::wstring& nickname);
	void setMoney(const int64_t& money);



	void giveSupermarket(Supermarket* supermarket);
	void giveHouses(House* house);
	void giveLandPlot(LandPlot* land_plot);
	void buySupermarket();
	void buyHouse();
	void buyLandPlot();



	std::vector<Supermarket*> getSupermarketsArr() const;
	std::vector<House*> getHousesArr() const;
	std::vector<LandPlot*> getLandPlotsArr() const;
	int64_t getMoney() const;

private:
	std::wstring nickname_;

	std::vector<House*> house_arr_;
	std::vector<Supermarket*> supermarket_arr_;
	std::vector<LandPlot*> land_plot_arr_;
	int64_t money_;

};
