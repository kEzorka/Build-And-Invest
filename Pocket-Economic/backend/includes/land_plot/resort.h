#pragma once

#include "land_plot.h"

class Resort : public virtual LandPlot {
public:
	Resort() = default;
	Resort(const std::string& name_of_land = "") {
		name_of_land_ = name_of_land;
	}
	Resort(const Resort&) = default;
	Resort(Resort&&) = default;
	Resort& operator=(const Resort&) = default;
	Resort& operator=(Resort&&) = default;

	void setCostOfNextUpdate(const int64_t& cost);
	void setCurIncome(const int64_t& income);

	virtual int64_t getIncome() const override;

	void update();

private:
	int update_stage_ = 0;

	int64_t cur_income_ = 0;
	int64_t cost_of_next_update_ = 1'000'000;

};
