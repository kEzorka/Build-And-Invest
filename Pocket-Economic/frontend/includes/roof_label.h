#pragma once

#include "my_label.h"

class RoofLabel : public QLabel {
public:
    RoofLabel();
    void setGrid(Grid* grid);

    void setPlayer(PlayerOwner* person);

    bool object_can_be_built_here = false;
    int chosen_x = 0;
    int chosen_y = 0;

protected:
    virtual void paintEvent(QPaintEvent* e) override;

private:
    Grid* grid_ = nullptr;
    PlayerOwner* player_owner = nullptr;
};
