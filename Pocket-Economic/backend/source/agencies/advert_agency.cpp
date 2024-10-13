#include "../../includes/agencies/advert_agency.h"
#include "../../includes/player.h"

int64_t AdvertAgency::buyAdvert(Player* player, const int& cnt_of_advert) const {
	int64_t player_money = player->getMoney();
	int64_t cost_of_advert = cost_of_one_advert_ * cnt_of_advert;
	if (player_money < cost_of_advert) {
		throw std::runtime_error("player does not have enough money to buy so many advert");
	}
	player->setMoney(player_money - cost_of_advert);
	return cost_of_advert;
}

void AdvertAgency::setCostOfOneAdvert(const int64_t& cost) {
	cost_of_one_advert_ = cost;
}

void AdvertAgency::setBoostOfSalesValue(const double& boost) {
	boost_of_sales_value_ = boost;
}

int64_t AdvertAgency::getCostOfOneAdvert() const {
	return cost_of_one_advert_;
}

double AdvertAgency::getBoostOfSalesValue() const {
	return boost_of_sales_value_;
}
