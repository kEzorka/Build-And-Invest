#pragma once

#include "agencies/land_agency.h"
#include "agencies/building_agency.h"
#include "agencies/advert_agency.h"
#include "land_plot/building_land.h"
#include "land_plot/resort.h"

#include <iostream>
#include <vector>

class Player {
public:
	Player();
	Player(const int64_t& money, const std::string& color);
	void setNickname(const std::string& nickname);
	void setMoney(const int64_t& money);
	void setColor(const std::string& color);
	void updateSpendingMoneyForAdvertForNewStep();


	void buyHouseAdvert(const int& cnt_of_advert, const AdvertAgency& advert_agency);
	void buySupermarketAdvert(const int& cnt_of_advert, const AdvertAgency& advert_agency);

	Supermarket* buildSupermarket(const BuildingAgency& real_estate_agency);
	House* buildHouse(const House::HouseType& house_type, const BuildingAgency& real_estate_ageny);
	void buyBuildingLand(BuildingLand* land_plot, const LandAgency& land_agency);
	void buyResort(Resort* land_plot, const LandAgency& land_agency);



	std::string getNickname() const;
	std::vector<Supermarket*> getSupermarketsArr() const;
	std::vector<House*> getHousesArr() const;
	std::vector<LandPlot*> getLandPlotsArr() const;
	int64_t getMoney() const;
	std::string getColor();
	int64_t getCoefOfHouseAdvertThisMonth() const;
	int64_t getCoefOfSupermarketAdvertThisMonth() const;
	RealEstateAgency* getRealEstateAgency() const;

	void getIncome(const int& month);

	bool hasSupply() const;

private:
	std::string nickname_ = "";

	std::vector<House*> house_arr_;
	std::vector<Supermarket*> supermarket_arr_;
	std::vector<LandPlot*> land_plot_arr_;
	int64_t money_ = 0;

	int64_t coef_of_advert_houses_this_month_ = 0;
	int64_t coef_of_advert_houses_next_month_ = 0;

	int64_t coef_of_advert_supermarket_this_month_ = 0;

	RealEstateAgency* player_estate_agency_ = nullptr;

	std::string color_ = "";
};
