#include "../../includes/player.h"
#include "../../includes/agencies/real_estate_agency.h"

void RealEstateAgency::setDefaultMonoliticDemand(const double& demand) {
    default_monolitic_house_demand_ = demand;
}

void RealEstateAgency::setDefaultPanelDemand(const double& demand) {
    default_panel_house_demand_ = demand;
}

void RealEstateAgency::setDefaultBrickDemand(const double& demand) {
    default_brick_house_demand_ = demand;
}

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


void RealEstateAgency::addMonoliticHouseDemand(const double& demand) {
    monolithic_house_demand_ += demand;
}

void RealEstateAgency::addMonoliticHouseDemand(double&& demand) {
    monolithic_house_demand_ += demand;
}

void RealEstateAgency::addPanelHouseDemand(const double& demand) {
    panel_house_demand_ += demand;
}

void RealEstateAgency::addPanelHouseDemand(double&& demand) {
    panel_house_demand_ += demand;
}

void RealEstateAgency::addBrickHouseDemand(const double& demand) {
    brick_house_demand_ += demand;
}

void RealEstateAgency::addBrickHouseDemand(double&& demand) {
    brick_house_demand_ += demand;
}




double RealEstateAgency::getDefaultMonolicticHouseDemand() const {
    return default_monolitic_house_demand_;
}

double RealEstateAgency::getDefaultPanelHouseDemand() const {
    return default_panel_house_demand_;
}

double RealEstateAgency::getDefaultBrickHouseDemand() const {
    return default_brick_house_demand_;
}

int64_t RealEstateAgency::getIncome(Player* player, BuildingLand* building_land, const int& month) {
    income_monolithic_house = 0;
    income_panel_house = 0;
    income_brick_house = 0;
    

    for (House*& house : building_land->getHouses()) {
        std::vector<House::FlatType*> flat_type_arr = house->getFlatTypesArr();
        if (!flat_type_arr.empty()) {
            int free_flats = flat_type_arr[0]->getFreeFlats();
            if (house->getHouseType() == House::HouseType::MonoliticHouse) {
                if (free_flats <= monolithic_house_demand_) {
                    income_monolithic_house += flat_type_arr[0]->getFlat()->getCostOfSquareMeter() * free_flats;
                    flat_type_arr[0]->setFreeFlatsCnt(0);
                    monolithic_house_demand_ -= free_flats;
                } else {
                    income_monolithic_house += flat_type_arr[0]->getFlat()->getCostOfSquareMeter()
                        * monolithic_house_demand_;
                    flat_type_arr[0]->setFreeFlatsCnt(free_flats - monolithic_house_demand_);
                    monolithic_house_demand_ = 0;
                    building_land->makeMonolithicHouseSupplyFalse();
                }
            } else if (house->getHouseType() == House::HouseType::PanelHouse) {
                if (free_flats <= panel_house_demand_) {
                    income_panel_house += flat_type_arr[0]->getFlat()->getCostOfSquareMeter() * free_flats;
                    flat_type_arr[0]->setFreeFlatsCnt(0);
                    panel_house_demand_ -= free_flats;
                } else {
                    income_panel_house += flat_type_arr[0]->getFlat()->getCostOfSquareMeter()
                        * panel_house_demand_;
                    flat_type_arr[0]->setFreeFlatsCnt(free_flats - panel_house_demand_);
                    panel_house_demand_ = 0;
                    building_land->makePanelHouseSupplyFalse();
                }
            } else if (house->getHouseType() == House::HouseType::BrickHouse) {
                if (free_flats <= brick_house_demand_) {
                    income_brick_house += flat_type_arr[0]->getFlat()->getCostOfSquareMeter() * free_flats;
                    flat_type_arr[0]->setFreeFlatsCnt(0);
                    brick_house_demand_ -= free_flats;
                } else {
                    income_brick_house += flat_type_arr[0]->getFlat()->getCostOfSquareMeter()
                        * brick_house_demand_;
                    flat_type_arr[0]->setFreeFlatsCnt(free_flats - brick_house_demand_);
                    brick_house_demand_ = 0;
                    building_land->makeBrickHouseSupplyFalse();
                }
            }
        }
    }

    return income_monolithic_house + income_panel_house + income_brick_house;
}

void RealEstateAgency::makeDemand(Player* player, BuildingLand* building_land, const int& month) {
    double coef_by_month = getCoefByMonth(month);
    double coef_by_supermarkets = 1 + building_land->getSupermarkets().size() * 0.3;
    double coef_by_advert = 1 + player->getCoefOfHouseAdvertThisMonth() / 100.0;
    double monolitic_demand_coef = default_monolitic_house_demand_
        * coef_by_month * coef_by_supermarkets * coef_by_advert;
    double panel_demand_coef = default_panel_house_demand_
        * coef_by_month * coef_by_supermarkets * coef_by_advert;
    double brick_demand_coef = default_brick_house_demand_
        * coef_by_month * coef_by_supermarkets * coef_by_advert;
    double coef_for_monolitic_house = 0;
    double coef_for_panel_house = 0;
    double coef_for_brick_house = 0;
    for (House*& house : building_land->getHouses()) {
        int64_t time_end_of_bulding = house->getBuildingTime();
        double coef_of_house = 1.0 / (time_end_of_bulding + 1);
        if (time_end_of_bulding == 0) {
            int newness_of_house = house->getNewness();
            if (newness_of_house <= 3) {
                coef_of_house = 1.5;
            } else if (newness_of_house <= 12) {
                coef_of_house = 1.2;
            } else {
                coef_of_house = 1.0;
            }
        }
        if (house->getHouseType() == House::HouseType::MonoliticHouse) {
            coef_for_monolitic_house += coef_of_house;
        } else if (house->getHouseType() == House::HouseType::PanelHouse) {
            coef_for_panel_house += coef_of_house;
        } else if (house->getHouseType() == House::HouseType::BrickHouse) {
            coef_for_brick_house += coef_of_house;
        }
    }
    monolitic_demand_coef *= coef_for_monolitic_house;
    panel_demand_coef *= coef_for_panel_house;
    brick_demand_coef *= coef_for_brick_house;

    addMonoliticHouseDemand(monolitic_demand_coef);
    addPanelHouseDemand(panel_demand_coef);
    addBrickHouseDemand(brick_demand_coef);

    monolithic_house_demand_ = static_cast<int>(monolithic_house_demand_);
    panel_house_demand_ = static_cast<int>(panel_house_demand_);
    brick_house_demand_ = static_cast<int>(brick_house_demand_);
}

void RealEstateAgency::updateDemand() {
    monolithic_house_demand_ /= 10;
    panel_house_demand_ /= 10;
    brick_house_demand_ /= 10;
}

void RealEstateAgency::giveDemandForPlayer(Player* player) {
    if (monolithic_house_demand_ != 0) {
        player->getRealEstateAgency()->addMonoliticHouseDemand(monolithic_house_demand_);
        monolithic_house_demand_ = 0;
    }

    if (panel_house_demand_ != 0) {
        player->getRealEstateAgency()->addPanelHouseDemand(panel_house_demand_);
        panel_house_demand_ = 0;
    }

    if (brick_house_demand_ != 0) {
        player->getRealEstateAgency()->addBrickHouseDemand(brick_house_demand_);
        brick_house_demand_ = 0;
    }
}

void RealEstateAgency::giveDemandForGlobalRealEsateAgency(RealEstateAgency& real_estate_agecny) {
    if (monolithic_house_demand_ != 0) {
        real_estate_agecny.addMonoliticHouseDemand(monolithic_house_demand_);
        monolithic_house_demand_ = 0;
    }

    if (panel_house_demand_ != 0) {
        real_estate_agecny.addPanelHouseDemand(panel_house_demand_);
        panel_house_demand_ = 0;
    }

    if (brick_house_demand_ != 0) {
        real_estate_agecny.addBrickHouseDemand(brick_house_demand_);
        brick_house_demand_ = 0;
    }
}

double RealEstateAgency::getCurMonolithicIncome() const {
    return income_monolithic_house;
}

double RealEstateAgency::getCurPanelIncome() const {
    return income_panel_house;
}

double RealEstateAgency::getCurBrickIncome() const {
    return income_brick_house;
}

double RealEstateAgency::getCurMonolithicDemand() const {
    return monolithic_house_demand_;
}

double RealEstateAgency::getCurPanelDemand() const {
    return panel_house_demand_;
}

double RealEstateAgency::getCurBrickDemand() const {
    return brick_house_demand_;
}


inline double RealEstateAgency::getCoefByMonth(const int& month) const {
    if (month % 12 == 1 || month % 12 == 2) {
        return 0.5;
    } else if (month % 12 == 3 || month % 12 == 4) {
        return 0.7;
    } else if (month % 12 == 5 || month % 12 == 6) {
        return 1.0;
    } else if (month % 12 == 7 || month % 12 == 8) {
        return 1.2;
    } else if (month % 12 == 9) {
        return 1.3;
    } else if (month % 12 == 10 || month % 12 == 11) {
        return 1.5;
    } else {
        return 0.7;
    }
}
