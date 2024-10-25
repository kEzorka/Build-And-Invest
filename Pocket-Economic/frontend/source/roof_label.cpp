#include "../includes/roof_label.h"
#include "../includes/my_label.h"

RoofLabel::RoofLabel() {
    grid_ = new Grid();
    player_owner = new PlayerOwner();
}

void RoofLabel::setGrid(Grid* grid) {
    grid_ = grid;
}

void RoofLabel::setPlayer(PlayerOwner* person) {
    player_owner = person;
}

void RoofLabel::paintEvent(QPaintEvent* e) {
    QLabel::paintEvent(e);
    object_can_be_built_here = false;
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    for (Grid::land_struct& land : grid_->lands) {
        auto x = pos().x(), y = pos().y() + 50;
        if (land.x <= x && x <= land.x + land.amount_x * grid_->cell_size &&
            land.y <= y && y <= land.y + land.amount_y * grid_->cell_size) {
            if (land.free_space.size()) {
                int x_in_vector = (x - land.x) / grid_->cell_size;
                int y_in_vector = (y - land.y) / grid_->cell_size;
                if (land.free_space[x_in_vector][y_in_vector] == true && land.owner.color == player_owner->color) {
                    object_can_be_built_here = true;
                    chosen_x = land.x + x_in_vector * grid_->cell_size;
                    chosen_y = land.y + y_in_vector * grid_->cell_size - 50;
                    break;
                }
            }
        }
    }
    painter.setPen(QPen((object_can_be_built_here ? QColor(0, 150, 0, 150) : QColor(255, 0, 0, 150)), 2));
    painter.drawRect(QRect(0, 0, 25, 25));
    update();
}
