#include "../../includes/game/game.h"
#include "../../includes/agencies/grocery_agency.h"
#include "../../includes/agencies/building_agency.h"
#include <algorithm>
//#include "qdebug.h"

extern StandardClasses* standard_classes = nullptr;

void Game::start() {
    makeCalamitiesArr();
    main_game_window_.distrib_calamity_type_ =
        std::uniform_int_distribution<>(0, main_game_window_.calamities_.size() - 1);
    makeLandPlotsArr();

    land_agency_ = new LandAgency();
    global_real_estate_agency_ = new RealEstateAgency();
    advert_agency_ = new AdvertAgency();
    building_agency_ = new BuildingAgency();

    standard_classes = new StandardClasses();
    standard_classes->grocery_agency_standard_ = new GroceryAgency();
    standard_classes->real_estate_agency_standard_ = new RealEstateAgency();

    building_agency_->makeStandarts();

    news_window_.fresh_news_arr_.push_back(std::make_pair(nullptr,
        "Congratulations, our game has started!                                                                 "));
    nextGameStep();
}

bool Game::finished() const {
    return moves_in_the_game_ != INF &&
        month_ > moves_in_the_game_;
}

std::string Game::getResults() {
    std::string results_str;
    std::vector<std::pair<int64_t, Player*>> results_for_player;
    for (Player*& player : players_arr_) {
        results_for_player.push_back(std::make_pair(0, player));
        for (House*& house : player->getHousesArr()) {
            if (!house->isBuilt()) {
                results_for_player.back().first += house->getBuildingCost();
            } else {
                std::vector<House::FlatType*> flat_type_arr = house->getFlatTypesArr();
                if (!flat_type_arr.empty()) {
                    if (house->getHouseType() == House::HouseType::MonoliticHouse) {
                        results_for_player.back().first += flat_type_arr[0]->getFreeFlats() *
                            building_agency_->getCostOfMonolithicHouseSquareMeter();
                    } else if (house->getHouseType() == House::HouseType::PanelHouse) {
                        results_for_player.back().first += flat_type_arr[0]->getFreeFlats() *
                            building_agency_->getCostOfPanelHouseSquareMeter();
                    } else if (house->getHouseType() == House::HouseType::BrickHouse) {
                        results_for_player.back().first += flat_type_arr[0]->getFreeFlats() *
                            building_agency_->getCostOfBrickHouseSquareMeter();
                    }
                }
            }
        }

        for (Supermarket*& supermarket : player->getSupermarketsArr()) {
            if (supermarket->getSupermarketType() == Supermarket::SupermarketType::Supermarket) {
                results_for_player.back().first += 1.6 * building_agency_->getSupermarketBuildingCost();
            } else if (supermarket->getSupermarketType() == Supermarket::SupermarketType::Hypermarket) {
                results_for_player.back().first += 1.6 * building_agency_->getHypermarketBuildingCost();
            }
        }

        for (LandPlot*& land_plot : player->getLandPlotsArr()) {
            Resort* resort = dynamic_cast<Resort*>(land_plot);
            if (resort != nullptr) {
                results_for_player.back().first += resort->getIncome() * 2;
            }
        }

        results_for_player.back().first += player->getMoney();
    }

    std::sort(results_for_player.begin(), results_for_player.end());

    if (results_for_player.size() == 5) {
        results_str += results_for_player[4].second->getNickname() +
            " win the game with " + std::to_string(results_for_player[4].first) + "!\n";

        results_str += results_for_player[3].second->getNickname() +
            " on the second place with " + std::to_string(results_for_player[3].first) + "!\n";

        results_str += results_for_player[2].second->getNickname() +
            " on the third place with " + std::to_string(results_for_player[2].first) + "!\n";

        results_str += results_for_player[1].second->getNickname() +
            " on the fourth place with " + std::to_string(results_for_player[1].first) + "!\n";

        results_str += results_for_player[0].second->getNickname() +
            " on the fifth place with " + std::to_string(results_for_player[0].first) + "!\n";
    } else if (results_for_player.size() == 4) {
        results_str += results_for_player[3].second->getNickname() +
            " win the game with " + std::to_string(results_for_player[3].first) + "!\n";

        results_str += results_for_player[2].second->getNickname() +
            " on the second place with " + std::to_string(results_for_player[2].first) + "!\n";

        results_str += results_for_player[1].second->getNickname() +
            " on the third place with " + std::to_string(results_for_player[1].first) + "!\n";

        results_str += results_for_player[0].second->getNickname() +
            " on the fourth place with " + std::to_string(results_for_player[0].first) + "!\n";
    } else if (results_for_player.size() == 3) {
        results_str += results_for_player[2].second->getNickname() +
            " win the game with " + std::to_string(results_for_player[2].first) + "!\n";

        results_str += results_for_player[1].second->getNickname() +
            " on the second place with " + std::to_string(results_for_player[1].first) + "!\n";

        results_str += results_for_player[0].second->getNickname() +
            " on the third place with " + std::to_string(results_for_player[0].first) + "!\n";
    } else if (results_for_player.size() == 2) {
        results_str += results_for_player[1].second->getNickname() +
            " win the game with " + std::to_string(results_for_player[1].first) + "!\n";

        results_str += results_for_player[0].second->getNickname() +
            " on the second place with " + std::to_string(results_for_player[0].first) + "!\n";
    }
    return results_str;
}

bool Game::nextPlayer() {
    ++cur_player_pos_in_arr_;
    if (cur_player_pos_in_arr_ == players_arr_.size()) {
        cur_player_pos_in_arr_ = 0;
        nextGameStep();
        cur_player_ = players_arr_[cur_player_pos_in_arr_];
        return true;
    }
    cur_player_ = players_arr_[cur_player_pos_in_arr_];
    if (cur_player_->isBot()) {
        Bot* bot_ptr = dynamic_cast<Bot*>(cur_player_);
        bot_ptr->step(this);
    }
    return false;
}

void Game::begin() {
    cur_player_ = players_arr_[0];
}




void Game::setStartMoneyCnt(const int& money) {
    default_money_for_player_ = money;
}

void Game::setMovesCnt(const int& moves) {
    moves_in_the_game_ = moves;
}

void Game::pushPlayer(Player* player) {
    players_arr_.push_back(player);
    player->setMoney(default_money_for_player_);
}

void Game::pushBot() {
    int64_t rand_num = RandNum() % 5;
    if (rand_num == 0) {
        Player* new_bot = new FirstBot();
        new_bot->setMoney(default_money_for_player_);
        players_arr_.push_back(new_bot);
    } else if (rand_num == 1) {
        Player* new_bot = new SecondBot();
        new_bot->setMoney(default_money_for_player_);
        players_arr_.push_back(new_bot);
    } else if (rand_num == 2) {
        Player* new_bot = new ThirdBot();
        new_bot->setMoney(default_money_for_player_);
        players_arr_.push_back(new_bot);
    } else if (rand_num == 3) {
        Player* new_bot = new FourthBot();
        new_bot->setMoney(default_money_for_player_);
        players_arr_.push_back(new_bot);
    } else if (rand_num == 4) {
        Player* new_bot = new FifthBot();
        new_bot->setMoney(default_money_for_player_);
        players_arr_.push_back(new_bot);
    }
}




std::vector<Player*> Game::getPlayersArr() const {
    return players_arr_;
}

Player* Game::getCurPlayer() const {
    return cur_player_;
}
