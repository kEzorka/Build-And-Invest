﻿#include "../includes/main_window.h"
#include <QDebug>
#include <iostream>


PocketEconomic::PocketEconomic(QWidget* parent) : QMainWindow(parent) {
    window->setWindowTitle("PocketEconomic");
    window->resize(1535, 793);

    window->installEventFilter(this);
    background_picture_->setMouseTracking(true);

    AddHouse();
    MakeButtons();
    Styling();
    SetLandsCoors();
    PrepareBuildings();
    OfferIsShown();

    window->showFullScreen();
}

void PocketEconomic::MakeButtons() {
    window->setMouseTracking(true);

    background_picture_->setGeometry(0, -50, fullscreen_width, fullscreen_height);
    background_picture_->setParent(window);
    background_picture_->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    background_picture_->setPixmap(background_pix);
    //background_picture_->setVisible(false);

    dynamic_cast<MyLabel*>(background_picture_)->setGrid(grid);
    dynamic_cast<MyLabel*>(background_picture_)->setPlayer(player);


    player->color = player->Red;

    int button_size = (window->size().width() - 50) / 5;
    house1_btn->setGeometry(0, fullscreen_height - 50, button_size, 50);
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
    //house3_btn->setText("house 3");
    house3_btn->setIcon(house3_btn_pix);
    house3_btn->setIconSize(QSize(45, 45));

    shop1_btn->setGeometry(button_size * 3, house1_btn->pos().y(), house1_btn->size().width(), house1_btn->size().height());
    shop1_btn->setParent(window);
    //shop1_btn->setText("shop 1");
    shop1_btn->setIcon(shop1_btn_pix);
    shop1_btn->setIconSize(QSize(45, 45));

    shop2_btn->setGeometry(button_size * 4, house1_btn->pos().y(), house1_btn->size().width(), house1_btn->size().height());
    shop2_btn->setParent(window);
    //shop2_btn->setText("shop 2");
    shop2_btn->setIcon(shop2_btn_pix);
    shop2_btn->setIconSize(QSize(45, 45));

    info_btn->setGeometry(button_size * 5, house1_btn->pos().y(), 50, 50);
    info_btn->setParent(window);
    info_btn->setText("i");


    house1_roof->setGeometry(QCursor::pos().x(), QCursor::pos().y(), 25, 25);
    house1_roof->setMouseTracking(true);
    house1_roof->setVisible(false);
    house1_roof->setParent(window);
    house1_roof->setPixmap(house1_roof_pix);
    house1_roof->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    dynamic_cast<RoofLabel*>(house1_roof)->setGrid(grid);
    dynamic_cast<RoofLabel*>(house1_roof)->setPlayer(player);

    house2_roof->setGeometry(QCursor::pos().x(), QCursor::pos().y(), 50, 50);
    house2_roof->setMouseTracking(true);
    house2_roof->setVisible(false);
    house2_roof->setParent(window);
    house2_roof->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    house2_roof->setPixmap(house2_roof_pix);
    dynamic_cast<RoofLabel*>(house2_roof)->setGrid(grid);
    dynamic_cast<RoofLabel*>(house2_roof)->setPlayer(player);

    house3_roof->setGeometry(QCursor::pos().x(), QCursor::pos().y(), 50, 50);
    house3_roof->setMouseTracking(true);
    house3_roof->setVisible(false);
    house3_roof->setParent(window);
    house3_roof->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    house3_roof->setPixmap(house3_roof_pix);
    dynamic_cast<RoofLabel*>(house3_roof)->setGrid(grid);
    dynamic_cast<RoofLabel*>(house3_roof)->setPlayer(player);

    shop1_roof->setGeometry(QCursor::pos().x(), QCursor::pos().y(), 50, 50);
    shop1_roof->setMouseTracking(true);
    shop1_roof->setVisible(false);
    shop1_roof->setParent(window);
    shop1_roof->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    shop1_roof->setPixmap(shop1_roof_pix);
    dynamic_cast<RoofLabel*>(shop1_roof)->setGrid(grid);
    dynamic_cast<RoofLabel*>(shop1_roof)->setPlayer(player);

    shop2_roof->setGeometry(QCursor::pos().x(), QCursor::pos().y(), 50, 50);
    shop2_roof->setMouseTracking(true);
    shop2_roof->setVisible(false);
    shop2_roof->setParent(window);
    shop2_roof->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    shop2_roof->setPixmap(shop2_roof_pix);
    dynamic_cast<RoofLabel*>(shop2_roof)->setGrid(grid);
    dynamic_cast<RoofLabel*>(shop2_roof)->setPlayer(player);

    close_btn->setGeometry(fullscreen_width - 35, 0, 35, 35);
    close_btn->setParent(window);
    close_btn->setIcon(cross_pix);

    offer->setGeometry(100, 100, 150, 225);
    offer->setParent(window);
    offer->setVisible(false); //////////////


    main_layout->setAlignment(Qt::AlignHCenter);
    horizontal->setAlignment(Qt::AlignRight | Qt::AlignTop);
    //horizontal;
    vertical->setAlignment(Qt::AlignCenter);
    main_layout->addLayout(horizontal);
    main_layout->addLayout(vertical);
    
    offer->setLayout(main_layout);

    //close_offer_btn->setGeometry(offer->size().width() - 22, 2, 20, 20);
    close_offer_btn->setParent(offer);
    close_offer_btn->setIcon(QPixmap(cross_pix).scaled(12, 12, Qt::KeepAspectRatio));
    close_offer_btn->setFixedSize(20, 20);
    horizontal->addWidget(close_offer_btn);

    offer_pic->setParent(offer);
    offer_pic->setFixedSize(130, 100);
    //offer_pic->setGeometry(20, 20, 130, 100);
    offer_pic->setAlignment(Qt::AlignBottom | Qt::AlignHCenter);
    offer_pic->setPixmap(land_pix);

    buy_offer_btn->setParent(offer);
    //buy_offer_btn->setGeometry(35, 175, 90, 15);
    buy_offer_btn->setText("Buy");

    offer_txt->setAlignment(Qt::AlignCenter);

    vertical->addWidget(offer_txt);
    vertical->addWidget(offer_pic);
    vertical->addWidget(buy_offer_btn);
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
    QString button =
        "QPushButton {"
        "  border: 0px;"
        "  font-size: 16px;"
        "  background-color: #4fb6ff;"
        "  border-width: 1px;"
        "  border-color: #ffffff;"
        "  border-style: solid;"
        "  color: black;"
        "}"
        "QPushButton:hover { "
        "  background-color: #3499e0;"
        "}"
        "QPushButton:pressed { "
        "  background-color: #1b7bbf;"
        "}";

    QString label_buying_background =
        "QPushButton {"
        "  background-color: #228B22;"
        "  border-width: 4px;"
        "  border-color: white;"
        "  border-style: solid;"
        "  border-radius: 8px;"
        "}"
        "QPushButton:hover { "
        "  background-color: #008000;"
        "}"
        "QPushButton:pressed { "
        "  background-color: #006400;"
        "}"
        "QLabel { "

    house1_btn->setStyleSheet(button);
    house2_btn->setStyleSheet(button);
    house3_btn->setStyleSheet(button);
    shop1_btn->setStyleSheet(button);
    shop2_btn->setStyleSheet(button);
    info_btn->setStyleSheet(button);
    offer->setStyleSheet(label_buying_background);
    offer_pic->setStyleSheet(label_buying);
    offer_txt->setStyleSheet(label_buying);
    close_btn->setStyleSheet(close_global);
    close_offer_btn->setStyleSheet(close_offer);
}

void PocketEconomic::SetLandsCoors() {
    grid->lands.resize(18 * 4);
    int delta_x = 400;
    for (int k = 0; k < 4; ++k) {
        // 1 column
        grid->lands[k * grid->lands.size() / 4] = { 101 + k * delta_x, 122, 4, 4, std::vector<std::vector<bool>>(4, std::vector<bool>(4, true)) };
        grid->lands[k * grid->lands.size() / 4 + 1] = { 101 + k * delta_x, 260, 4, 5, std::vector<std::vector<bool>>(4, std::vector<bool>(5, true)) };
        grid->lands[k * grid->lands.size() / 4 + 2] = { 101 + k * delta_x, 423, 4, 4, std::vector<std::vector<bool>>(4, std::vector<bool>(4, true)) };
        grid->lands[k * grid->lands.size() / 4 + 3] = { 101 + k * delta_x, 561, 4, 5, std::vector<std::vector<bool>>(4, std::vector<bool>(5, true)) };
        grid->lands[k * grid->lands.size() / 4 + 4] = { 101 + k * delta_x, 723, 4, 4, std::vector<std::vector<bool>>(4, std::vector<bool>(4, true)) };

        // 2 column
        grid->lands[k * grid->lands.size() / 4 + 5] = { 241 + k * delta_x, 122, 4, 4, std::vector<std::vector<bool>>(4, std::vector<bool>(4, true)) };
        grid->lands[k * grid->lands.size() / 4 + 7] = { 240 + k * delta_x, 260, k == 2 ? 3 : 8, 5, std::vector<std::vector<bool>>(k == 2 ? 3 : 8, std::vector<bool>(5, true)) };
        grid->lands[k * grid->lands.size() / 4 + 6] = { 241 + k * delta_x, 423, 4, 4, std::vector<std::vector<bool>>(4, std::vector<bool>(4, true)) };
        grid->lands[k * grid->lands.size() / 4 + 8] = { 240 + k * delta_x, 561, 8, 5, std::vector<std::vector<bool>>(8, std::vector<bool>(5, true)) };
        grid->lands[k * grid->lands.size() / 4 + 9] = { 241 + k * delta_x, 723, k == 1 ? 0 : 4, 4, std::vector<std::vector<bool>>(k == 1 ? 0 : 4, std::vector<bool>(4, true)) };

        // 2.5 column
        grid->lands[k * grid->lands.size() / 4 + 10] = { 440 + k * delta_x, 285, k == 2 ? 0 : 1, 4, std::vector<std::vector<bool>>(k == 2 ? 0 : 1, std::vector<bool>(4, true)) };
        grid->lands[k * grid->lands.size() / 4 + 11] = { 440 + k * delta_x, 586, 1, 4, std::vector<std::vector<bool>>(1, std::vector<bool>(4, true)) };

        // 2.75 column
        grid->lands[k * grid->lands.size() / 4 + 12] = { 389 + k * delta_x, 147, 1, 2, std::vector<std::vector<bool>>(1, std::vector<bool>(2, true)) };
        grid->lands[k * grid->lands.size() / 4 + 13] = { 389 + k * delta_x, 448, 1, 2, std::vector<std::vector<bool>>(1, std::vector<bool>(2, true)) };
        grid->lands[k * grid->lands.size() / 4 + 14] = { 389 + k * delta_x, 748, 1, 2, std::vector<std::vector<bool>>(1, std::vector<bool>(2, true)) };

        // 3 column
        grid->lands[k * grid->lands.size() / 4 + 15] = { 414 + k * delta_x, 122, 2, 4, std::vector<std::vector<bool>>(2, std::vector<bool>(4, true)) };
        grid->lands[k * grid->lands.size() / 4 + 16] = { 414 + k * delta_x, 423, 2, 4, std::vector<std::vector<bool>>(2, std::vector<bool>(4, true)) };
        grid->lands[k * grid->lands.size() / 4 + 17] = { 414 + k * delta_x, 723, 2, 4, std::vector<std::vector<bool>>(2, std::vector<bool>(4, true)) };
    }

    grid->resorts.resize(3);
    grid->resorts[0] = { 0, 122, 3, 4, std::vector<std::vector<bool>>(3, std::vector<bool>(4, true)) };
    grid->resorts[1] = { 240 + 2 * delta_x + 3 * grid->cell_size, 260, 5, 5, std::vector<std::vector<bool>>(5, std::vector<bool>(5, true)) };
    grid->resorts[2] = { 241 + delta_x, 723, 4, 4, std::vector<std::vector<bool>>(4, std::vector<bool>(4, true)) };
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
        shop1_roof->setVisible(shop1_buying_in_process);
        grid->isBuyingProcess = shop1_buying_in_process;
        });
    QObject::connect(shop2_btn, &QPushButton::clicked, [&]() {
        shop2_buying_in_process ^= 1;
        shop2_roof->setVisible(shop2_buying_in_process);
        grid->isBuyingProcess = shop2_buying_in_process;
        });
    QObject::connect(close_btn, &QPushButton::clicked, [&]() {
        window->close();
        });
}

void PocketEconomic::SetBuilding(QLabel* roof, QPixmap& pix) {
    if (dynamic_cast<RoofLabel*>(roof)->object_can_be_built_here) {
        int x = dynamic_cast<RoofLabel*>(roof)->chosen_x;
        int y = dynamic_cast<RoofLabel*>(roof)->chosen_y;
        bought_objects_[index_bought_buildings_]->setGeometry(x, y, roof->size().width(), roof->size().height());
        bought_objects_[index_bought_buildings_]->setAlignment(roof->alignment());
        bought_objects_[index_bought_buildings_]->setPixmap(roof->pixmap());
        bought_objects_[index_bought_buildings_]->setVisible(true);
        index_bought_buildings_++;
    }
    roof->setVisible(false);
    roof->setPixmap(pix);


    grid->isBuyingProcess = false;

    dynamic_cast<RoofLabel*>(roof)->object_can_be_built_here = false;
}

void PocketEconomic::RotateBuilding(QLabel* roof) {
    QPixmap rotated = roof->pixmap().transformed(QTransform().rotate(-90));
    roof->setGeometry(roof->pos().x(), roof->pos().y(), roof->size().height(), roof->size().width());
    roof->setPixmap(rotated);
}

bool PocketEconomic::eventFilter(QObject* target, QEvent* event)
{
    if (event->type() == QEvent::MouseMove)
    {
        QMouseEvent* mouseEvent = (QMouseEvent*)event;
        int y = std::min(mouseEvent->pos().y(), fullscreen_height - house1_btn->size().height() - 25);
        house1_roof->setGeometry(mouseEvent->pos().x(), y, 50, 50);
        house2_roof->setGeometry(mouseEvent->pos().x(), y, 50, 50);
        house3_roof->setGeometry(mouseEvent->pos().x(), y, 50, 50);
        shop1_roof->setGeometry(mouseEvent->pos().x(), y, 50, 50);
        shop2_roof->setGeometry(mouseEvent->pos().x(), y, 50, 50);
        shop1_btn->setText(QString::fromStdString(std::to_string(mouseEvent->pos().x()) + " " + std::to_string(mouseEvent->pos().y())));
        return true;
    }
    else if (event->type() == QEvent::MouseButtonPress && !is_offer_shown)
    {
        QMouseEvent* mouseEvent = (QMouseEvent*)event;
        if (mouseEvent->button() == Qt::LeftButton) {
            if (house1_buying_in_process) {
                SetBuilding(house1_roof, house1_roof_pix);
                house1_buying_in_process = false;
            }
            else if (house2_buying_in_process) {
                SetBuilding(house2_roof, house2_roof_pix);
                house2_buying_in_process = false;
            }
            else if (house3_buying_in_process) {
                SetBuilding(house3_roof, house3_roof_pix);
                house3_buying_in_process = false;
            }
            else if (shop1_buying_in_process) {
                SetBuilding(shop1_roof, shop1_roof_pix);
                shop1_buying_in_process = false;
            }
            else if (shop2_buying_in_process) {
                SetBuilding(shop2_roof, shop2_roof_pix);
                shop2_buying_in_process = false;
            }
            //shops
            else {
                BuyLandOrResort(mouseEvent->pos().x(), mouseEvent->pos().y());
            }
        }
        else {
            if (house1_buying_in_process) {
                RotateBuilding(house1_roof);
            }
            else if (house2_buying_in_process) {
                RotateBuilding(house2_roof);
            }
            else if (house3_buying_in_process) {
                RotateBuilding(house3_roof);
            }
            else if (shop1_buying_in_process) {
                RotateBuilding(shop1_roof);
            }
            else if (shop2_buying_in_process) {
                RotateBuilding(shop2_roof);
            }
        }
        return true;
    }
    return false;
};

void PocketEconomic::BuyLandOrResort(int x, int y) {
    int x_pos = x, y_pos = y;
    if (x + offer->size().width() >= fullscreen_width) x_pos -= offer->size().width();
    if (y + offer->size().height() >= fullscreen_height - house1_btn->size().height()) y_pos -= offer->size().height();
    for (int i = 0; i < grid->lands.size(); ++i) {
        Grid::land_struct* land = &grid->lands[i];
        if (land->x < x && x < land->x + land->amount_x * grid->cell_size &&
            land->y < y && y < land->y + land->amount_y * grid->cell_size) {
            if (land->owner.color == player->Nobody) {
                offer_pic->setPixmap(land_pix);
                offer_txt->setText("Buy a land!");
                offer->setVisible(true);
                is_offer_shown = true;
                if (land->amount_x == 8) {
                    grid->chosen_land = { land, &grid->lands[i + 3] };
                }
                else if (land->amount_x == 1) {
                    grid->chosen_land = { land, &grid->lands[i - 3] };
                }
                else {
                    grid->chosen_land = { land, nullptr };
                }
                offer->setGeometry(x_pos, y_pos, offer->size().width(), offer->size().height());
                update();
                OfferIsShown();
                return;
            }
        }
    }
    for (Grid::land_struct& resort : grid->resorts) {
        if (resort.x < x && x < resort.x + resort.amount_x * grid->cell_size &&
            resort.y < y && y < resort.y + resort.amount_y * grid->cell_size) {
            if (resort.owner.color == player->Nobody) {
                offer_pic->setPixmap(resort_pix);
                offer_txt->setText("Buy a resort!");
                offer->setVisible(true);
                is_offer_shown = true;

                grid->chosen_land = { &resort, nullptr };
                offer->setGeometry(x_pos, y_pos, offer->size().width(), offer->size().height());
                update();
                OfferIsShown();
                return;
            }
        }
    }
}

void PocketEconomic::OfferIsShown() {
    if (offer->isVisible()) {
        QObject::connect(close_offer_btn, &QPushButton::clicked, [&]() {
            offer->setVisible(false);
            //shop2_btn->setText("closed");
            is_offer_shown = false;
            update();
            return;
            });
        QObject::connect(buy_offer_btn, &QPushButton::clicked, [&]() {
            offer->setVisible(false);
            is_offer_shown = false;
            (grid->chosen_land.first)->owner = *player;
            if (grid->chosen_land.second) (grid->chosen_land.second)->owner = *player;
            //shop2_btn->setText("closed");
            update();
            return;
            });
    }
}
