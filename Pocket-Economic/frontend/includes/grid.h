#pragma once

#include "player_owner.h"

class Grid {
public:
    struct land_struct {
        int x = 0;
        int y = 0;
        int amount_x = -1;
        int amount_y = -1;
        std::vector<std::vector<bool>> free_space;
        int row = -1;
        int column = -1;
        PlayerOwner owner;
    };
    int cell_size = 25;
    std::vector<land_struct> lands;
    std::vector<land_struct> resorts;
    bool isBuyingProcess = false;
    std::pair< land_struct*, land_struct*> chosen_land = { nullptr, nullptr };
};
