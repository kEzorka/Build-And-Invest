#include "../../includes/land_plot/building_land.h"
#include "../../includes/agencies/real_estate_agency.h"
#include "../../includes/agencies/grocery_agency.h"

BuildingLand::BuildingLand(std::vector<std::vector<Realty*>> cells,
    const std::string& name_of_land, const int64_t& cost_of_land) 
    : cells_(cells) {
    name_of_land_ = name_of_land;
    cost_of_land_ = cost_of_land;
}

void BuildingLand::setSquareArr(const size_t& x, const size_t& y) {
    cells_.resize(x, std::vector<Realty*>(y, nullptr));
}

void BuildingLand::setCellsArr(std::vector<std::vector<Realty*>> cells) {
    cells_ = cells;
}

void BuildingLand::setOwner(Player* owner) {
    owner_ = owner;
    if (land_estate_agency_ != nullptr) {
        delete land_estate_agency_;
    }
    land_estate_agency_ = new RealEstateAgency();
    if (grocery_agency_ != nullptr) {
        delete grocery_agency_;
    }
    grocery_agency_ = new GroceryAgency();
}

void BuildingLand::build(Realty* realty, const int& x, const int& y) {
    cells_[x][y] = realty;
    House* house = dynamic_cast<House*>(realty);
    Supermarket* supermarket = dynamic_cast<Supermarket*>(realty);
    if (house != nullptr) {
        houses_.push_back(house);
        std::vector<House::FlatType*> flat_type = house->getFlatTypesArr();
        if (!flat_type.empty()) {
            if (flat_type[0]->getFreeFlats() != 0) {
                if (house->getHouseType() == House::HouseType::MonoliticHouse) {
                    has_monolithic_house_supply = true;
                } else if (house->getHouseType() == House::HouseType::PanelHouse) {
                    has_panel_house_supply = true;
                } else if (house->getHouseType() == House::HouseType::BrickHouse) {
                    has_brick_house_supply = true;
                }
            }
        }
    } else if (supermarket != nullptr) {
        supermarkets_.push_back(supermarket);
    }
}

void BuildingLand::makeMonolithicHouseSupplyFalse() {
    has_monolithic_house_supply = false;
}

void BuildingLand::makePanelHouseSupplyFalse() {
    has_panel_house_supply = false;
}

void BuildingLand::makeBrickHouseSupplyFalse() {
    has_brick_house_supply = false;
}

bool BuildingLand::hasMonolithicHouseSupply() const {
    return has_monolithic_house_supply;
}

bool BuildingLand::hasPanelHouseSupply() const {
    return has_panel_house_supply;
}

bool BuildingLand::hasBrickHouseSupply() const {
    return has_brick_house_supply;
}

size_t BuildingLand::getSquareArr() const {
    return (cells_.empty() ? 0 : cells_.size() * cells_[0].size());
}

std::vector<std::vector<Realty*>> BuildingLand::getCells() const {
    return cells_;
}

size_t BuildingLand::getSizeX() const {
    return cells_.empty() ? 0 : cells_[0].size();
}

size_t BuildingLand::getSizeY() const {
    return cells_.size();
}

Realty* BuildingLand::getRealty(const int& pos_x, const int& pos_y) const {
    return cells_[pos_x][pos_y];
}

RealEstateAgency* BuildingLand::getRealEstateAgency() const {
    return land_estate_agency_;
}

GroceryAgency* BuildingLand::getGroceryAgency() const {
    return grocery_agency_;
}

std::vector<House*> BuildingLand::getHouses() const {
    return houses_;
}

std::vector<Supermarket*> BuildingLand::getSupermarkets() const {
    return supermarkets_;
}
