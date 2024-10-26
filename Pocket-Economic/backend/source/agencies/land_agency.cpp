#include "../../includes/agencies/land_agency.h"
#include "../../includes/player.h"

bool LandAgency::buyBuildingLand(Player* player_owner, const int& size_x, const int& size_y) const {
    int64_t cost_of_land = cost_of_cell_ * size_x * size_y * size_x * size_y / 10;
    if (player_owner->getMoney() < cost_of_land) {
        throw std::runtime_error("player does not have enough money to buy this land");
        //return false;
    }
    player_owner->setMoney(player_owner->getMoney() - cost_of_land);
    return true;
}

bool LandAgency::buyResort(Player* player_owner) const {
    if (player_owner->getMoney() < cost_of_resort_) {
        throw std::runtime_error("player does not have enough money to buy this land");
        //return false;
    }
    player_owner->setMoney(player_owner->getMoney() - cost_of_resort_);
    return true;
}

void LandAgency::setCostOfCell(const int64_t& cost) {
    cost_of_cell_ = cost;
}

void LandAgency::setCostOfResort(const int64_t& cost) {
    cost_of_resort_ = cost;
    base_income_of_resort_ = cost * 0.15;
}

int64_t LandAgency::getCostOfCell() const {
    return cost_of_cell_;
}

int64_t LandAgency::getCostOfResort() const {
    return cost_of_resort_;
}
