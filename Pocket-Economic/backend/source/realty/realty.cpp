#include "../../includes/realty/realty.h"

void Realty::setBuildingCost(const int64_t& cost) {
	building_cost = cost;
}

int64_t Realty::getBuildingCost() const {
	return building_cost;
}
