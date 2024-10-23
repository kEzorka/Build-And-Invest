#include "../includes/player.h"
#include "../includes/agencies/real_estate_agency.h"
#include "../includes/agencies/grocery_agency.h"

Player::Player() {
    player_estate_agency_ = new RealEstateAgency();
}

Player::Player(const int64_t& money, const std::string& color = "#000000")
    : money_(money), color_(color) {
    player_estate_agency_ = new RealEstateAgency();
}

void Player::setNickname(const std::string& nickname) {
    nickname_ = nickname;
}

void Player::setMoney(const int64_t& money) {
    money_ = money;
}

void Player::setColor(const std::string& color) {
    color_ = color;
}

void Player::updateSpendingMoneyForAdvertForNewStep() {
    coef_of_advert_houses_this_month_ = coef_of_advert_houses_next_month_;
    coef_of_advert_houses_next_month_ = 0;
    coef_of_advert_supermarket_this_month_ = 0;
}




void Player::buyHouseAdvert(const int& cnt_of_advert, const AdvertAgency& advert_agency) {
    int64_t cost_of_advert = advert_agency.buyHouseAdvert(this, cnt_of_advert);
    coef_of_advert_houses_this_month_ += cnt_of_advert * advert_agency.getBoostOfHouseSalesValue();
    coef_of_advert_houses_next_month_ += cnt_of_advert * advert_agency.getBoostOfHouseSalesValue();
}

void Player::buySupermarketAdvert(const int& cnt_of_advert, const AdvertAgency& advert_agency) {
    int64_t cost_of_advert = advert_agency.buySupermarketAdvert(this, cnt_of_advert);
    coef_of_advert_supermarket_this_month_ +=
        cnt_of_advert * advert_agency.getBoostOfSupermarketSalesValue();
}

Supermarket* Player::buildSupermarket(const BuildingAgency& building_agency) {
    Supermarket* supermarket = building_agency.buySupermarket(this);
    supermarket_arr_.push_back(supermarket);
    return supermarket;
}

House* Player::buildHouse(const House::HouseType& house_type, const BuildingAgency& building_agency) {
    House* house = building_agency.buyHouse(this, house_type);
    house_arr_.push_back(house);
    return house;
}

void Player::buyBuildingLand(BuildingLand* land_plot, const LandAgency& land_agency) {
    land_agency.buyBuildingLand(this, land_plot->getSizeX(), land_plot->getSizeY());
    land_plot->setOwner(this);
    land_plot_arr_.push_back(land_plot);
}

void Player::buyResort(Resort* land_plot, const LandAgency& land_agency) {
    land_agency.buyResort(this);
    land_plot->setOwner(this);
    land_plot_arr_.push_back(land_plot);
}




std::string Player::getNickname() const {
    return nickname_;
}

std::vector<Supermarket*> Player::getSupermarketsArr() const {
    return supermarket_arr_;
}

std::vector<House*> Player::getHousesArr() const {
    return house_arr_;
}

std::vector<LandPlot*> Player::getLandPlotsArr() const {
    return land_plot_arr_;
}

int64_t Player::getMoney() const {
    return money_;
}

void Player::getIncome(const int& month) {
    int64_t income = 0;

    for (LandPlot*& land_plot : land_plot_arr_) {
        BuildingLand* building_land = dynamic_cast<BuildingLand*>(land_plot);
        Resort* resort = dynamic_cast<Resort*>(land_plot);
        if (building_land != nullptr) {
            income += building_land->getRealEstateAgency()->getIncome(this, building_land, month);
            income += building_land->getGroceryAgency()->getIncome(this, building_land, month);
        } else if (resort != nullptr) {

        }
    }

    money_ += income;
}

std::string Player::getColor() {
    return color_;
}

int64_t Player::getCoefOfHouseAdvertThisMonth() const {
    return coef_of_advert_houses_this_month_;
}

int64_t Player::getCoefOfSupermarketAdvertThisMonth() const {
    return coef_of_advert_supermarket_this_month_;
}
