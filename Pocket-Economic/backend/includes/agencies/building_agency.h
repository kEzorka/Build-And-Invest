#pragma once

#include "../realty/house.h"
#include "../realty/supermarket.h"
#include "../realty/non_build_realty.h"

class BuildingAgency {
public:
	House* buyHouse(Player* player, const House::HouseType& house_type) const;
	Supermarket* buySupermarket(Player* player) const;
	void makeStandarts();

	void setMonolithicHouseBuildingTime(const int64_t& building_time);
	void setPanelHouseBuildingTime(const int64_t& building_time);
	void setBrickHouseBuildingTime(const int64_t& building_time);
	void setSupermarketBuildingTime(const int64_t& building_time);
	void setHypermarketBuildingTime(const int64_t& building_time);

	void setMonoliticHouseBuildingCost(const int64_t& cost);
	void setPanelHouseBuildingCost(const int64_t& cost);
	void setBrickHouseBuildingCost(const int64_t& cost);
	void setSupermarketBuildingCost(const int64_t& cost);
	void setHypermarketBuildingCost(const int64_t& cost);

	void setCostOfMonolithicHouseSquareMeter(const int64_t& cost);
	void setCostOfPanelHouseSquareMeter(const int64_t& cost);
	void setCostOfBrickHouseSquareMeter(const int64_t& cost);

	void setCostOfOneSupermarketProduct(const int64_t& cost);
	void setCostOfOneHypermarketProduct(const int64_t& cost);

	int64_t getMonolithicHouseBuildingTime() const;
	int64_t getPanelHouseBuildingTime() const;
	int64_t getBrickHouseBuildingTime() const;
	int64_t getSupermarketBuildingTime() const;
	int64_t getHypermarketBuildingTime() const;

	int64_t getMonolithicHouseBuildingCost() const;
	int64_t getPanelHouseBuildingCost() const;
	int64_t getBrickHouseBuildingCost() const;
	int64_t getSupermarketBuildingCost() const;
	int64_t getHypermarketBuildingCost() const;

	int64_t getCostOfMonolithicHouseSquareMeter() const;
	int64_t getCostOfPanelHouseSquareMeter() const;
	int64_t getCostOfBrickHouseSquareMeter() const;

	int64_t getCostOfOneSupermarketProduct() const;
	int64_t getCostOfOneHypermarketProduct() const;

	House* getMonolithicHouseStandard() const;
	House* getPanelHouseStandard() const;
	House* getBrickHouseStandard() const;
	Supermarket* getSupermarketStandard() const;
	Supermarket* getHypermarketStandard() const;

private:
	House* monolithic_house_standard_ = nullptr;
	House* panel_house_standard_ = nullptr;
	House* brick_house_standard_ = nullptr;
	Supermarket* supermarket_standard_ = nullptr;
	Supermarket* hypermarket_standard_ = nullptr;

};