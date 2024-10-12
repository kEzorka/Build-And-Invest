#pragma once
#include <iostream>

class Player;

class AdvertAgency {
public:
	int64_t buyAdvert(Player* player, const int& cnt_of_advert) const;
	//////////////////////////////////
	//
	// return how many money does the player spent for advert
	// 
	//////////////////////////////////

	void setCostOfOneAdvert(const int64_t& cost);
	void setBoostOfSalesValue(const double& boost);

	int64_t getCostOfOneAdvert() const;
	double getBoostOfSalesValue() const;

private:
	int64_t cost_of_one_advert_ = 0;
	double boost_of_sales_value_ = 0.5; // in percents

};
