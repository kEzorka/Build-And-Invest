#include "../includes/third_bot.h"
#include "../../includes/game/game.h"

ThirdBot::ThirdBot() {
    nickname_ = "Bot3";
}

void ThirdBot::step(Game* game) {
    if (game->month_ % 6 == 1) {
        bool bougth_land = false;
        for (size_t row = 0; row < game->land_plots_arr_.size(); ++row) {
            for (size_t column = 0; column < game->land_plots_arr_[row].size(); ++column) {
                BuildingLand* building_land = dynamic_cast<BuildingLand*>(game->land_plots_arr_[row][column]);
                if (building_land != nullptr) {
                    if (building_land->getOwner() == nullptr) {
                        game->buyBuildingLand(this, row, column);
                        bougth_land = true;
                        break;
                    }
                }
            }
            if (bougth_land) {
                break;
            }
        }
    }

    bool buy_house = false;
    bool buy_supermarket = false;
    for (LandPlot*& land_plot : land_plot_arr_) {
        BuildingLand* building_land = dynamic_cast<BuildingLand*>(land_plot);
        if (building_land != nullptr) {
            for (size_t row = 0; row < building_land->getCells().size(); ++row) {
                for (size_t column = 0; column < building_land->getCells()[row].size(); ++column) {
                    if (building_land->getCells()[row][column] == nullptr && !buy_house) {
                        game->buildHouse(this, building_land, House::HouseType::BrickHouse, row, column);
                        buy_house = true;
                    } else if (building_land->getCells()[row][column] == nullptr && !buy_supermarket) {
                        game->buildSupermarket(this, building_land,
                            Supermarket::SupermarketType::Supermarket, row, column);
                        buy_supermarket = true;
                        break;
                    }
                }
                if (buy_house && buy_supermarket) {
                    break;
                }
            }
        }
    }
}
