#include "../../includes/realty/land_plot.h"

void LandPlot::setCostOfLand(const int64_t& cost) {
	cost_of_land_ = cost;
}

void LandPlot::setSquare(const int& square) {
	square_ = square;
}

int64_t LandPlot::getCostOfLand() const {
	return cost_of_land_;
}

int LandPlot::getSquare() const {
	return square_;
}
