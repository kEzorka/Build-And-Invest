#include "../includes/player.h"
#include "../includes/agencies/real_estate_agency.h"
#include "../includes/agencies/grocery_agency.h"
#include "../includes/standard_classes.h"
#include "../bots/includes/bot.h"


extern StandardClasses* standard_classes;

Player::Player() {
    player_estate_agency_ = new RealEstateAgency(*(standard_classes->real_estate_agency_standard_));
}

Player::Player(const int64_t& money, const std::string& color = "#000000")
    : money_(money), color_(color) {
    player_estate_agency_ = new RealEstateAgency(*(standard_classes->real_estate_agency_standard_));
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

bool Player::isBot() {
    Bot* bot_ptr = dynamic_cast<Bot*>(this);
    if (bot_ptr != nullptr) {
        return true;
    }
    return false;
}




void Player::buyHouseAdvert(const int& cnt_of_advert, const AdvertAgency& advert_agency) {
    int64_t cost_of_advert = advert_agency.buyHouseAdvert(this, cnt_of_advert);
    if (cost_of_advert == -1) {
        return;
    }
    coef_of_advert_houses_this_month_ += cnt_of_advert * advert_agency.getBoostOfHouseSalesValue();
    coef_of_advert_houses_next_month_ += cnt_of_advert * advert_agency.getBoostOfHouseSalesValue();
}

void Player::buySupermarketAdvert(const int& cnt_of_advert, const AdvertAgency& advert_agency) {
    int64_t cost_of_advert = advert_agency.buySupermarketAdvert(this, cnt_of_advert);
    if (cost_of_advert == -1) {
        return;
    }
    coef_of_advert_supermarket_this_month_ +=
        cnt_of_advert * advert_agency.getBoostOfSupermarketSalesValue();
}

Supermarket* Player::buildSupermarket(const Supermarket::SupermarketType& supermarket_type,
    const BuildingAgency& building_agency) {
    Supermarket* supermarket = building_agency.buySupermarket(this, supermarket_type);
    supermarket_arr_.push_back(supermarket);
    return supermarket;
}

House* Player::buildHouse(const House::HouseType& house_type, const BuildingAgency& building_agency) {
    House* house = building_agency.buyHouse(this, house_type);
    house_arr_.push_back(house);
    return house;
}

void Player::buyBuildingLand(BuildingLand* land_plot, const LandAgency& land_agency) {
    if (land_agency.buyBuildingLand(this, land_plot->getSizeX(), land_plot->getSizeY())) {
        land_plot->setOwner(this);
        land_plot_arr_.push_back(land_plot);
    }
}

void Player::buyResort(Resort* land_plot, const LandAgency& land_agency) {
    if (land_agency.buyResort(this)) {
        land_plot->setOwner(this);
        land_plot_arr_.push_back(land_plot);
        land_plot->setCostOfNextUpdate(land_agency.getCostOfResort() * 4);
        land_plot->setCurIncome(land_agency.getCostOfResort());
    }
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
    global_income_ = 0;
    int64_t house_income = 0;
    int64_t supermarket_income = 0;
    int64_t player_income = 0;
    int64_t resort_income = 0;

    for (LandPlot*& land_plot : land_plot_arr_) {
        BuildingLand* building_land = dynamic_cast<BuildingLand*>(land_plot);
        Resort* resort = dynamic_cast<Resort*>(land_plot);
        if (building_land != nullptr) {
            building_land->getRealEstateAgency()->makeDemand(this, building_land, month);
            house_income += building_land->getRealEstateAgency()->getIncome(this, building_land, month);
            building_land->getRealEstateAgency()->giveDemandForPlayer(this);
            supermarket_income += building_land->getGroceryAgency()->getIncome(this, building_land, month);
        }
        else if (resort != nullptr) {
            resort_income += resort->getIncome();
        }
    }

    if (hasSupply()) {
        for (LandPlot*& land_plot : land_plot_arr_) {
            BuildingLand* building_land = dynamic_cast<BuildingLand*>(land_plot);
            if (building_land != nullptr) {
                if (building_land->hasMonolithicHouseSupply() ||
                    building_land->hasBrickHouseSupply() ||
                    building_land->hasPanelHouseSupply()) {
                    player_income += player_estate_agency_->getIncome(this, building_land, month);
                }
            }
        }
    }

    money_ += house_income;
    money_ += supermarket_income;
    money_ += player_income;
    money_ += resort_income;

    global_income_ = house_income + supermarket_income + player_income + resort_income;

    updateIncome();
}


bool Player::hasSupply() const {
    return player_estate_agency_->getCurMonolithicDemand() != 0 ||
        player_estate_agency_->getCurPanelDemand() != 0 ||
        player_estate_agency_->getCurBrickDemand() != 0;
}

void Player::updateResort(Resort* resort) {
    resort->update();
}

void Player::updateIncome() {
    for (LandPlot*& land_plot : land_plot_arr_) {
        BuildingLand* building_land = dynamic_cast<BuildingLand*>(land_plot);
        Resort* resort = dynamic_cast<Resort*>(land_plot);
        if (building_land != nullptr) {
            income_monolithic_house_ += building_land->getRealEstateAgency()->getCurMonolithicIncome();
            income_panel_house_ += building_land->getRealEstateAgency()->getCurPanelIncome();
            income_brick_house_ += building_land->getRealEstateAgency()->getCurBrickIncome();
            income_supermarket_house_ += building_land->getGroceryAgency()->getCurSupermarketIncome();
            income_hypermarket_house_ += building_land->getGroceryAgency()->getCurHypermarketIncome();
        } else if (resort != nullptr) {

        }
    }
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

RealEstateAgency* Player::getRealEstateAgency() const {
    return player_estate_agency_;
}

double Player::getMonolithicIncome() const {
    return income_monolithic_house_;
}

double Player::getPanelIncome() const {
    return income_panel_house_;
}

double Player::getBrickIncome() const {
    return income_brick_house_;
}

double Player::getSupermarketIncome() const {
    return income_supermarket_house_;
}

double Player::getHypermarketIncome() const {
    return income_hypermarket_house_;
}

double Player::getGlobalIncome() const {
    return global_income_;
}
