#include "../../includes/agencies/land_agency.h"
#include "../../includes/player.h"

void LandAgency::buyBuildingLand(Player* player, const int& size_x, const int& size_y) const {
	int64_t cost_of_land = cost_of_cell_ * size_x * size_y * size_x * size_y / 10;
	if (player->getMoney() < cost_of_land) {
		throw std::runtime_error("player does not have enough money to buy this land");
	}
	player->setMoney(player->getMoney() - cost_of_land);
}

void LandAgency::buyResort(Player* player) const {
	if (player->getMoney() < cost_of_resort_) {
		throw std::runtime_error("player does not have enough money to buy this land");
	}
	player->setMoney(player->getMoney() - cost_of_resort_);
}
