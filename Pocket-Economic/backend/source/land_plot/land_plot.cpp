#include "../../includes/land_plot/land_plot.h"
#include "../../includes/agencies/real_estate_agency.h"

LandPlot::LandPlot(const int64_t& cost_of_land) : cost_of_land_(cost_of_land) {}

LandPlot::LandPlot(int64_t&& cost_of_land) : cost_of_land_(cost_of_land) {}

void LandPlot::setCostOfLand(const int64_t& cost) {
	cost_of_land_ = cost;
}

void LandPlot::setCostOfLand(int64_t&& cost) {
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

int64_t LandPlot::getIncome() const {
	return 0;
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
