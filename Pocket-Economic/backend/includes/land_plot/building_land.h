#pragma once

#include "land_plot.h"
#include "../agencies/real_estate_agency.h"

class BuildingLand : public virtual LandPlot {
public:
	BuildingLand() = default;
	BuildingLand(std::vector<std::vector<Realty*>> cells, const std::string& name_of_land = "", const int64_t& cost_of_land = 0)
		: cells_(cells) {
		name_of_land_ = name_of_land;
		cost_of_land_ = cost_of_land;
	}
	BuildingLand(const BuildingLand&) = default;
	BuildingLand(BuildingLand&&) = default;
	BuildingLand& operator=(const BuildingLand&) = default;
	BuildingLand& operator=(BuildingLand&&) = default;

	void setSquareArr(const size_t& x, const size_t& y);
	void setCellsArr(std::vector<std::vector<Realty*>> cells);
	void build(Realty* realty, const int& x, const int& y);

	size_t getSquareArr() const;
	std::vector<std::vector<Realty*>> getCells() const;
	size_t getSizeX() const;
	size_t getSizeY() const;
	Realty* getRealty(const int& x, const int& y) const;

private:
	std::vector<std::vector<Realty*>> cells_;

	RealEstateAgency* land_estate_ageny_ = nullptr;
};
