#include "../includes/my_label.h"
#include "../includes/grid.h"

void MyLabel::setGrid(Grid* grid) {
    grid_ = grid;
}

void MyLabel::setPlayer(PlayerOwner* person) {
    player_owner = person;
}

void MyLabel::paintEvent(QPaintEvent* e) {
    QLabel::paintEvent(e);

    if (grid_->isBuyingProcess) {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.setBrush(QBrush(QColor(255, 255, 255, 50)));
        painter.setPen(QPen(QColor(255, 255, 255, 150), 1));
        for (Grid::land_struct& land : grid_->lands) {
            if (land.owner.color == player_owner->color) {
                for (int y = land.y; y < land.y + land.amount_y * grid_->cell_size; y += grid_->cell_size) {
                    for (int x = land.x; x < land.x + land.amount_x * grid_->cell_size; x += grid_->cell_size) {
                        painter.drawRect(QRect(x, y, grid_->cell_size, grid_->cell_size));
                    }
                }
            }
        }
        update();
    }
}
