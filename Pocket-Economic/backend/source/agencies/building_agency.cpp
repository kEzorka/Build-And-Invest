#include "../../includes/player.h"

void BuildingAgency::makeStandardHouses() {
	House::Flat* flat = new House::Flat(50);
	House::FlatType* monolithic_flat_type = new House::FlatType(flat, 60, 60);
	House::FlatType* panel_flat_type = new House::FlatType(flat, 60, 60);
	House::FlatType* brick_flat_type = new House::FlatType(flat, 60, 60);
	monolithic_house_standard_.pushFlatType(monolithic_flat_type);
	panel_house_standard_.pushFlatType(panel_flat_type);
	brick_house_standard_.pushFlatType(brick_flat_type);
	monolithic_house_standard_.setBuildingCost(0);
	panel_house_standard_.setBuildingCost(0);
	brick_house_standard_.setBuildingCost(0);
	monolithic_house_standard_.setBuildingTime(0);
	panel_house_standard_.setBuildingTime(0);
	brick_house_standard_.setBuildingTime(0);

	supermarket_standard_.setBuildingCost(0);
	supermarket_standard_.setBuildingTime(0);
}

House* BuildingAgency::buyHouse(Player* player, const HouseType& house_type) const {
	int64_t building_cost;
	int64_t player_money = player->getMoney();
	House* house = nullptr;
	switch (house_type) {
	case HouseType::MonoliticHouse: {
		building_cost = monolithic_house_standard_.getBuildingCost();
		if (player_money < building_cost) {
			throw std::runtime_error("player does not have enough money to buy this house");
		}
		player->setMoney(player_money - building_cost);
		house = new House(monolithic_house_standard_);
		break;
	}
	case HouseType::PanelHouse: {
		building_cost = panel_house_standard_.getBuildingCost();
		if (player_money < building_cost) {
			throw std::runtime_error("player does not have enough money to buy this house");
		}
		player->setMoney(player_money - building_cost);
		house = new House(panel_house_standard_);
		break;
	}
	case HouseType::BrickHouse: {
		building_cost = brick_house_standard_.getBuildingCost();
		if (player_money < building_cost) {
			throw std::runtime_error("player does not have enough money to buy this house");
		}
		player->setMoney(player_money - building_cost);
		house = new House(brick_house_standard_);
		break;
	}
	}

	if (house != nullptr) {
		house->setOwner(player);
	}

	return house;
}

Supermarket* BuildingAgency::buySupermarket(Player* player) const {
	int64_t building_cost;
	int64_t player_money = player->getMoney();
	Supermarket* supermarket = nullptr;
	building_cost = supermarket_standard_.getBuildingCost();
	if (player_money < building_cost) {
		throw std::runtime_error("player does not have enough money to buy this supermarket");
	}
	player->setMoney(player_money - building_cost);
	supermarket = new Supermarket(supermarket_standard_);
	if (supermarket != nullptr) {
		supermarket->setOwner(player);
	}
	return supermarket;
}
