#include "../../includes/land_plot/land_plot.h"
#include "../../includes/agencies/real_estate_agency.h"

void LandPlot::setOwner(Player* owner) {
	owner_ = owner;
}

void LandPlot::setNameOfLand(const std::string& str) {
	name_of_land_ = str;
}

void LandPlot::updateSupply() {

}

void LandPlot::setCoords(const std::pair<int, int>& coords) {
	coords_ = coords;
}

int64_t LandPlot::getIncome() const {
	return 0;
}

Player* LandPlot::getOwner() const {
	return owner_;
}

std::string LandPlot::getNameOfLand() const {
	return name_of_land_;
}

std::pair<int, int> LandPlot::getCoords() const {
	return coords_;
}
