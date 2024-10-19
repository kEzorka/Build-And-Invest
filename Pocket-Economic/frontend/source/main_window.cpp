#include "../includes/main_window.h"
#include <QDebug>
#include <iostream>


PocketEconomic::PocketEconomic(QWidget* parent) : QMainWindow(parent) {
    window = new QWidget();
	window->setWindowTitle("21");
	window->resize(900, 100);

    window->installEventFilter(this);
    background_picture_->setMouseTracking(true);

    AddHouse();
    MakeButtons();
    Styling();
    SetLandsCoors();
    PrepareBuildings();

    window->show();
}

void PocketEconomic::MakeButtons() {
    window->setMouseTracking(true);

    background_picture_->setGeometry(0, -50, 1535, 793);
    background_picture_->setParent(window);
    background_picture_->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    background_picture_->setPixmap(background_pix);
    //background_picture_->setVisible(false);

    dynamic_cast<MyLabel*>(background_picture_)->setGrid(grid);

    int button_size = (window->size().width() - 50) / 5;
    house1_btn->setGeometry(0, window->size().height() - 50, button_size, 50);
    house1_btn->setParent(window);
    //house1_btn->setText("house 1");
    house1_btn->setIcon(house1_btn_pix);
    house1_btn->setIconSize(QSize(48, 48));

    house2_btn->setGeometry(button_size, house1_btn->pos().y(), house1_btn->size().width(), house1_btn->size().height());
    house2_btn->setParent(window);
    //house2_btn->setText("house 2");
    house2_btn->setIcon(house2_btn_pix);
    house2_btn->setIconSize(QSize(45, 45));

    house3_btn->setGeometry(button_size * 2, house1_btn->pos().y(), house1_btn->size().width(), house1_btn->size().height());
    house3_btn->setParent(window);
    house3_btn->setText("house 3");

    shop1_btn->setGeometry(button_size * 3, house1_btn->pos().y(), house1_btn->size().width(), house1_btn->size().height());
    shop1_btn->setParent(window);
    shop1_btn->setText("shop 1");

    shop2_btn->setGeometry(button_size * 4, house1_btn->pos().y(), house1_btn->size().width(), house1_btn->size().height());
    shop2_btn->setParent(window);
    shop2_btn->setText("shop 2");

    info_btn->setGeometry(button_size * 5, house1_btn->pos().y(), 50, 50);
    info_btn->setParent(window);
    info_btn->setText("i");


    house1_roof->setGeometry(QCursor::pos().x(), QCursor::pos().y(), 50, 50);
    house1_roof->setVisible(false);
    house1_roof->setParent(window);
    house1_roof->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    house1_roof->setPixmap(house1_roof_pix);
    dynamic_cast<RoofLabel*>(house1_roof)->setGrid(grid);

    house2_roof->setGeometry(QCursor::pos().x(), QCursor::pos().y(), 50, 50);
    house2_roof->setVisible(false);
    house2_roof->setParent(window);
    house2_roof->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    house2_roof->setPixmap(house2_roof_pix);
    dynamic_cast<RoofLabel*>(house2_roof)->setGrid(grid);

    house3_roof->setGeometry(QCursor::pos().x(), QCursor::pos().y(), 50, 50);
    house3_roof->setVisible(false);
    house3_roof->setParent(window);
    house3_roof->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    house3_roof->setPixmap(house3_roof_pix);
    dynamic_cast<RoofLabel*>(house3_roof)->setGrid(grid);

}

void PocketEconomic::PrepareBuildings() {
    int cnt = 0;
    for (Grid::land_struct land : grid->lands) {
        cnt += land.amount_x * land.amount_y;
    }
    bought_objects_.resize(cnt);
    for (auto& el : bought_objects_) {
        el = new QLabel(window);
        el->setVisible(false);
    }
}

void PocketEconomic::Styling() {
    QString styler =
        "QPushButton {"
        "  border: 0px;"
        "  font-size: 16px;"
        "  background-color: #F5E2D8;"
        "  border-width: 4px;"
        "  border-color: #CE8468;"
        "  border-style: solid;"
        "  border-radius: 7px;"
        "}";

    house1_btn->setStyleSheet(styler);
    house2_btn->setStyleSheet(styler);
    house3_btn->setStyleSheet(styler);
    shop1_btn->setStyleSheet(styler);
    shop2_btn->setStyleSheet(styler);
    info_btn->setStyleSheet(styler);
}

void PocketEconomic::SetLandsCoors() {
    grid->lands.resize(12 * 4);
    int delta_x = 400;
    for (int k = 0; k < 4; ++k) {
        // 1 column
        grid->lands[k * 12] = { 101 + k * delta_x, 122, 4, 4 };
        grid->lands[k * 12 + 1] = { 101 + k * delta_x, 260, 4, 5 };
        grid->lands[k * 12 + 2] = { 101 + k * delta_x, 423, 4, 4 };
        grid->lands[k * 12 + 3] = { 101 + k * delta_x, 561, 4, 5 };

        // 2 column
        grid->lands[k * 12 + 4] = { 241 + k * delta_x, 122, 4, 4 };
        grid->lands[k * 12 + 5] = { 240 + k * delta_x, 260, 8, 5 };
        grid->lands[k * 12 + 6] = { 241 + k * delta_x, 423, 4, 4 };
        grid->lands[k * 12 + 7] = { 240 + k * delta_x, 561, 8, 5 };

        // 2.5 column
        grid->lands[k * 12 + 8] = { 440 + k * delta_x, 285, 1, 4 };
        grid->lands[k * 12 + 9] = { 440 + k * delta_x, 586, 1, 4 };

        // 3 column
        grid->lands[k * 12 + 10] = { 391 + k * delta_x, 122, 3, 4 };
        grid->lands[k * 12 + 11] = { 391 + k * delta_x, 423, 3, 4 };
    }
}

void PocketEconomic::AddHouse() {
    QObject::connect(house1_btn, &QPushButton::clicked, [&]() {
        house1_buying_in_process ^= 1;
        house1_roof->setVisible(house1_buying_in_process);
        grid->isBuyingProcess = house1_buying_in_process;
        });
    QObject::connect(house2_btn, &QPushButton::clicked, [&]() {
        house2_buying_in_process ^= 1;
        house2_roof->setVisible(house2_buying_in_process);
        grid->isBuyingProcess = house2_buying_in_process;
        });
    QObject::connect(house3_btn, &QPushButton::clicked, [&]() {
        house3_buying_in_process ^= 1;
        house3_roof->setVisible(house3_buying_in_process);
        grid->isBuyingProcess = house3_buying_in_process;
        });
    QObject::connect(shop1_btn, &QPushButton::clicked, [&]() {
        shop1_buying_in_process ^= 1;
        //shop1_roof->setVisible(shop1_buying_in_process);
        grid->isBuyingProcess = shop1_buying_in_process;
        });
    QObject::connect(shop2_btn, &QPushButton::clicked, [&]() {
        shop2_buying_in_process ^= 1;
        //shop2_roof->setVisible(shop2_buying_in_process);
        grid->isBuyingProcess = shop2_buying_in_process;
        });
}


void PocketEconomic::SetBuilding(QLabel* roof, QPixmap& pix) {
    bought_objects_[index_bought_buildings_]->setGeometry(roof->pos().x(), roof->pos().y(), roof->size().width(), roof->size().height());
    bought_objects_[index_bought_buildings_]->setAlignment(roof->alignment());
    bought_objects_[index_bought_buildings_]->setPixmap(roof->pixmap());
    bought_objects_[index_bought_buildings_]->setVisible(true);
    index_bought_buildings_++;

    roof->setVisible(false);
    roof->setPixmap(pix);


    grid->isBuyingProcess = false;
}

void PocketEconomic::RotateBuilding(QLabel* roof) {
    QPixmap rotated = roof->pixmap().transformed(QTransform().rotate(-90));
    roof->setGeometry(roof->pos().x(), roof->pos().y(), roof->size().height(), roof->size().width());
    roof->setPixmap(rotated);
}

bool PocketEconomic::eventFilter(QObject* target, QEvent* event) {
    if (event->type() == QEvent::MouseMove) {
        QMouseEvent* mouseEvent = (QMouseEvent*)event;
        house1_roof->setGeometry(mouseEvent->pos().x(), std::min(std::max(mouseEvent->pos().y(), 0), window->size().height()), 50, 50);
        house2_roof->setGeometry(mouseEvent->pos().x(), std::min(std::max(mouseEvent->pos().y(), 0), window->size().height()), 50, 50);
        house3_roof->setGeometry(mouseEvent->pos().x(), std::min(std::max(mouseEvent->pos().y(), 0), window->size().height()), 50, 50);
        house2_btn->setText(QString::fromStdString(std::to_string(mouseEvent->pos().x()) + " " + std::to_string(mouseEvent->pos().y())));
        return true;
    } else if (event->type() == QEvent::MouseButtonPress) {
            QMouseEvent* mouseEvent = (QMouseEvent*)event;
            if (mouseEvent->button() == Qt::LeftButton) {
                if (house1_buying_in_process) {
                    SetBuilding(house1_roof, house1_roof_pix);
                    house1_buying_in_process = false;
                } else if (house2_buying_in_process) {
                    SetBuilding(house2_roof, house2_roof_pix);
                    house2_buying_in_process = false;
                } else if (house3_buying_in_process) {
                    SetBuilding(house3_roof, house3_roof_pix);
                    house3_buying_in_process = false;
                }
            } else {
                if (house1_buying_in_process) {
                    RotateBuilding(house1_roof);
                } else if (house2_buying_in_process) {
                    RotateBuilding(house2_roof);
                } else if (house3_buying_in_process) {
                    RotateBuilding(house3_roof);
                }
            }
            return true;
        } else if (event->type() == QEvent::Wheel) { // ���� �������� � ������������
            QWheelEvent* wheelEvent = (QWheelEvent*)event;
            QPoint numPixels = wheelEvent->angleDelta();
            if (numPixels.y() > 0) {
                if (scale_x < 3000 && scale_y < 1600) {
                    scale_x *= 1.1;
                    scale_y *= 1.1;
                }
            } else {
                if (scale_x > 1600 && scale_y > 900) {
                    scale_x /= 1.1;
                    scale_y /= 1.1;
                }
            }
            double x, y;
            //x = 
            house2_btn->setText(QString::fromStdString(std::to_string(scale_x) + " " + std::to_string(scale_y)));
            background_picture_->setPixmap(background_pix.scaled(scale_x, scale_y, Qt::KeepAspectRatio));
            return true;
        }
        return false;    //������� ������ ���� ���������� ������������ ��������
};

