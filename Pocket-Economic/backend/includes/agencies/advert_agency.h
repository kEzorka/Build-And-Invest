#pragma once
#include <iostream>

class Player;

class AdvertAgency {
public:
	int64_t buyHouseAdvert(Player* player, const int& cnt_of_advert) const;
	int64_t buySupermarketAdvert(Player* player, const int& cnt_of_advert) const;
	//////////////////////////////////
	//
	// return how many money does the player spent for advert
	// 
	//////////////////////////////////

	void setCostOfOneHouseAdvert(const int64_t& cost);
	void setBoostOfHouseSalesValue(const double& boost);
	void setCostOfOneSupermarketAdvert(const int64_t& cost);
	void setBoostOfSupermarketSalesValue(const double& boost);

	int64_t getCostOfOneHouseAdvert() const;
	double getBoostOfHouseSalesValue() const;
	int64_t getCostOfOneSupermarketAdvert() const;
	double getBoostOfSupermarketSalesValue() const;

private:
	int64_t cost_of_one_house_advert_ = 3000;
	double boost_of_house_sales_value_ = 0.5; // in percents

	int64_t cost_of_one_supermarket_advert_ = 3000;
	double boost_of_supermarket_sales_value_ = 2.0; // in percents

};
