#include "../includes/player.h"
#include "../includes/realty/house.h"
#include "../includes/realty/realty.h"

void Player::setNickname(const std::string& nickname) {
	nickname_ = nickname;
}

void Player::setMoney(const int64_t& money) {
	money_ = money;
}




void Player::giveSupermarket(Supermarket* supermarket) {
	supermarket_arr_.push_back(supermarket);
}

void Player::giveHouses(House* house) {
	house_arr_.push_back(house);
}

void Player::giveLandPlot(LandPlot* land_plot) {
	land_plot_arr_.push_back(land_plot);
}




void Player::buySupermarket() {
	//buy realty using real estate agency
}

void Player::buyHouse() {
	//buy house using real estate agency
}

void Player::buyLandPlot() {
	//buy land plot using real estate agency
}




std::string Player::getNickname() const {
	return nickname_;
}

std::vector<Supermarket*> Player::getSupermarketsArr() const {
	return supermarket_arr_;
}

std::vector<House*> Player::getHousesArr() const {
	return house_arr_;
}

std::vector<LandPlot*> Player::getLandPlotsArr() const {
	return land_plot_arr_;
}

int64_t Player::getMoney() const {
	return money_;
}
