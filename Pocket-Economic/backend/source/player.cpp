#include "../includes/player.h"

void Player::setNickname(const std::string& nickname) {
	nickname_ = nickname;
}

void Player::setMoney(const int64_t& money) {
	money_ = money;
}

void Player::updateSpendingMoneyForAdvertForNewStep() {
	spend_on_advert_this_month_ = spend_on_advert_next_month_;
	spend_on_advert_next_month_ = 0;
}





void Player::buyAdvert(const int& cnt_of_advert, const AdvertAgency& advert_agency) {
	int64_t cost_of_advert = advert_agency.buyAdvert(this, cnt_of_advert);
	spend_on_advert_this_month_ += cost_of_advert / 2;
	spend_on_advert_next_month_ += cost_of_advert / 2;
}

Supermarket* Player::buildSupermarket(const BuildingAgency& building_agency) {
	Supermarket* supermarket = building_agency.buySupermarket(this);
	supermarket_arr_.push_back(supermarket);
	return supermarket;
}

House* Player::buildHouse(const BuildingAgency::HouseType& house_type, const BuildingAgency& building_agency) {
	House* house = building_agency.buyHouse(this, house_type);
	house_arr_.push_back(house);
	return house;
}

void Player::buyBuildingLand(BuildingLand* land_plot, const LandAgency& land_agency) {
	land_agency.buyBuildingLand(this, land_plot->getSizeX(), land_plot->getSizeY());
	land_plot->setOwner(this);
	land_plot_arr_.push_back(land_plot);
}

void Player::buyResort(Resort* land_plot, const LandAgency& land_agency) {
	land_agency.buyResort(this);
	land_plot->setOwner(this);
	land_plot_arr_.push_back(land_plot);
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

int64_t Player::getIncome() const {
	//get inclome using real estate agency
	return 0;
}
