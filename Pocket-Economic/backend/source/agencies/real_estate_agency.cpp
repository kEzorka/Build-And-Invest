#include "../../includes/player.h"

void RealEstateAgency::setMonoliticHouseDemand(const double& demand) {
	monolithic_house_demand_ /= 10;
	monolithic_house_demand_ += demand;
}

void RealEstateAgency::setMonoliticHouseDemand(double&& demand) {
	monolithic_house_demand_ /= 10;
	monolithic_house_demand_ += demand;
}

void RealEstateAgency::setPanelHouseDemand(const double& demand) {
	panel_house_demand_ /= 10;
	panel_house_demand_ += demand;
}

void RealEstateAgency::setPanelHouseDemand(double&& demand) {
	panel_house_demand_ /= 10;
	panel_house_demand_ += demand;
}

void RealEstateAgency::setBrickHouseDemand(const double& demand) {
	brick_house_demand_ /= 10;
	brick_house_demand_ += demand;
}

void RealEstateAgency::setBrickHouseDemand(double&& demand) {
	brick_house_demand_ /= 10;
	brick_house_demand_ += demand;
}

void RealEstateAgency::setMonoliticHouseSupply(const double& supply) {
	monolithic_house_supply_ /= 10;
	monolithic_house_supply_ += supply;
}

void RealEstateAgency::setMonoliticHouseSupply(double&& supply) {
	monolithic_house_supply_ /= 10;
	monolithic_house_supply_ += supply;
}

void RealEstateAgency::setPanelHouseSupply(const double& supply) {
	panel_house_supply_ /= 10;
	panel_house_supply_ += supply;
}

void RealEstateAgency::setPanelHouseSupply(double&& supply) {
	panel_house_supply_ /= 10;
	panel_house_supply_ += supply;
}

void RealEstateAgency::setBrickHouseSupply(const double& supply) {
	brick_house_supply_ /= 10;
	brick_house_supply_ += supply;
}

void RealEstateAgency::setBrickHouseSupply(double&& supply) {
	brick_house_supply_ /= 10;
	brick_house_supply_ += supply;
}

int64_t RealEstateAgency::getIncome() {
	return 0;
}
