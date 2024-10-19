#pragma once

#include "qt_headers.h"

class Grid {
public:
    struct land_struct {
        int x;
        int y;
        int amount_x;
        int amount_y;
    };
    int cell_size = 25;
    std::vector<land_struct> lands;
    bool isBuyingProcess = false;
};


class MyLabel : public QLabel {
public:
    void setGrid(Grid* grid) {
        grid_ = grid;
    }

    Grid* getGrid() {
        return grid_;
    }

protected:
    virtual void paintEvent(QPaintEvent* e) {
        QLabel::paintEvent(e);

        if (grid_->isBuyingProcess) {
            QPainter painter(this);
            painter.setRenderHint(QPainter::Antialiasing, true);
            painter.setBrush(QBrush(QColor(255, 255, 255, 50)));
            painter.setPen(QPen(QColor(255, 255, 255, 150), 1));
            for (Grid::land_struct& land : grid_->lands) { /// *
                for (int y = land.y; y < land.y + land.amount_y * grid_->cell_size; y += grid_->cell_size) {
                    for (int x = land.x; x < land.x + land.amount_x * grid_->cell_size; x += grid_->cell_size) {
                        painter.drawRect(QRect(x, y, grid_->cell_size, grid_->cell_size));
                    }
                }
            }
            update();
        }
    }
private:
    Grid* grid_ = new Grid();
};

class RoofLabel : public QLabel {
public:
    void setGrid(Grid* grid) {
        grid_ = grid;
    }

    Grid* getGrid() {
        return grid_;
    }
protected:
    virtual void paintEvent(QPaintEvent* e) {
        QLabel::paintEvent(e);
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);
        bool in_correct_place = false;
        for (Grid::land_struct& land : grid_->lands) {
            if (land.x <= pos().x() && pos().x() + 25 <= land.x + land.amount_x * grid_->cell_size &&
                land.y <= pos().y() && pos().y() + 25 <= land.y + land.amount_y * grid_->cell_size) {
                in_correct_place = true;
                break;
            }
        }
        painter.setPen(QPen((in_correct_place ? QColor(0, 255, 0, 150) : QColor(255, 0, 0, 150)), 2));
        if (pos().x() <= 30 && pos().y() <= 30) {
            int x = pos().x();
            int y = pos().y();
            painter.drawRect(QRect(pos().x(), pos().y(), 25, 25));
        }
        painter.drawRect(QRect(pos().x(), pos().y(), 25, 25));
    }
private:
    Grid* grid_ = new Grid();
};


class PocketEconomic : public QMainWindow {
    Q_OBJECT

public:
    PocketEconomic(QWidget *parent = nullptr);
    ~PocketEconomic() = default;

    void MakeButtons();
    void Styling();
    void AddHouse();
    void SetBuilding(QLabel* roof, QPixmap& pix);
    void RotateBuilding(QLabel* roof);
    void SetLandsCoors();
    void PrepareBuildings();

    bool eventFilter(QObject*, QEvent* event);

    bool isBuyingProcess() const { return house1_buying_in_process; }

private:
    QWidget* window = new QWidget();
    QLabel* background_picture_ = new MyLabel();
    QPushButton* house1_btn = new QPushButton();
    QPushButton* house2_btn = new QPushButton();
    QPushButton* house3_btn = new QPushButton();
    QPushButton* shop1_btn = new QPushButton();
    QPushButton* shop2_btn = new QPushButton();
    QPushButton* info_btn = new QPushButton();

    std::vector<QLabel*> bought_objects_;
    int index_bought_buildings_ = 0;

    Grid* grid = new Grid();

    QLabel* house1_roof = new RoofLabel();
    QLabel* house2_roof = new RoofLabel();
    QLabel* house3_roof = new RoofLabel();

    bool house1_buying_in_process = false;
    bool house2_buying_in_process = false;
    bool house3_buying_in_process = false;
    bool shop1_buying_in_process = false;
    bool shop2_buying_in_process = false;

    QPixmap background_pix = QPixmap("../../../Pocket-Economic/frontend/assets/background_full_mini.png").scaled(1600, 900, Qt::KeepAspectRatio);
    QPixmap house1_btn_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house1/house1-front-red.png");
    QPixmap house2_btn_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house2/house2-front-red.png");
    QPixmap house1_roof_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house1/house1-top-red.png").scaled(25, 25, Qt::KeepAspectRatio);
    QPixmap house2_roof_pix = QPixmap(QPixmap("../../../Pocket-Economic/frontend/assets/house2/house2-top-red.png").scaled(35, 35, Qt::KeepAspectRatio)).transformed(QTransform().rotate(180)); //////////////////////
    QPixmap house3_roof_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house3/house3-top-red.png").scaled(40, 40, Qt::KeepAspectRatio); ////////////////////////

    double scale_x = 1600, scale_y = 900;

};
