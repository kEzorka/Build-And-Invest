#include "../../includes/standard_classes.h"
#include "../../includes/game/game.h"
#include "../../includes/agencies/grocery_agency.h"


extern StandardClasses* standard_classes;

void Game::setDefaultMonolithicHouseDemand(const double& demand) {
    standard_classes->real_estate_agency_standard_->setDefaultMonoliticDemand(demand);
}

void Game::setDefaultPanelHouseDemand(const double& demand) {
    standard_classes->real_estate_agency_standard_->setDefaultPanelDemand(demand);
}

void Game::setDefaultBrickHouseDemand(const double& demand) {
    standard_classes->real_estate_agency_standard_->setDefaultBrickDemand(demand);
}

void Game::setDefaultSupermarketDemand(const double& demand) {
    standard_classes->grocery_agency_standard_->setDefaultSupermarketDemand(demand);
}

void Game::setDefaultHypermarketDemand(const double& demand) {
    standard_classes->grocery_agency_standard_->setDefaultHypermarketDemand(demand);
}

double Game::getDefaultMonolithicHouseDemand() const {
    return standard_classes->real_estate_agency_standard_->getDefaultMonolicticHouseDemand();
}

double Game::getDefaultPanelHouseDemand() const {
    return standard_classes->real_estate_agency_standard_->getDefaultPanelHouseDemand();
}

double Game::getDefaultBrickHouseDemand() const {
    return standard_classes->real_estate_agency_standard_->getDefaultBrickHouseDemand();
}

double Game::getDefaultSupermarketDemand() const {
    return standard_classes->grocery_agency_standard_->getDefaultSupermarketDemand();
}

double Game::getDefaultHypermarketDemand() const {
    return standard_classes->grocery_agency_standard_->getDefaultHypermarketDemand();
}

void Game::setCostOfSquareMeterMonolithic(const int64_t& cost) {
    building_agency_->setCostOfMonolithicHouseSquareMeter(cost);
}

void Game::setCostOfSquareMeterPanel(const int64_t& cost) {
    building_agency_->setCostOfPanelHouseSquareMeter(cost);
}

void Game::setCostOfSquareMeterBrick(const int64_t& cost) {
    building_agency_->setCostOfBrickHouseSquareMeter(cost);
}

void Game::setCostOfOneProductSupermarket(const int64_t& cost) {
    building_agency_->setCostOfOneSupermarketProduct(cost);
}

void Game::setCostOfOneProductHypermarket(const int64_t& cost) {
    building_agency_->setCostOfOneHypermarketProduct(cost);
}

int64_t Game::getCostOfSquareMeterMonolithicHouse() const {
    return building_agency_->getCostOfMonolithicHouseSquareMeter();
}

int64_t Game::getCostOfSquareMeterPanelHouse() const {
    return building_agency_->getCostOfPanelHouseSquareMeter();
}

int64_t Game::getCostOfSquareMeterBrickHouse() const {
    return building_agency_->getCostOfBrickHouseSquareMeter();
}

int64_t Game::getCostOfOneProductSupermarket() const {
    return building_agency_->getCostOfOneSupermarketProduct();
}

int64_t Game::getCostOfOneProductHypermarket() const {
    return building_agency_->getCostOfOneHypermarketProduct();
}

void Game::setCostOfLandCell(const int64_t& cost) {
    land_agency_->setCostOfCell(cost);
}

void Game::setCostOfResort(const int64_t& cost) {
    land_agency_->setCostOfResort(cost);
    Resort* resort_ptr = dynamic_cast<Resort*>(land_plots_arr_[0][0]);
    resort_ptr->setCurIncome(cost * 0.15);
    resort_ptr = dynamic_cast<Resort*>(land_plots_arr_[1][6]);
    resort_ptr->setCurIncome(cost * 0.15);
    resort_ptr = dynamic_cast<Resort*>(land_plots_arr_[4][5]);
    resort_ptr->setCurIncome(cost * 0.15);
}

int64_t Game::getCostOfLandCell() const {
    return land_agency_->getCostOfCell();
}

int64_t Game::getCostOfResort() const {
    return land_agency_->getCostOfResort();
}

void Game::setCostOfBuildingMonolithicHouse(const int64_t& cost) {
    building_agency_->setMonoliticHouseBuildingCost(cost);
}

void Game::setCostOfBuildingPanelHouse(const int64_t& cost) {
    building_agency_->setPanelHouseBuildingCost(cost);
}

void Game::setCostOfBuildingBrickHouse(const int64_t& cost) {
    building_agency_->setBrickHouseBuildingCost(cost);
}

void Game::setCostOfBuildingSupermarket(const int64_t& cost) {
    building_agency_->setSupermarketBuildingCost(cost);
}

void Game::setCostOfBuildingHypermarket(const int64_t& cost) {
    building_agency_->setHypermarketBuildingCost(cost);
}

int64_t Game::getCostOfBuildingMonolithicHouse() const {
    return building_agency_->getMonolithicHouseBuildingCost();
}

int64_t Game::getCostOfBuildingPanelHouse() const {
    return building_agency_->getPanelHouseBuildingCost();
}

int64_t Game::getCostOfBuildingBrickHouse() const {
    return building_agency_->getBrickHouseBuildingCost();
}

int64_t Game::getCostOfBuildingSupermarket() const {
    return building_agency_->getSupermarketBuildingCost();
}

int64_t Game::getCostOfBuildingHypermarket() const {
    return building_agency_->getHypermarketBuildingCost();
}

void Game::setTimeOfBuildingMonolithicHouse(const int64_t& time) {
    building_agency_->setMonolithicHouseBuildingTime(time);
}

void Game::setTimeOfBuildingPanelHouse(const int64_t& time) {
    building_agency_->setPanelHouseBuildingTime(time);
}

void Game::setTimeOfBuildingBrickHouse(const int64_t& time) {
    building_agency_->setBrickHouseBuildingTime(time);
}

void Game::setTimeOfBuildingSupermarket(const int64_t& time) {
    building_agency_->setSupermarketBuildingTime(time);
}

void Game::setTimeOfBuildingHypermarket(const int64_t& time) {
    building_agency_->setHypermarketBuildingTime(time);
}

int64_t Game::getTimeOfBuildingMonolithicHouse() const {
    return building_agency_->getMonolithicHouseBuildingTime();
}

int64_t Game::getTimeOfBuildingPanelHouse() const {
    return building_agency_->getPanelHouseBuildingTime();
}

int64_t Game::getTimeOfBuildingBrickHouse() const {
    return building_agency_->getBrickHouseBuildingTime();
}

int64_t Game::getTimeOfBuildingSupermarket() const {
    return building_agency_->getSupermarketBuildingTime();
}

int64_t Game::getTimeOfBuildingHypermarket() const {
    return building_agency_->getHypermarketBuildingTime();
}
