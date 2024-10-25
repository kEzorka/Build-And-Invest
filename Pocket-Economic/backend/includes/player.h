#pragma once

#include "agencies/land_agency.h"
#include "agencies/building_agency.h"
#include "agencies/advert_agency.h"
#include "land_plot/building_land.h"
#include "land_plot/resort.h"

#include <iostream>
#include <vector>

class Player {
public:
    Player();
    Player(const int64_t& money, const std::string& color);
    virtual void setNickname(const std::string& nickname);
    virtual void setMoney(const int64_t& money);
    virtual void setColor(const std::string& color);
    virtual void updateSpendingMoneyForAdvertForNewStep();

    bool isBot();


    virtual void buyHouseAdvert(const int& cnt_of_advert, const AdvertAgency& advert_agency);
    virtual void buySupermarketAdvert(const int& cnt_of_advert, const AdvertAgency& advert_agency);

    virtual Supermarket* buildSupermarket(const Supermarket::SupermarketType& supermarket_type, 
        const BuildingAgency& real_estate_agency);
    virtual House* buildHouse(const House::HouseType& house_type, const BuildingAgency& real_estate_ageny);
    virtual void buyBuildingLand(BuildingLand* land_plot, const LandAgency& land_agency);
    virtual void buyResort(Resort* land_plot, const LandAgency& land_agency);



    virtual std::string getNickname() const;
    virtual std::vector<Supermarket*> getSupermarketsArr() const;
    virtual std::vector<House*> getHousesArr() const;
    virtual std::vector<LandPlot*> getLandPlotsArr() const;
    virtual int64_t getMoney() const;
    virtual std::string getColor();
    virtual int64_t getCoefOfHouseAdvertThisMonth() const;
    virtual int64_t getCoefOfSupermarketAdvertThisMonth() const;
    virtual RealEstateAgency* getRealEstateAgency() const;

    virtual double getMonolithicIncome() const;
    virtual double getPanelIncome() const;
    virtual double getBrickIncome() const;
    virtual double getSupermarketIncome() const;
    virtual double getHypermarketIncome() const;

    virtual void getIncome(const int& month);

    virtual bool hasSupply() const;

    virtual void updateResort(Resort* resort);

protected:
    void updateIncome();

    std::string nickname_ = "";

    std::vector<House*> house_arr_;
    std::vector<Supermarket*> supermarket_arr_;
    std::vector<LandPlot*> land_plot_arr_;
    int64_t money_ = 0;

    int64_t coef_of_advert_houses_this_month_ = 0;
    int64_t coef_of_advert_houses_next_month_ = 0;

    int64_t coef_of_advert_supermarket_this_month_ = 0;

    RealEstateAgency* player_estate_agency_ = nullptr;

    std::string color_ = "";

    double income_monolithic_house_ = 0;
    double income_panel_house_ = 0;
    double income_brick_house_ = 0;
    double income_supermarket_house_ = 0;
    double income_hypermarket_house_ = 0;
};
