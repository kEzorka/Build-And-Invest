#include "../../includes/land_plot/land_plot.h"

void LandPlot::setCostOfLand(const int64_t& cost) {
	cost_of_land_ = cost;
}

void LandPlot::setOwner(Player* owner) {
	owner_ = owner;
}

void LandPlot::setNameOfLand(const std::string& str) {
	name_of_land_ = str;
}

void LandPlot::updateSupply() {

}

int64_t LandPlot::getCostOfLand() const {
	return cost_of_land_;
}

Player* LandPlot::getOwner() const {
	return owner_;
}

std::string LandPlot::getNameOfLand() const {
	return name_of_land_;
}
