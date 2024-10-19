#include "../../../includes/player.h"

void RealEstateAgency::setMonoliticHouseDemand(const int& demand) {
	monolithic_house_demand_ = demand;
}

void RealEstateAgency::setMonoliticHouseDemand(int&& demand) {
	monolithic_house_demand_ = demand;
}

void RealEstateAgency::setPanelHouseDemand(const int& demand) {
	panel_house_demand_ = demand;
}

void RealEstateAgency::setPanelHouseDemand(int&& demand) {
	panel_house_demand_ = demand;
}

void RealEstateAgency::setBrickHouseDemand(const int& demand) {
	brick_house_demand_ = demand;
}

void RealEstateAgency::setBrickHouseDemand(int&& demand) {
	brick_house_demand_ = demand;
}

void RealEstateAgency::setMonoliticHouseSupply(const int& supply) {
	monolithic_house_supply_ = supply;
}

void RealEstateAgency::setMonoliticHouseSupply(int&& supply) {
	monolithic_house_supply_ = supply;
}

void RealEstateAgency::setPanelHouseSupply(const int& supply) {
	panel_house_supply_ = supply;
}

void RealEstateAgency::setPanelHouseSupply(int&& supply) {
	panel_house_supply_ = supply;
}

void RealEstateAgency::setBrickHouseSupply(const int& supply) {
	brick_house_supply_ = supply;
}

void RealEstateAgency::setBrickHouseSupply(int&& supply) {
	brick_house_supply_ = supply;
}

int64_t RealEstateAgency::getIncome() {
	return 0;
}
