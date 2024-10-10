#include "../../includes/realty/realty.h"

void Realty::setBuildingCost(const int64_t& cost) {
    building_cost_ = cost;
}

void Realty::setBuildingTime(const int64_t& time) {
    building_time_ = time;
}

void Realty::setOwner(Player* owner) {
    owner_ = owner;
}

void Realty::setLandPlot(LandPlot* land_plot) {
    land_plot_ = land_plot;
}

void Realty::setDemand(const int& demand) {
    demand_ = demand;
}

void Realty::setSupply(const int& supply) {
    supply_ = supply;
}

void Realty::setCalamity(Calamity* calamity) {
    cur_calamity_ = calamity;
}




int64_t Realty::getBuildingCost() const {
    return building_cost_;
}

int64_t Realty::getBuildingTime() const {
    return building_time_;
}

Player* Realty::getOwner() const {
    return owner_;
}

LandPlot* Realty::getLandPlot() const {
    return land_plot_;
}

int Realty::getDemand() const {
    return demand_;
}

int Realty::getSupply() const {
    return supply_;
}

Calamity* Realty::getCalamity() {
    return cur_calamity_;
}




bool Realty::isBuilt() const {
    return building_time_ == 0 ? true : false;
}

void Realty::buyAdvert() {

}
