#pragma once

#include "qt_headers.h"


class Grid {
public:
    struct Land {
        int x;
        int y;
        int amount_x;
        int amount_y;
        int cell_size;
    };
    std::vector<Land> lands_coors_and_amount_of_cells_;
    bool isBuyingProcess = true;
};


class MyLabel : public QLabel, public Grid { // THIS??????????????????????
protected:
    virtual void paintEvent(QPaintEvent* e) {
        QLabel::paintEvent(e);

        if (isBuyingProcess) {
            QPainter painter(this);
            painter.setRenderHint(QPainter::Antialiasing, true);
            painter.setBrush(QBrush(QColor(255, 255, 255, 50)));
            painter.setPen(QPen(QColor(255, 255, 255, 150), 1));
            for (Land& land : lands_coors_and_amount_of_cells_) { /// *
                for (int y = land.y; y <= land.y + land.amount_y * land.cell_size; y += land.cell_size) {
                    for (int x = land.x; x <= land.x + land.amount_x * land.cell_size; x += land.cell_size) {
                        painter.drawRect(QRect(x, y, land.cell_size, land.cell_size));
                    }
                }
            }
           
            for (int y = 260; y < 260 + 5 * 25; y += 25) {
                for (int x = 240; x < 240 + 8 * 25; x += 25) {
                    painter.drawRect(QRect(x, y, 25, 25));
                }
            }
        }
    }
};

class RoofLabel :public QLabel {
protected:
    virtual void paintEvent(QPaintEvent* e) {
        QLabel::paintEvent(e);
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);
        if (101 <= pos().x() && pos().x() <= 201 && 122 <= pos().y() && pos().y() <= 222) {
            painter.setPen(QPen(QColor(0, 255, 0, 150), 2));
        }
        else {
            painter.setPen(QPen(QColor(255, 0, 0, 150), 2));
        }
        painter.drawRect(QRect(pos().x() - 5 , pos().y() - 5, size().width() + 10, size().height() + 10));
    }
};


class PocketEconomic : public QMainWindow, public Grid {
    Q_OBJECT

public:
    PocketEconomic(QWidget* parent = nullptr);
    ~PocketEconomic() = default;

    void MakeButtons();
    void Styling();
    void AddHouse();
    void SetBuilding(QLabel* roof, QPixmap& pix);
    void RotateBuilding(QLabel* roof);
    void SetLandsCoors();

    bool eventFilter(QObject*, QEvent* event);

    bool isBuyingProcess() { return house1_buying_in_process; }

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
    QLabel* add = new QLabel();


    QLabel* house1_roof = new RoofLabel();
    QLabel* house2_roof = new RoofLabel();
    QLabel* house3_roof = new RoofLabel();

    bool house1_buying_in_process = false;
    bool house2_buying_in_process = false;
    bool house3_buying_in_process = false;

    QPixmap background_pix = QPixmap("../../../Pocket-Economic/frontend/assets/background_full_mini.png").scaled(1600, 900, Qt::KeepAspectRatio);
    QPixmap house1_btn_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house1/house1-front-red.png");
    QPixmap house2_btn_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house2/house2-front-red.png");
    QPixmap house1_roof_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house1/house1-top-red.png").scaled(25, 25, Qt::KeepAspectRatio);
    QPixmap house2_roof_pix = QPixmap(QPixmap("../../../Pocket-Economic/frontend/assets/house2/house2-top-red.png").scaled(35, 35, Qt::KeepAspectRatio)).transformed(QTransform().rotate(180)); //////////////////////
    QPixmap house3_roof_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house3/house3-top-red.png").scaled(40, 40, Qt::KeepAspectRatio); ////////////////////////

    double scale_x = 1600, scale_y = 900;
};
