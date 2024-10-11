#pragma once

#include "house.h"
#include "supermarket.h"
#include "non_build_realty.h"

class RealEstateAgency {
public:
	enum class HouseType {
		MonoliticHouse,
		PanelHouse,
		BrickHouse
	};
public:
	House* buyHouse(Player* player, const HouseType& house_type);
	Supermarket* buySupermarket(Player* player);
	void makeStandardHouses();

private:
	House monolithic_house_standard_;
	House panel_house_standard_;
	House brick_house_standard_;
	Supermarket supermarket_standard_;

	int64_t cost_of_square_meter_ = 0;

};

