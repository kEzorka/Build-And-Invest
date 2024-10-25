#include "../../includes/player.h"
#include "../../includes/agencies/real_estate_agency.h"
#include "../../includes/agencies/grocery_agency.h"

void BuildingAgency::makeStandarts() {
	House::Flat* monolitic_flat = new House::Flat(50, 200'000);
	House::Flat* panel_flat = new House::Flat(50, 250'000);
	House::Flat* brick_flat = new House::Flat(50, 300'000);
	House::FlatType* monolithic_flat_type = new House::FlatType(monolitic_flat, 60, 60);
	House::FlatType* panel_flat_type = new House::FlatType(panel_flat, 60, 60);
	House::FlatType* brick_flat_type = new House::FlatType(brick_flat, 60, 60);

	monolithic_house_standard_ = new House();
	panel_house_standard_ = new House();
	brick_house_standard_ = new House();
	supermarket_standard_ = new Supermarket();
	hypermarket_standard_ = new Supermarket();

	monolithic_house_standard_->pushFlatType(monolithic_flat_type);
	panel_house_standard_->pushFlatType(panel_flat_type);
	brick_house_standard_->pushFlatType(brick_flat_type);

	monolithic_house_standard_->setBuildingCost(6'000'000);
	panel_house_standard_->setBuildingCost(7'000'000);
	brick_house_standard_->setBuildingCost(8'000'000);

	monolithic_house_standard_->setBuildingTime(4);
	panel_house_standard_->setBuildingTime(4);
	brick_house_standard_->setBuildingTime(4);

	monolithic_house_standard_->setHouseType(House::HouseType::MonoliticHouse);
	panel_house_standard_->setHouseType(House::HouseType::PanelHouse);
	brick_house_standard_->setHouseType(House::HouseType::BrickHouse);


	supermarket_standard_->setBuildingCost(4'000'000);
	supermarket_standard_->setBuildingTime(4);
	supermarket_standard_->setSupermarketType(Supermarket::SupermarketType::Supermarket);
	supermarket_standard_->setCostOfOneProduct(10'000);

	hypermarket_standard_->setBuildingCost(5'000'000);
	hypermarket_standard_->setBuildingTime(4);
	hypermarket_standard_->setSupermarketType(Supermarket::SupermarketType::Hypermarket);
	hypermarket_standard_->setCostOfOneProduct(40'000);
}

void BuildingAgency::setMonolithicHouseBuildingTime(const int64_t& building_time) {
	monolithic_house_standard_->setBuildingTime(building_time);
}

void BuildingAgency::setPanelHouseBuildingTime(const int64_t& building_time) {
	panel_house_standard_->setBuildingTime(building_time);
}

void BuildingAgency::setBrickHouseBuildingTime(const int64_t& building_time) {
	brick_house_standard_->setBuildingTime(building_time);
}

void BuildingAgency::setSupermarketBuildingTime(const int64_t& building_time) {
	supermarket_standard_->setBuildingTime(building_time);
}

void BuildingAgency::setHypermarketBuildingTime(const int64_t& building_time) {
	hypermarket_standard_->setBuildingTime(building_time);
}

void BuildingAgency::setMonoliticHouseBuildingCost(const int64_t& cost) {
	monolithic_house_standard_->setBuildingCost(cost);
}

void BuildingAgency::setPanelHouseBuildingCost(const int64_t& cost) {
	panel_house_standard_->setBuildingCost(cost);
}

void BuildingAgency::setBrickHouseBuildingCost(const int64_t& cost) {
	brick_house_standard_->setBuildingCost(cost);
}

void BuildingAgency::setSupermarketBuildingCost(const int64_t& cost) {
	supermarket_standard_->setBuildingCost(cost);
}

void BuildingAgency::setHypermarketBuildingCost(const int64_t& cost) {
	hypermarket_standard_->setBuildingCost(cost);
}

void BuildingAgency::setCostOfMonolithicHouseSquareMeter(const int64_t& cost) {
	std::vector<House::FlatType*> arr = monolithic_house_standard_->getFlatTypesArr();
	if (!arr.empty()) {
		arr[0]->getFlat()->setCostOfSquareMeter(cost);
	}
}

void BuildingAgency::setCostOfPanelHouseSquareMeter(const int64_t& cost) {
	std::vector<House::FlatType*> arr = panel_house_standard_->getFlatTypesArr();
	if (!arr.empty()) {
		arr[0]->getFlat()->setCostOfSquareMeter(cost);
	}
}

void BuildingAgency::setCostOfBrickHouseSquareMeter(const int64_t& cost) {
	std::vector<House::FlatType*> arr = brick_house_standard_->getFlatTypesArr();
	if (!arr.empty()) {
		arr[0]->getFlat()->setCostOfSquareMeter(cost);
	}
}

void BuildingAgency::setCostOfOneSupermarketProduct(const int64_t& cost) {
	supermarket_standard_->setCostOfOneProduct(cost);
}

void BuildingAgency::setCostOfOneHypermarketProduct(const int64_t& cost) {
	hypermarket_standard_->setCostOfOneProduct(cost);
}





int64_t BuildingAgency::getMonolithicHouseBuildingTime() const {
	return monolithic_house_standard_->getBuildingTime();
}

int64_t BuildingAgency::getPanelHouseBuildingTime() const {
	return panel_house_standard_->getBuildingTime();
}

int64_t BuildingAgency::getBrickHouseBuildingTime() const {
	return brick_house_standard_->getBuildingTime();
}

int64_t BuildingAgency::getSupermarketBuildingTime() const {
	return supermarket_standard_->getBuildingTime();
}

int64_t BuildingAgency::getHypermarketBuildingTime() const {
	return hypermarket_standard_->getBuildingTime();
}

int64_t BuildingAgency::getMonolithicHouseBuildingCost() const {
	return monolithic_house_standard_->getBuildingCost();
}

int64_t BuildingAgency::getPanelHouseBuildingCost() const {
	return panel_house_standard_->getBuildingCost();
}

int64_t BuildingAgency::getBrickHouseBuildingCost() const {
	return brick_house_standard_->getBuildingCost();
}

int64_t BuildingAgency::getSupermarketBuildingCost() const {
	return supermarket_standard_->getBuildingCost();
}

int64_t BuildingAgency::getHypermarketBuildingCost() const {
	return hypermarket_standard_->getBuildingCost();
}

int64_t BuildingAgency::getCostOfMonolithicHouseSquareMeter() const {
	std::vector<House::FlatType*> arr = monolithic_house_standard_->getFlatTypesArr();
	if (!arr.empty()) {
		return arr[0]->getFlat()->getCostOfSquareMeter();
	}
	return 0;
}

int64_t BuildingAgency::getCostOfPanelHouseSquareMeter() const {
	std::vector<House::FlatType*> arr = panel_house_standard_->getFlatTypesArr();
	if (!arr.empty()) {
		return arr[0]->getFlat()->getCostOfSquareMeter();
	}
	return 0;
}

int64_t BuildingAgency::getCostOfBrickHouseSquareMeter() const {
	std::vector<House::FlatType*> arr = brick_house_standard_->getFlatTypesArr();
	if (!arr.empty()) {
		return arr[0]->getFlat()->getCostOfSquareMeter();
	}
	return 0;
}

int64_t BuildingAgency::getCostOfOneSupermarketProduct() const {
	return supermarket_standard_->getCostOfOneProduct();
}

int64_t BuildingAgency::getCostOfOneHypermarketProduct() const {
	return hypermarket_standard_->getCostOfOneProduct();
}

House* BuildingAgency::getMonolithicHouseStandard() const {
	return monolithic_house_standard_;
}

House* BuildingAgency::getPanelHouseStandard() const {
	return panel_house_standard_;
}

House* BuildingAgency::getBrickHouseStandard() const {
	return brick_house_standard_;
}

Supermarket* BuildingAgency::getSupermarketStandard() const {
	return supermarket_standard_;
}

Supermarket* BuildingAgency::getHypermarketStandard() const {
	return hypermarket_standard_;
}




House* BuildingAgency::buyHouse(Player* player, const House::HouseType& house_type) const {
	int64_t building_cost;
	int64_t player_money = player->getMoney();
	House* house = nullptr;
	switch (house_type) {
	case House::HouseType::MonoliticHouse: {
		building_cost = monolithic_house_standard_->getBuildingCost();
		if (player_money < building_cost) {
			//throw std::runtime_error("player does not have enough money to buy this house");
			return nullptr;
		}
		player->setMoney(player_money - building_cost);
		house = new House(*monolithic_house_standard_);
		break;
	}
	case House::HouseType::PanelHouse: {
		building_cost = panel_house_standard_->getBuildingCost();
		if (player_money < building_cost) {
			//throw std::runtime_error("player does not have enough money to buy this house");
			return nullptr;
		}
		player->setMoney(player_money - building_cost);
		house = new House(*panel_house_standard_);
		break;
	}
	case House::HouseType::BrickHouse: {
		building_cost = brick_house_standard_->getBuildingCost();
		if (player_money < building_cost) {
			//throw std::runtime_error("player does not have enough money to buy this house");
			return nullptr;
		}
		player->setMoney(player_money - building_cost);
		house = new House(*brick_house_standard_);
		break;
	}
	}

	if (house != nullptr) {
		house->setOwner(player);
	}

	return house;
}

Supermarket* BuildingAgency::buySupermarket(Player* player, 
	const Supermarket::SupermarketType& supermarket_type) const {
	int64_t building_cost;
	int64_t player_money = player->getMoney();
	Supermarket* supermarket = nullptr;

	switch (supermarket_type) {
	case Supermarket::SupermarketType::Supermarket: {
		building_cost = supermarket_standard_->getBuildingCost();
		if (player_money < building_cost) {
			//throw std::runtime_error("player does not have enough money to buy this house");
			return nullptr;
		}
		player->setMoney(player_money - building_cost);
		supermarket = new Supermarket(*supermarket_standard_);
		break;
	}
	case Supermarket::SupermarketType::Hypermarket: {
		building_cost = hypermarket_standard_->getBuildingCost();
		if (player_money < building_cost) {
			throw std::runtime_error("player does not have enough money to buy this house");
			return nullptr;
		}
		player->setMoney(player_money - building_cost);
		supermarket = new Supermarket(*hypermarket_standard_);
		break;
	}
	}

	if (supermarket != nullptr) {
		supermarket->setOwner(player);
	}
	return supermarket;
}
