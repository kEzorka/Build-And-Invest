#include "../../includes/land_plot/building_land.h"

size_t BuildingLand::getSquareArr() const {
	return (cells_.empty() ? 0 : cells_.size() * cells_[0].size());
}

void BuildingLand::setSquareArr(const size_t& x, const size_t& y) {
	cells_.resize(x, std::vector<Realty*>(y, nullptr));
}
