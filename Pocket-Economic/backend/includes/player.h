#pragma once

#include "agencies/land_agency.h"
#include "agencies/building_agency.h"
#include "agencies/advert_agency.h"
#include "agencies/real_estate_agency.h"

#include <iostream>
#include <vector>

class Player {
public:
	void setNickname(const std::string& nickname);
	void setMoney(const int64_t& money);
	void updateSpendingMoneyForAdvertForNewStep();


	void buyAdvert(const int& cnt_of_advert, const AdvertAgency& advert_agency);

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

	int64_t spend_on_advert_this_month_;
	int64_t spend_on_advert_next_month_;

	RealEstateAgency* player_estate_agency_ = nullptr;

};
