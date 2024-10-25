#pragma once

#include "grid.h"
#include "qt_headers.h"

class MyLabel : public QLabel {
public:
    void setGrid(Grid* grid);

    void setPlayer(PlayerOwner* person);

protected:
    virtual void paintEvent(QPaintEvent* e);

private:
    Grid* grid_ = new Grid();
    PlayerOwner* player_owner = new PlayerOwner();
};
