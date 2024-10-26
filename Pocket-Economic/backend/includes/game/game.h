#pragma once

#include <random>
#include <chrono>
#include <utility>
#include "../game/calamity.h"
#include "../agencies/real_estate_agency.h"
#include "news_window.h"
#include "main_game_window.h"
#include "../standard_classes.h"
#include "../../bots/includes/first_bot.h"
#include "../../bots/includes/second_bot.h"
#include "../../bots/includes/third_bot.h"
#include "../../bots/includes/fourth_bot.h"
#include "../../bots/includes/fifth_bot.h"

static std::mt19937 RandNum = std::mt19937{ static_cast<std::mt19937::result_type>(
    std::chrono::steady_clock::now().time_since_epoch().count()) };

class Game {
public:
    friend FirstBot;
    friend SecondBot;
    friend ThirdBot;
    friend FourthBot;
    friend FifthBot;
    friend Bot;

    void start();

    bool finished() const;

    std::string getResults();

    bool nextPlayer();
    void begin();
    //////////////////
    //
    // return TRUE if it's next step of the game
    // return FALSE in another way
    //
    ///////////////////
    
    void setStartMoneyCnt(const int& money);
    void setMovesCnt(const int& moves);

    void pushPlayer(Player* player_owner);
    void pushBot();
    
    std::vector<Player*> getPlayersArr() const;	
    Player* getCurPlayer() const;
    std::vector<std::pair<Player*, std::string>> getFreshNews() const;
    std::vector<std::pair<Player*, std::string>> getBuyNews() const;
    void clearBuyNewsArr();
    int getMovesCnt() const;
    int getStartMoneyCnt() const;

    const int INF = -1;


    void buildHouse(Player* player_owner, BuildingLand* building_land, const House::HouseType& house_type,
        const int& building_pos_x, const int& building_pos_y);
    void buildSupermarket(Player* player_owner, BuildingLand* building_land,
        const Supermarket::SupermarketType& house_type,
        const int& building_pos_x, const int& building_pos_y);
    void buyLand(Player* player_owner, const int& pos_x, const int& pos_y);
    void buyBuildingLand(Player* player_owner, const int& pos_x, const int& pos_y);
    void buyResort(Player* player_owner, const int& pos_x, const int& pos_y);

    void buyHouseAdvert(Player* player_owner, const int& cnt_of_advert) const;
    void buySupermarketAdvert(Player* player_owner, const int& cnt_of_advert) const;


    std::vector<std::vector<LandPlot*>> getLandsArr() const;


    double getMonolithicIncome(Player* player_owner) const;
    double getPanelIncome(Player* player_owner) const;
    double getBrickIncome(Player* player_owner) const;
    double getSupermarketIncome(Player* player_owner) const;
    double getHypermarketIncome(Player* player_owner) const;


    void setDefaultMonolithicHouseDemand(const double& demand);
    void setDefaultPanelHouseDemand(const double& demand);
    void setDefaultBrickHouseDemand(const double& demand);
    void setDefaultSupermarketDemand(const double& demand);
    void setDefaultHypermarketDemand(const double& demand);

    double getDefaultMonolithicHouseDemand() const;
    double getDefaultPanelHouseDemand() const;
    double getDefaultBrickHouseDemand() const;
    double getDefaultSupermarketDemand() const;
    double getDefaultHypermarketDemand() const;

    void setCostOfSquareMeterMonolithic(const int64_t& cost);
    void setCostOfSquareMeterPanel(const int64_t& cost);
    void setCostOfSquareMeterBrick(const int64_t& cost);
    void setCostOfOneProductSupermarket(const int64_t& cost);
    void setCostOfOneProductHypermarket(const int64_t& cost);

    int64_t getCostOfSquareMeterMonolithicHouse() const;
    int64_t getCostOfSquareMeterPanelHouse() const;
    int64_t getCostOfSquareMeterBrickHouse() const;
    int64_t getCostOfOneProductSupermarket() const;
    int64_t getCostOfOneProductHypermarket() const;

    void setCostOfLandCell(const int64_t& cost);
    void setCostOfResort(const int64_t& cost);

    int64_t getCostOfLandCell() const;
    int64_t getCostOfResort() const;

    void setCostOfBuildingMonolithicHouse(const int64_t& cost);
    void setCostOfBuildingPanelHouse(const int64_t& cost);
    void setCostOfBuildingBrickHouse(const int64_t& cost);
    void setCostOfBuildingSupermarket(const int64_t& cost);
    void setCostOfBuildingHypermarket(const int64_t& cost);

    int64_t getCostOfBuildingMonolithicHouse() const;
    int64_t getCostOfBuildingPanelHouse() const;
    int64_t getCostOfBuildingBrickHouse() const;
    int64_t getCostOfBuildingSupermarket() const;
    int64_t getCostOfBuildingHypermarket() const;

    void setTimeOfBuildingMonolithicHouse(const int64_t& time);
    void setTimeOfBuildingPanelHouse(const int64_t& time);
    void setTimeOfBuildingBrickHouse(const int64_t& time);
    void setTimeOfBuildingSupermarket(const int64_t& time);
    void setTimeOfBuildingHypermarket(const int64_t& time);

    int64_t getTimeOfBuildingMonolithicHouse() const;
    int64_t getTimeOfBuildingPanelHouse() const;
    int64_t getTimeOfBuildingBrickHouse() const;
    int64_t getTimeOfBuildingSupermarket() const;
    int64_t getTimeOfBuildingHypermarket() const;

    std::string getMonth() const;

private:
    int default_money_for_player_ = 20'000'000;
    int moves_in_the_game_ = INF;

    void nextGameStep();
    void makeCalamitiesArr();
    void makeLandPlotsArr();


    void buildNonBuildRealty(Player* player_owner, BuildingLand* building_land, const int& x, const int& y);


    NewsWindow news_window_;
    MainGameWindow main_game_window_;

    

    RealEstateAgency* global_real_estate_agency_ = nullptr;
    LandAgency* land_agency_ = nullptr;
    BuildingAgency* building_agency_ = nullptr;
    AdvertAgency* advert_agency_ = nullptr;

    std::vector<Player*> players_arr_; /*players club 7-3-5*/
    Player* cur_player_ = nullptr;
    size_t month_ = 0;
    int cur_player_pos_in_arr_ = 0;

    std::vector<std::vector<LandPlot*>> land_plots_arr_;

};
