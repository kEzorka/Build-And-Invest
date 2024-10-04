#pragma once
#include <iostream>

class LandPlot {
public:
	void setCostOfLand(const int64_t& cost);
	void setSquare(const int& square);

	int64_t getCostOfLand() const;
	int getSquare() const;

private:
	int64_t cost_of_land_;
	int square_; //in cells

};

