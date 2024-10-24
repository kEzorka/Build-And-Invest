#include "../../includes/agencies/grocery_agency.h"

int64_t GroceryAgency::getIncome(Player* player, BuildingLand* building_land, const int& month) {

    double coef_by_month = getCoefByMonth(month);
    double coef_by_houses = 1 + building_land->getHouses().size() * 0.8;
    double coef_by_advert = 1 + player->getCoefOfSupermarketAdvertThisMonth() / 100.0;
    double supermarket_demand_coef = default_supermarket_demand_
        * coef_by_month * coef_by_houses * coef_by_advert;
    double hypermarket_demand_coef = default_hypermarket_demand_
        * coef_by_month * coef_by_houses * coef_by_advert;

    for (Supermarket*& supermarket : building_land->getSupermarkets()) {
        int64_t time_end_of_bulding = supermarket->getBuildingTime();
        double coef_of_house = 1.0 / (time_end_of_bulding + 1);
        if (supermarket->getSupermarketType() == Supermarket::SupermarketType::Supermarket) {
            income_supermarket += supermarket_demand_coef * supermarket->getCostOfOneProduct();
        } else if (supermarket->getSupermarketType() == Supermarket::SupermarketType::Hypermarket) {
            income_hypermarket += hypermarket_demand_coef * supermarket->getCostOfOneProduct();
        }
    }

    return income_supermarket + income_hypermarket;
}

double GroceryAgency::getCurSupermarketIncome() const {
    return income_supermarket;
}

double GroceryAgency::getCurHypermarketIncome() const {
    return income_hypermarket;
}

void GroceryAgency::setDefaultSupermarketDemand(const double& demand) {
    default_supermarket_demand_ = demand;
}

void GroceryAgency::setDefaultHypermrkaetDemand(const double& demand) {
    default_hypermarket_demand_ = demand;
}

double GroceryAgency::getCoefByMonth(const int& month) {
    if (month % 12 == 1 || month % 12 == 2 || month % 12 == 11 || month % 12 == 0) {
        return 2.0;
    } else if (month % 12 == 3 || month % 12 == 4 || month % 12 == 5) {
        return 1.0;
    } else if (month % 12 == 6 || month % 12 == 7) {
        return 1.2;
    } else if (month % 12 == 8 || month % 12 == 9 || month % 12 == 10) {
        return 1.5;
    } else {
        return 0;
    }
}
