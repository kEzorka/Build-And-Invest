#include "../../includes/realty/land_plot.h"

void LandPlot::setCostOfLand(const int64_t& cost) {
	cost_of_land_ = cost;
}

void LandPlot::setSquare(const size_t& x, const size_t& y) {
	cells_.resize(x, std::vector<Realty*>(y, nullptr));
}

void LandPlot::setOwner(Player* owner) {
	owner_ = owner;
}

void LandPlot::setNameOfLand(const std::string& str) {
	name_of_land_ = str;
}

int64_t LandPlot::getCostOfLand() const {
	return cost_of_land_;
}

size_t LandPlot::getSquareOfLand() const {
	return (cells_.empty() ? 0 : cells_.size() * cells_[0].size());
}

Player* LandPlot::getOwner() const {
	return owner_;
}

std::string LandPlot::getNameOfLand() const {
	return name_of_land_;
}
