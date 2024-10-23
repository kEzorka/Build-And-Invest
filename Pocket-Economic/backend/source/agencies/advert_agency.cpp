#include "../../includes/agencies/advert_agency.h"
#include "../../includes/player.h"

int64_t AdvertAgency::buyHouseAdvert(Player* player, const int& cnt_of_advert) const {
	int64_t player_money = player->getMoney();
	int64_t cost_of_advert = cost_of_one_house_advert_ * cnt_of_advert;
	if (player_money < cost_of_advert) {
		throw std::runtime_error("player does not have enough money to buy so many advert");
	}
	player->setMoney(player_money - cost_of_advert);
	return cost_of_advert;
}

int64_t AdvertAgency::buySupermarketAdvert(Player* player, const int& cnt_of_advert) const {
	int64_t player_money = player->getMoney();
	int64_t cost_of_advert = cost_of_one_supermarket_advert_ * cnt_of_advert;
	if (player_money < cost_of_advert) {
		throw std::runtime_error("player does not have enough money to buy so many advert");
	}
	player->setMoney(player_money - cost_of_advert);
	return cost_of_advert;
}

void AdvertAgency::setCostOfOneHouseAdvert(const int64_t& cost) {
	cost_of_one_house_advert_ = cost;
}

void AdvertAgency::setBoostOfHouseSalesValue(const double& boost) {
	boost_of_house_sales_value_ = boost;
}

void AdvertAgency::setCostOfOneSupermarketAdvert(const int64_t& cost) {
	cost_of_one_supermarket_advert_ = cost;
}

void AdvertAgency::setBoostOfSupermarketSalesValue(const double& boost) {
	boost_of_supermarket_sales_value_ = boost;
}


int64_t AdvertAgency::getCostOfOneHouseAdvert() const {
	return cost_of_one_house_advert_;
}

double AdvertAgency::getBoostOfHouseSalesValue() const {
	return boost_of_house_sales_value_;
}

int64_t AdvertAgency::getCostOfOneSupermarketAdvert() const {
	return cost_of_one_supermarket_advert_;
}

double AdvertAgency::getBoostOfSupermarketSalesValue() const {
	return boost_of_supermarket_sales_value_;
}
