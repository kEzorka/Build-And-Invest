#pragma once

#include "land_plot.h"
class RealEstateAgency;
class GroceryAgency;

class BuildingLand : public virtual LandPlot {
public:
	BuildingLand() = default;
	BuildingLand(std::vector<std::vector<Realty*>> cells,
		const std::string& name_of_land = "");
	BuildingLand(const BuildingLand&) = default;
	BuildingLand(BuildingLand&&) = default;
	BuildingLand& operator=(const BuildingLand&) = default;
	BuildingLand& operator=(BuildingLand&&) = default;


	void setSquareArr(const size_t& x, const size_t& y);
	void setCellsArr(std::vector<std::vector<Realty*>> cells);
	void setOwner(Player* owner);


	size_t getSquareArr() const;
	std::vector<std::vector<Realty*>> getCells() const;
	size_t getSizeX() const;
	size_t getSizeY() const;
	Realty* getRealty(const int& x, const int& y) const;
	RealEstateAgency* getRealEstateAgency() const;
	GroceryAgency* getGroceryAgency() const;
	std::vector<House*> getHouses() const;
	std::vector<Supermarket*> getSupermarkets() const;


	void build(Realty* realty, const int& x, const int& y);

	void makeMonolithicHouseSupplyFalse();
	void makePanelHouseSupplyFalse();
	void makeBrickHouseSupplyFalse();

	bool hasMonolithicHouseSupply() const;
	bool hasPanelHouseSupply() const;
	bool hasBrickHouseSupply() const;

private:
	std::vector<std::vector<Realty*>> cells_;
	std::vector<House*> houses_;
	std::vector<Supermarket*> supermarkets_;

	bool has_monolithic_house_supply = false;
	bool has_panel_house_supply = false;
	bool has_brick_house_supply = false;
	RealEstateAgency* land_estate_agency_ = nullptr;
	GroceryAgency* grocery_agency_ = nullptr;
};
