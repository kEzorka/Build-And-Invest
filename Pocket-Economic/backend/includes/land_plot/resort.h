#pragma once

#include "land_plot.h"

class Resort : public virtual LandPlot {
public:
	Resort() = default;
	Resort(const std::string& name_of_land = "", const int64_t& cost_of_land = 0) {
		name_of_land_ = name_of_land;
		cost_of_land_ = cost_of_land;
	}
	Resort(const Resort&) = default;
	Resort(Resort&&) = default;
	Resort& operator=(const Resort&) = default;
	Resort& operator=(Resort&&) = default;

private:

};
