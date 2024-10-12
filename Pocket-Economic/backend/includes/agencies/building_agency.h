#pragma once

#include "../realty/house.h"
#include "../realty/supermarket.h"
#include "../realty/non_build_realty.h"

class BuildingAgency {
public:
	enum class HouseType {
		MonoliticHouse,
		PanelHouse,
		BrickHouse
	};
public:
	House* buyHouse(Player* player, const HouseType& house_type) const;
	Supermarket* buySupermarket(Player* player) const;
	void makeStandardHouses();

private:
	House monolithic_house_standard_;
	House panel_house_standard_;
	House brick_house_standard_;
	Supermarket supermarket_standard_;

};