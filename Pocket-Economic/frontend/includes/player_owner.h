#pragma once

#include <vector>

class PlayerOwner {
public:
    PlayerOwner();
    enum Color {
        Red,
        Orange,
        Yellow,
        Blue,
        Violet,
        Nobody
    };
    Color color = Nobody;
    std::vector<bool> availiable = std::vector<bool>(5, false);
};
