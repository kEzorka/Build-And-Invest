#include "../../includes/land_plot/building_land.h"

void BuildingLand::setSquareArr(const size_t& x, const size_t& y) {
	cells_.resize(x, std::vector<Realty*>(y, nullptr));
}

void BuildingLand::setCellsArr(std::vector<std::vector<Realty*>> cells) {
	cells_ = cells;
}

void BuildingLand::build(Realty* realty, const int& x, const int& y) {
	cells_[x][y] = realty;
}

size_t BuildingLand::getSquareArr() const {
	return (cells_.empty() ? 0 : cells_.size() * cells_[0].size());
}

std::vector<std::vector<Realty*>> BuildingLand::getCells() const {
	return cells_;
}

size_t BuildingLand::getSizeX() const {
	return cells_.empty() ? 0 : cells_[0].size();
}

size_t BuildingLand::getSizeY() const {
	return cells_.size();
}

Realty* BuildingLand::getRealty(const int& pos_x, const int& pos_y) const {
	return cells_[pos_x][pos_y];
}
