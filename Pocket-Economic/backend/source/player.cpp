#include "../includes/player.h"
#include "../includes/realty/house.h"
#include "../includes/realty/real_estate_agency.h"

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




Supermarket* Player::buySupermarket(RealEstateAgency& real_estate_ageny) {
	Supermarket* supermarket = real_estate_ageny.buySupermarket(this);
	supermarket_arr_.push_back(supermarket);
	return supermarket;
}

House* Player::buyHouse(const RealEstateAgency::HouseType& house_type, RealEstateAgency& real_estate_ageny) {
	House* house = real_estate_ageny.buyHouse(this, house_type);
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
