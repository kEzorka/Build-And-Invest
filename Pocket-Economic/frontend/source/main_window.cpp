#include "../includes/main_window.h"
#include <QDebug>
#include <iostream>


PocketEconomic::PocketEconomic(QWidget* parent) : QMainWindow(parent) {
    game = new Game();
    game->start();
    InputCosts();
}

void PocketEconomic::MakeButtons() {
    window->setMouseTracking(true);

    background_picture_->setGeometry(0, -50, fullscreen_width, fullscreen_height);
    background_picture_->setParent(window);
    background_picture_->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    background_picture_->setPixmap(background_pix);

    dynamic_cast<MyLabel*>(background_picture_)->setGrid(grid);
    dynamic_cast<MyLabel*>(background_picture_)->setPlayer(player);

    int button_size = (window->size().width() - 50) / 5;
    house1_btn->setGeometry(0, fullscreen_height - 50, button_size, 50);
    house1_btn->setParent(window);
    house1_btn->setIcon(house1_front_red_pix);
    house1_btn->setIconSize(QSize(48, 48));

    house2_btn->setGeometry(button_size, house1_btn->pos().y(), house1_btn->size().width(), house1_btn->size().height());
    house2_btn->setParent(window);
    house2_btn->setIcon(house2_front_red_pix);
    house2_btn->setIconSize(QSize(45, 45));

    house3_btn->setGeometry(button_size * 2, house1_btn->pos().y(), house1_btn->size().width(), house1_btn->size().height());
    house3_btn->setParent(window);
    house3_btn->setIcon(house3_front_red_pix);
    house3_btn->setIconSize(QSize(45, 45));

    shop1_btn->setGeometry(button_size * 3, house1_btn->pos().y(), house1_btn->size().width(), house1_btn->size().height());
    shop1_btn->setParent(window);
    shop1_btn->setIcon(shop1_btn_pix);
    shop1_btn->setIconSize(QSize(45, 45));

    shop2_btn->setGeometry(button_size * 4, house1_btn->pos().y(), house1_btn->size().width(), house1_btn->size().height());
    shop2_btn->setParent(window);
    shop2_btn->setIcon(shop2_btn_pix);
    shop2_btn->setIconSize(QSize(45, 45));

    info_btn->setGeometry(button_size * 5, house1_btn->pos().y(), 50, 50);
    info_btn->setParent(window);
    info_btn->setText("i");


    house1_roof->setGeometry(QCursor::pos().x(), QCursor::pos().y(), 25, 25);
    house1_roof->setMouseTracking(true);
    house1_roof->setVisible(false);
    house1_roof->setParent(window);
    house1_roof->setPixmap(house1_roof_red_pix);
    house1_roof->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    dynamic_cast<RoofLabel*>(house1_roof)->setGrid(grid);
    dynamic_cast<RoofLabel*>(house1_roof)->setPlayer(player);

    house2_roof->setGeometry(QCursor::pos().x(), QCursor::pos().y(), 50, 50);
    house2_roof->setMouseTracking(true);
    house2_roof->setVisible(false);
    house2_roof->setParent(window);
    house2_roof->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    house2_roof->setPixmap(house2_roof_red_pix);
    dynamic_cast<RoofLabel*>(house2_roof)->setGrid(grid);
    dynamic_cast<RoofLabel*>(house2_roof)->setPlayer(player);

    house3_roof->setGeometry(QCursor::pos().x(), QCursor::pos().y(), 50, 50);
    house3_roof->setMouseTracking(true);
    house3_roof->setVisible(false);
    house3_roof->setParent(window);
    house3_roof->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    house3_roof->setPixmap(house3_roof_red_pix);
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

    close_btn->setGeometry(fullscreen_width - 47, 0, 47, 47);
    close_btn->setParent(window);
    close_btn->setIcon(cross_pix);
    close_btn->setVisible(false);

    news_btn->setParent(window);
    news_btn->setGeometry(0, 0, (fullscreen_width - 45) / 2, close_btn->size().height());
    news_btn->setText("News");
    news_btn->setVisible(false);

    players_info_btn->setParent(window);
    players_info_btn->setGeometry(news_btn->size().width(), 0, news_btn->size().width(), news_btn->size().height());
    players_info_btn->setText("Player's information");
    players_info_btn->setVisible(false);

    month->setParent(window);
    month->setText("September");
    month->setAlignment(Qt::AlignCenter);
    month->setGeometry(5, 5, 100, 25);
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
    QString menu_buttons_style =
        "QPushButton {"
        "  border: 0px;"
        "  font-size: 16px;"
        "  background-color: #4fb6ff;"
        "  border-width: 1px;"
        "  border-color: #ffffff;"
        "  border-style: solid;"
        "  color: white;"
        "}"
        "QPushButton:hover { "
        "  background-color: #3499e0;"
        "}"
        "QPushButton:pressed { "
        "  background-color: #1b7bbf;"
        "}";

    QString offer_background_style =
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
        "  border: 0px;"
        "  font-size: 16px;"
        "  background-color: #ffffff;"
        "  border-width: 1px;"
        "  border-color: #dbdbda;"
        "  border-style: solid;"
        "  border-radius: 10px;"
        "}";

    QString offer_buttons_label_style =
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
        "  border: 0px;"
        "  font-size: 16px;"
        "  background-color: #ffffff;"
        "  border-width: 1px;"
        "  border-color: white;"
        "  border-style: solid;"
        "  color: black;"
        "  border-radius: 10px;"
        "}";


    QString offer_cost_style =
        "QLabel { "
        "  border: 0px;"
        "  font-size: 10px;"
        "  background-color: #ffffff;"
        "  border-width: 1px;"
        "  border-color: white;"
        "  border-style: solid;"
        "  color: black;"
        "  border-radius: 10px;"
        "}";

    QString close_global_style =
        "QPushButton {"
        "  background-color: #4fb6ff;"
        //"  border-width: 2px;"
        "  border-width: 1px;"
        "  border-color: #ffffff;"
        "  border-style: solid;"
        //"  border-radius: 17px;"
        "  color: black;"
        "}"
        "QPushButton:hover { "
        "  background-color: #3499e0;"
        "}"
        "QPushButton:pressed { "
        "  background-color: #1b7bbf;"
        "}";

    QString close_offer_style =
        "QPushButton {"
        "  background-color: #ec1919;"
        "  border-width: 2px;"
        "  border-color: #ffffff;"
        "  border-style: solid;"
        "  border-radius: 10px;"
        "  color: black;"
        "}"
        "QPushButton:hover { "
        "  background-color: #d10b0b;"
        "}"
        "QPushButton:pressed { "
        "  background-color: #a20000;"
        "}";

    personal_info_red_border_style =
        "QLabel { "
        "  background-color: #ffffff;"
        "  border-width: 3px;"
        "  border-color: " + red_css +
        "  border-style: solid;"
        "  border-radius: 10px;"
        "}";

    personal_info_orange_border_style =
        "QLabel { "
        "  background-color: #ffffff;"
        "  border-width: 3px;"
        "  border-color: " + orange_css +
        "  border-style: solid;"
        "  border-radius: 10px;"
        "}";

    personal_info_yellow_border_style =
        "QLabel { "
        "  background-color: #ffffff;"
        "  border-width: 3px;"
        "  border-color: " + yellow_css +
        "  border-style: solid;"
        "  border-radius: 10px;"
        "}";

    personal_info_blue_border_style =
        "QLabel { "
        "  background-color: #ffffff;"
        "  border-width: 3px;"
        "  border-color: " + blue_css +
        "  border-style: solid;"
        "  border-radius: 10px;"
        "}";

    personal_info_violet_border_style =
        "QLabel { "
        "  background-color: #ffffff;"
        "  border-width: 3px;"
        "  border-color: " + violet_css +
        "  border-style: solid;"
        "  border-radius: 10px;"
        "}";


    QString personal_info_const_style =
        "QLabel { "
        "  font-size: 16px;"
        "  background-color: #ffffff;"
        "  color: black;"
        "  border-color: white;"
        "}";

    personal_info_good_value_style =
        "QLabel { "
        "  font-size: 16px;"
        "  background-color: #ffffff;"
        "  color: black;"
        "  border-color: white;"
        "}";

    personal_info_bad_value_style =
        "QLabel { "
        "  font-size: 16px;"
        "  background-color: #ffffff;"
        "  color: #d10b0b;"
        "  border-color: white;"
        "}";

    QString shopping_background_style =
        "QLabel { "
        "  font-size: 16px;"
        "  color: white;"
        "  background-color: #4fb6ff;"
        "  border-width: 2px;"
        "  border-color: white;"
        "  border-style: solid;"
        "  border-radius: 8px;"
        "}";

    shopping_style =
        "QLabel { "
        "  border: 0px;"
        "  font-size: 15px;"
        "  color: white;"
        "  background-color: #4fb6ff;"
        "}";


    QString close_shop_style =
        "QPushButton {"
        "  background-color: #4fb6ff;"
        "  border-width: 2px;"
        "  border-color: #ffffff;"
        "  border-style: solid;"
        "  border-radius: 12px;"
        "}"
        "QPushButton:hover { "
        "  background-color: #3499e0;"
        "}"
        "QPushButton:pressed { "
        "  background-color: #1b7bbf;"
        "}";


    QString news_background_style =
        "QLabel { "
        "  font-size: 16px;"
        "  color: black;"
        "  background-color: white;"
        "  border-width: 2px;"
        "  border-color: #dbdbda;"
        "  border-style: solid;"
        "  border-radius: 8px;"
        "}";

    news_txt_style =
        "QLabel { "
        //"  border-width: 1px;"
        //"  border-color: black;"
        "  font-size: 16px;"
        "  border: 0px;"
        "  color: black;"
        "}";

    QString news_table_style =
        "QTableWidget { "
        "  background-color: white;"
        "  border: 0px solid #4181C0;"
        "  color: black;"
        "  font-size: 16px;"
        "}"
        ;

    QString month_style =
        "QLabel { "
        "  font-size: 16px;"
        "  color: black;"
        "  background-color: white;"
        "  border-width: 1px;"
        "  border-color: #dbdbda;"
        "  border-style: solid;"
        //"  border-radius: 8px;"
        "}";

    house1_btn->setStyleSheet(menu_buttons_style);
    house2_btn->setStyleSheet(menu_buttons_style);
    house3_btn->setStyleSheet(menu_buttons_style);
    shop1_btn->setStyleSheet(menu_buttons_style);
    shop2_btn->setStyleSheet(menu_buttons_style);
    info_btn->setStyleSheet(menu_buttons_style);

    offer->setStyleSheet(offer_background_style);
    offer_pic->setStyleSheet(offer_buttons_label_style);
    offer_txt->setStyleSheet(offer_buttons_label_style);
    offer_cost_txt->setStyleSheet(offer_cost_style);

    close_btn->setStyleSheet(close_global_style);
    close_offer_btn->setStyleSheet(close_offer_style);

    personal_info->setStyleSheet(personal_info_red_border_style);
    capital->setStyleSheet(personal_info_const_style);
    capital_number->setStyleSheet(personal_info_good_value_style);
    income->setStyleSheet(personal_info_const_style);
    income_number->setStyleSheet(personal_info_bad_value_style);

    news_btn->setStyleSheet(menu_buttons_style);
    players_info_btn->setStyleSheet(menu_buttons_style);

    shop_name_const->setStyleSheet(" font-size: 25px; color: white; style: solid; border-width: 1px; border-style: solid; border-color: white;");
    shop_information->setStyleSheet(shopping_background_style);

    land_resort_information->setStyleSheet(offer_background_style);
    land_resort_information_txt->setStyleSheet(offer_buttons_label_style);
    land_resort_information_owner_txt->setStyleSheet(offer_buttons_label_style);
    close_land_resort_information_btn->setStyleSheet(close_offer_style);

    news->setStyleSheet(news_background_style);
    news_table->setStyleSheet(news_table_style);
    news_table->horizontalHeader()->hide();
    news_table->verticalHeader()->hide();

    players_info->setStyleSheet(news_background_style);
    /*players_nicknames_table->setStyleSheet(news_table_style);
    players_nicknames_table->horizontalHeader()->hide();
    players_nicknames_table->verticalHeader()->hide();*/

    next_step_btn->setStyleSheet(menu_buttons_style);
    month->setStyleSheet(month_style);
}

void PocketEconomic::SetLandsCoors() {
    grid->lands.resize(18ll * 4 + 5);
    int delta_x = 400;
    for (int k = 0; k < 3; ++k) {
        // 1 column
        grid->lands[k * grid->lands.size() / 4] = { 101 + k * delta_x, 122, 4, 4, std::vector<std::vector<bool>>(4, std::vector<bool>(4, true)), 0, 3 * k + 1 };
        grid->lands[k * grid->lands.size() / 4 + 1] = { 101 + k * delta_x, 260, 4, 5, std::vector<std::vector<bool>>(4, std::vector<bool>(5, true)), 1, 3 * k + 1};
        grid->lands[k * grid->lands.size() / 4 + 2] = { 101 + k * delta_x, 423, 4, 4, std::vector<std::vector<bool>>(4, std::vector<bool>(4, true)), 2, 3 * k + 1};
        grid->lands[k * grid->lands.size() / 4 + 3] = { 101 + k * delta_x, 561, 4, 5, std::vector<std::vector<bool>>(4, std::vector<bool>(5, true)), 3,  3 * k + 1};
        grid->lands[k * grid->lands.size() / 4 + 4] = { 101 + k * delta_x, 723, 4, 4, std::vector<std::vector<bool>>(4, std::vector<bool>(4, true)), 4,  3 * k + 1};

        // 2 column
        grid->lands[k * grid->lands.size() / 4 + 5] = { 241 + k * delta_x, 122, 4, 4, std::vector<std::vector<bool>>(4, std::vector<bool>(4, true)), 0, 2 + 3 * k };
        grid->lands[k * grid->lands.size() / 4 + 7] = { 240 + k * delta_x, 260, k == 2 ? 0 : 8, 5, std::vector<std::vector<bool>>(k == 2 ? 0 : 8, std::vector<bool>(5, true)), 1, 2 + 3 * k };
        grid->lands[k * grid->lands.size() / 4 + 6] = { 241 + k * delta_x, 423, 4, 4, std::vector<std::vector<bool>>(4, std::vector<bool>(4, true)), 2, 2 + 3 * k };
        grid->lands[k * grid->lands.size() / 4 + 8] = { 240 + k * delta_x, 561, 8, 5, std::vector<std::vector<bool>>(8, std::vector<bool>(5, true)), 3, 2 + 3 * k };
        grid->lands[k * grid->lands.size() / 4 + 9] = { 241 + k * delta_x, 723, k == 1 ? 0 : 4, 4, std::vector<std::vector<bool>>(k == 1 ? 0 : 4, std::vector<bool>(4, true)), 4, 2 + 3 * k };

        // 2.5 column
        grid->lands[k * grid->lands.size() / 4 + 10] = { 440 + k * delta_x, 285, k == 2 ? 0 : 1, 4, std::vector<std::vector<bool>>(k == 2 ? 0 : 1, std::vector<bool>(4, true)), 1, 2 + k * 3 };
        grid->lands[k * grid->lands.size() / 4 + 11] = { 440 + k * delta_x, 586, 1, 4, std::vector<std::vector<bool>>(1, std::vector<bool>(4, true)), 3, 2 + k * 3 };

        // 2.75 column
        grid->lands[k * grid->lands.size() / 4 + 12] = { 389 + k * delta_x, 147, 1, 2, std::vector<std::vector<bool>>(1, std::vector<bool>(2, true)), 0, 2 + k * 3 };
        grid->lands[k * grid->lands.size() / 4 + 13] = { 389 + k * delta_x, 448, 1, 2, std::vector<std::vector<bool>>(1, std::vector<bool>(2, true)), 1, 2 + k * 3 };
        grid->lands[k * grid->lands.size() / 4 + 14] = { 389 + k * delta_x, 748, 1, 2, std::vector<std::vector<bool>>(1, std::vector<bool>(2, true)), 2, 2 + k * 3 };

        // 3 column
        grid->lands[k * grid->lands.size() / 4 + 15] = { 414 + k * delta_x, 122, 2, 4, std::vector<std::vector<bool>>(2, std::vector<bool>(4, true)), 0, 2 + k * 3 };
        grid->lands[k * grid->lands.size() / 4 + 16] = { 414 + k * delta_x, 423, 2, 4, std::vector<std::vector<bool>>(2, std::vector<bool>(4, true)), 2, 2 + k * 3 };
        grid->lands[k * grid->lands.size() / 4 + 17] = { 414 + k * delta_x, 723, 2, 4, std::vector<std::vector<bool>>(2, std::vector<bool>(4, true)), 4, 2 + k * 3 };
    }

    grid->lands[3 * grid->lands.size() / 4] = { 101 + 3 * delta_x, 122, 4, 4, std::vector<std::vector<bool>>(4, std::vector<bool>(4, true)), 0, 9};
    grid->lands[3 * grid->lands.size() / 4 + 1] = { 101 + 3 * delta_x, 260, 4, 5, std::vector<std::vector<bool>>(4, std::vector<bool>(5, true)), 1, 9 };
    grid->lands[3 * grid->lands.size() / 4 + 2] = { 101 + 3 * delta_x, 423, 4, 4, std::vector<std::vector<bool>>(4, std::vector<bool>(4, true)), 2, 9 };
    grid->lands[3 * grid->lands.size() / 4 + 3] = { 101 + 3 * delta_x, 561, 4, 5, std::vector<std::vector<bool>>(4, std::vector<bool>(5, true)), 3, 9 };
    grid->lands[3 * grid->lands.size() / 4 + 4] = { 101 + 3 * delta_x, 723, 4, 4, std::vector<std::vector<bool>>(4, std::vector<bool>(4, true)), 4, 9 };



    grid->resorts.resize(3);
    grid->resorts[0] = { 0, 122, 3, 4, std::vector<std::vector<bool>>(3, std::vector<bool>(4, true)) };
    grid->resorts[1] = { 240 + 2 * delta_x + 3 * grid->cell_size, 260, 5, 5, std::vector<std::vector<bool>>(5, std::vector<bool>(5, true)) };
    grid->resorts[2] = { 241 + delta_x, 723, 4, 4, std::vector<std::vector<bool>>(4, std::vector<bool>(4, true)) };
}

void PocketEconomic::AddHouse() {
        QObject::connect(house1_btn, &QPushButton::clicked, [&]() {
            if (!game->getCurPlayer()->isBot()) {
                CloseAllInfoWindows();
                house1_buying_in_process ^= 1;
                house1_roof->setVisible(house1_buying_in_process);
                grid->isBuyingProcess = house1_buying_in_process;
                if (house1_buying_in_process) QGuiApplication::setOverrideCursor(QCursor(cursor_invisible_pix));
                else QGuiApplication::restoreOverrideCursor();
            }
            });
        QObject::connect(house2_btn, &QPushButton::clicked, [&]() {
            if (!game->getCurPlayer()->isBot()) {
                CloseAllInfoWindows();
                house2_buying_in_process ^= 1;
                house2_roof->setVisible(house2_buying_in_process);
                grid->isBuyingProcess = house2_buying_in_process;
                if (house2_buying_in_process) QGuiApplication::setOverrideCursor(QCursor(cursor_invisible_pix));
                else QGuiApplication::restoreOverrideCursor();
            }
            });
        QObject::connect(house3_btn, &QPushButton::clicked, [&]() {
            if (!game->getCurPlayer()->isBot()) {
                CloseAllInfoWindows();
                house3_buying_in_process ^= 1;
                house3_roof->setVisible(house3_buying_in_process);
                grid->isBuyingProcess = house3_buying_in_process;
                if (house3_buying_in_process) QGuiApplication::setOverrideCursor(QCursor(cursor_invisible_pix));
                else QGuiApplication::restoreOverrideCursor();
            }
            });
        QObject::connect(shop1_btn, &QPushButton::clicked, [&]() {
            if (!game->getCurPlayer()->isBot()) {
                CloseAllInfoWindows();
                shop1_buying_in_process ^= 1;
                shop1_roof->setVisible(shop1_buying_in_process);
                grid->isBuyingProcess = shop1_buying_in_process;
                if (shop1_buying_in_process) QGuiApplication::setOverrideCursor(QCursor(cursor_invisible_pix));
                else QGuiApplication::restoreOverrideCursor();
            }
            });
        QObject::connect(shop2_btn, &QPushButton::clicked, [&]() {
            if (!game->getCurPlayer()->isBot()) {
                CloseAllInfoWindows();
                shop2_buying_in_process ^= 1;
                shop2_roof->setVisible(shop2_buying_in_process);
                grid->isBuyingProcess = shop2_buying_in_process;
                if (shop2_buying_in_process) QGuiApplication::setOverrideCursor(QCursor(cursor_invisible_pix));
                else QGuiApplication::restoreOverrideCursor();
            }
            });

        QObject::connect(close_btn, &QPushButton::clicked, [&]() {
                window->close();
            });
}

void PocketEconomic::SetBuilding(QLabel* roof) {
    QPixmap pix = roof->pixmap();
    if (dynamic_cast<RoofLabel*>(roof)->object_can_be_built_here) {
        int x = dynamic_cast<RoofLabel*>(roof)->chosen_x;
        int y = dynamic_cast<RoofLabel*>(roof)->chosen_y;
        bought_objects_[index_bought_buildings_]->setGeometry(x, y, roof->size().width(), roof->size().height());
        bought_objects_[index_bought_buildings_]->setAlignment(roof->alignment());
        bought_objects_[index_bought_buildings_]->setPixmap(roof->pixmap());
        bought_objects_[index_bought_buildings_]->setVisible(true);
        bought_objects_[index_bought_buildings_]->setMouseTracking(true);
        index_bought_buildings_++;

        for (int i = 0; i < grid->lands.size(); ++i) {
            Grid::land_struct* land = &grid->lands[i];
            if (land->x <= x && x <= land->x + land->amount_x * grid->cell_size &&
                land->y <= y + 50 && y + 50 <= land->y + land->amount_y * grid->cell_size) {
                int row = land->row;
                int column = land->column + 1;
                int column_small = (x - land->x) / grid->cell_size;
                int row_small = (y + 50 - land->y) / grid->cell_size;
                if (roof == house1_roof) {
                    game->buildHouse(game->getCurPlayer(), dynamic_cast<BuildingLand*>(game->getLandsArr()[row][column]), House::HouseType::MonoliticHouse, row_small, column_small);
                }
                else if (roof == house2_roof) {
                    game->buildHouse(game->getCurPlayer(), dynamic_cast<BuildingLand*>(game->getLandsArr()[row][column]), House::HouseType::PanelHouse, row_small, column_small);
                }
                else if (roof == house3_roof) {
                    game->buildHouse(game->getCurPlayer(), dynamic_cast<BuildingLand*>(game->getLandsArr()[row][column]), House::HouseType::BrickHouse, row_small, column_small);
                }
                else if (roof == shop1_roof) {
                    game->buildSupermarket(game->getCurPlayer(), dynamic_cast<BuildingLand*>(game->getLandsArr()[row][column]), Supermarket::SupermarketType::Supermarket, row_small, column_small);
                }
                else if (roof == shop2_roof) {
                    game->buildSupermarket(game->getCurPlayer(), dynamic_cast<BuildingLand*>(game->getLandsArr()[row][column]), Supermarket::SupermarketType::Hypermarket, row_small, column_small);
                }
            }
        }
    }
    roof->setVisible(false);
    roof->setPixmap(pix);


    grid->isBuyingProcess = false;

    dynamic_cast<RoofLabel*>(roof)->object_can_be_built_here = false;

    QGuiApplication::restoreOverrideCursor();
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
        //shop1_btn->setText(QString::fromStdString(std::to_string(mouseEvent->pos().x()) + " " + std::to_string(mouseEvent->pos().y())));
        return true;
    }
    else if (event->type() == QEvent::MouseButtonPress)
    {
        CloseAllInfoWindows();
        QMouseEvent* mouseEvent = (QMouseEvent*)event;
        if (mouseEvent->button() == Qt::LeftButton) {
            if (!game->getCurPlayer()->isBot()) {
                if (house1_buying_in_process) {
                    SetBuilding(house1_roof);
                    house1_buying_in_process = false;
                }
                else if (house2_buying_in_process) {
                    SetBuilding(house2_roof);
                    house2_buying_in_process = false;
                }
                else if (house3_buying_in_process) {
                    SetBuilding(house3_roof);
                    house3_buying_in_process = false;
                }
                else if (shop1_buying_in_process) {
                    SetBuilding(shop1_roof);
                    shop1_buying_in_process = false;
                }
                else if (shop2_buying_in_process) {
                    SetBuilding(shop2_roof);
                    shop2_buying_in_process = false;
                }
                else {
                    CloseAllInfoWindows();
                    BuyLandOrResort(mouseEvent->pos().x(), mouseEvent->pos().y());
                }
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
    else if (event->type() == QEvent::KeyPress) {
        QKeyEvent* keyEvent = (QKeyEvent*)event;
        if (keyEvent->key() == Qt::Key::Key_Escape) {
            close_btn->setVisible(!close_btn->isVisible());
            news_btn->setVisible(!news_btn->isVisible());
            if (news_btn->isVisible()) {
                month->setGeometry(month->pos().x(), month->pos().y() + news_btn->size().height(), month->size().width(), month->size().height());
            }
            else {
                month->setGeometry(month->pos().x(), month->pos().y() - news_btn->size().height(), month->size().width(), month->size().height());
            }
            players_info_btn->setVisible(!players_info_btn->isVisible());
            if (close_btn->isVisible()) {
                personal_info->setGeometry(personal_info->pos().x(), personal_info->pos().y() + 50, personal_info->size().width(), personal_info->size().height());
                next_step_btn->setGeometry(personal_info->pos().x() + 10, personal_info->pos().y() + personal_info->size().height() + 5, personal_info->size().width() - 20, 25);
                shop_information->setGeometry(shop_information->pos().x(), shop_information->pos().y() + 50, shop_information->size().width(), shop_information->size().height() - 50);
            }
            else {
                personal_info->setGeometry(personal_info->pos().x(), personal_info->pos().y() - 50, personal_info->size().width(), personal_info->size().height());
                next_step_btn->setGeometry(personal_info->pos().x() + 10, personal_info->pos().y() + personal_info->size().height() + 5, personal_info->size().width() - 20, 25);
                shop_information->setGeometry(shop_information->pos().x(), shop_information->pos().y() - 50, shop_information->size().width(), shop_information->size().height() + 50);
            }
            news->setVisible(false);
            players_info->setVisible(false);
            background_picture_->setPixmap(background_pix);
        }
        return true;
    }
    return false;
};

void PocketEconomic::BuyLandOrResort(int x, int y) {
    int x_pos = x, y_pos = y;
    for (int i = 0; i < grid->lands.size(); ++i) {
        Grid::land_struct* land = &grid->lands[i];
        if (land->x < x && x < land->x + land->amount_x * grid->cell_size &&
            land->y < y + 50 && y + 50 < land->y + land->amount_y * grid->cell_size) {
            if (land->owner.color == player->Nobody) {
                offer_pic->setPixmap(land_pix);
                offer_txt->setText("Buy a land!");
                offer->setVisible(true);
                is_offer_shown = true;
                if (land->amount_x == 8) {
                    grid->chosen_land = { land, &grid->lands[i + 3] };
                }
                else if (land->amount_x == 1 && land->amount_y == 4) {
                    grid->chosen_land = { land, &grid->lands[i - 3] };
                }
                else if (land->amount_x == 2 && land->amount_y == 4) {
                    grid->chosen_land = { land, &grid->lands[i - 3] };
                }
                else if (land->amount_x == 1 && land->amount_y == 2) {
                    grid->chosen_land = { land, &grid->lands[i + 3] };
                }
                else {
                    grid->chosen_land = { land, nullptr };
                }
                if (x + offer->size().width() >= fullscreen_width) x_pos -= offer->size().width();
                if (y + offer->size().height() >= fullscreen_height - house1_btn->size().height()) y_pos -= offer->size().height();
                offer->setGeometry(x_pos, y_pos, offer->size().width(), offer->size().height());
                background_picture_->setPixmap(background_pix);
                OfferIsShown();
                return;
            } else {
                land_resort_information_txt->setText("This land belongs to");
                land_resort_information_advertising_btn->setVisible(false);
                land_resort_information_updating_resort_btn->setVisible(false);
                if (land->owner.color != player->color) {
                    land_resort_information_owner_txt->setText("someone"); // add name from backend
                }
                else {
                    land_resort_information_owner_txt->setText("you");
                }
                if (x + land_resort_information->size().width() >= fullscreen_width) x_pos -= land_resort_information->size().width();
                if (y + land_resort_information->size().height() + 75 >= fullscreen_height - house1_btn->size().height()) y_pos -= land_resort_information->size().height();
                land_resort_information->setGeometry(x_pos, y_pos, land_resort_information->size().width(), 50 + (land_resort_information_owner_txt->text() == "you" ? 75 : 0));
                land_resort_information->setVisible(true);
                if (land->owner.color == player->color) {
                    land_resort_information_advertising_btn->setParent(land_resort_information);
                    land_resort_information_advertising_btn->setVisible(true);
                    land_resort_information_advertising_btn->setText("Buy advertising!");
                    land_resort_information_advertising_btn->setGeometry((land_resort_information->size().width() - 100) / 2, land_resort_information->size().height() - 40, 100, 30);
                }

                if (land->owner.color == player->Red) land_resort_information_owner_txt->setStyleSheet("border: 0px; color: " + red_css);
                else if (land->owner.color == player->Orange) land_resort_information_owner_txt->setStyleSheet("border: 0px; color: " + orange_css);
                else if (land->owner.color == player->Yellow) land_resort_information_owner_txt->setStyleSheet("border: 0px; color: " + yellow_css);
                else if (land->owner.color == player->Blue) land_resort_information_owner_txt->setStyleSheet("border: 0px; color: " + blue_css);
                else if (land->owner.color == player->Violet) land_resort_information_owner_txt->setStyleSheet("border: 0px; color: " + violet_css);
                background_picture_->setPixmap(background_pix);
                LandAnsResortInformationIsShown();
                return;
            }
        }
    }
    for (Grid::land_struct& resort : grid->resorts) {
        if (resort.x < x && x < resort.x + resort.amount_x * grid->cell_size &&
            resort.y < y + 50 && y + 50 < resort.y + resort.amount_y * grid->cell_size) {
            if (resort.owner.color == player->Nobody) {
                if (x + offer->size().width() >= fullscreen_width) x_pos -= offer->size().width();
                if (y + offer->size().height() >= fullscreen_height - house1_btn->size().height()) y_pos -= offer->size().height();

                offer_pic->setPixmap(resort_pix);
                offer_txt->setText("Buy a resort!");
                offer->setVisible(true);
                is_offer_shown = true;

                grid->chosen_land = { &resort, nullptr };
                offer->setGeometry(x_pos, y_pos, offer->size().width(), offer->size().height());
                background_picture_->setPixmap(background_pix);
                OfferIsShown();
                return;
            }
            else {
                land_resort_information_txt->setText("This resort belongs to");
                land_resort_information_advertising_btn->setVisible(false);
                land_resort_information_updating_resort_btn->setVisible(false);
                if (resort.owner.color != player->color) {
                    land_resort_information_owner_txt->setText("someone"); // add name from backend
                    land_resort_information_advertising_btn->setVisible(false);
                    land_resort_information_updating_resort_btn->setVisible(false);
                }
                else {
                    land_resort_information_owner_txt->setText("you");
                }
                if (x + land_resort_information->size().width() >= fullscreen_width) x_pos -= land_resort_information->size().width();
                if (y + land_resort_information->size().height() + 75 >= fullscreen_height - house1_btn->size().height()) y_pos -= land_resort_information->size().height();
                land_resort_information->setGeometry(x_pos, y_pos, land_resort_information->size().width(), 50 + (land_resort_information_owner_txt->text() == "you" ? 75 : 0));
                land_resort_information->setVisible(true);
                if (resort.owner.color == player->color) {
                    land_resort_information_updating_resort_btn->setParent(land_resort_information);
                    land_resort_information_updating_resort_btn->setVisible(true);
                    land_resort_information_updating_resort_btn->setText("Update resort!");
                    land_resort_information_updating_resort_btn->setGeometry((land_resort_information->size().width() - 100) / 2, land_resort_information->size().height() - 40, 100, 30);
                }

                if (resort.owner.color == player->Red) land_resort_information_owner_txt->setStyleSheet("border: 0px; color: " + red_css);
                else if (resort.owner.color == player->Orange) land_resort_information_owner_txt->setStyleSheet("border: 0px; color: " + orange_css);
                else if (resort.owner.color == player->Yellow) land_resort_information_owner_txt->setStyleSheet("border: 0px; color: " + yellow_css);
                else if (resort.owner.color == player->Blue) land_resort_information_owner_txt->setStyleSheet("border: 0px; color: " + blue_css);
                else if (resort.owner.color == player->Violet) land_resort_information_owner_txt->setStyleSheet("border: 0px; color: " + violet_css);
                background_picture_->setPixmap(background_pix);
                LandAnsResortInformationIsShown();
                return;
            }
        }
    }
}

void PocketEconomic::PrepareOffer() {
    offer->setGeometry(100, 100, 150, 225);
    offer->setParent(window);
    offer->setVisible(false);


    main_layout_offer->setAlignment(Qt::AlignHCenter);
    horizontal_offer->setAlignment(Qt::AlignRight | Qt::AlignTop);
    vertical_offer->setAlignment(Qt::AlignCenter);
    main_layout_offer->addLayout(horizontal_offer);
    main_layout_offer->addLayout(vertical_offer);

    offer->setLayout(main_layout_offer);

    //close_offer_btn->setGeometry(offer->size().width() - 22, 2, 20, 20);
    close_offer_btn->setParent(offer);
    close_offer_btn->setIcon(QPixmap(cross_pix).scaled(12, 12, Qt::KeepAspectRatio));
    close_offer_btn->setFixedSize(20, 20);
    horizontal_offer->addWidget(close_offer_btn);

    offer_pic->setParent(offer);
    offer_pic->setFixedSize(130, 100);
    //offer_pic->setGeometry(20, 20, 130, 100);
    offer_pic->setAlignment(Qt::AlignBottom | Qt::AlignHCenter);
    offer_pic->setPixmap(land_pix);

    buy_offer_btn->setParent(offer);
    //buy_offer_btn->setGeometry(35, 175, 90, 15);
    buy_offer_btn->setText("Buy");

    offer_txt->setAlignment(Qt::AlignCenter);
    offer_cost_txt->setAlignment(Qt::AlignCenter);
    offer_cost_txt->setText("Cost: 70M");

    vertical_offer->addWidget(offer_txt);
    vertical_offer->addWidget(offer_cost_txt);
    vertical_offer->addWidget(offer_pic);
    vertical_offer->addWidget(buy_offer_btn);

}

void PocketEconomic::OfferIsShown() {
    QObject::connect(close_offer_btn, &QPushButton::clicked, [&]() {
        offer->setVisible(false);
        is_offer_shown = false;
        background_picture_->setPixmap(background_pix);
        return;
        });
    QObject::connect(buy_offer_btn, &QPushButton::clicked, [&]() {
        offer->setVisible(false);
        is_offer_shown = false;
        (grid->chosen_land.first)->owner = *player;

        // buy LandOrResort

        if (grid->chosen_land.second) (grid->chosen_land.second)->owner = *player;
        background_picture_->setPixmap(background_pix);
        return;
        });
}

void PocketEconomic::CapitalAndIncome() {
    personal_info->setGeometry(fullscreen_width - 155, 5, 150, 100);
    personal_info->setParent(window);
    personal_info->setLayout(personal_info_layout);
    personal_info_layout->addLayout(capital_layout);
    personal_info_layout->addLayout(income_layout);

    personal_info_layout->setAlignment(Qt::AlignCenter);
    capital_layout->setAlignment(Qt::AlignLeft);
    income_layout->setAlignment(Qt::AlignLeft);

    capital->setText("Capital: ");
    capital_number->setText("70M");
    capital_layout->addWidget(capital);
    capital_layout->addWidget(capital_number);

    income->setText("Income: ");
    income_number->setText("-30M");
    income_layout->addWidget(income);
    income_layout->addWidget(income_number);


    next_step_btn->setParent(window);
    next_step_btn->setText("Next step");
    next_step_btn->setGeometry(personal_info->pos().x() + 10, personal_info->pos().y() + personal_info->size().height() + 5, personal_info->size().width() - 20, 25);
}

void PocketEconomic::CreateShop() {
    shop_information->setVisible(false);
    shop_information->setParent(window);
    shop_information->setGeometry(fullscreen_width - 305, personal_info->pos().y() - 5, 300, 750);
    shop_information->setLayout(shop_main_layout);

    shop_name_const->setText("SHOP");
    shop_name_layout->addWidget(shop_name_const);
    shop_name_layout->setAlignment(Qt::AlignCenter);
    shop_main_layout->addLayout(shop_name_layout);


    for (int i = 0; i < 5; ++i) {
        shop_buidings_pictures[i] = new QLabel(news);
        shop_buidings_layouts[i] = new QHBoxLayout();
        shop_buidings_info_layouts[i] = new QVBoxLayout();
        shop_buidings_pictures[i]->setStyleSheet(shopping_style);
        shop_building_infos[i].resize(4);
        shop_buidings_pictures[i]->setFixedSize(100, 100);
        shop_buidings_pictures[i]->setAlignment(Qt::AlignCenter);
        shop_buidings_layouts[i]->addWidget(shop_buidings_pictures[i]);
        shop_buidings_layouts[i]->addLayout(shop_buidings_info_layouts[i]);
        shop_buidings_info_layouts[i]->setAlignment(Qt::AlignVCenter);
        for (int j = 0; j < 4; ++j) {
            shop_building_infos[i][j] = new QLabel();
            shop_building_infos[i][j]->setStyleSheet(shopping_style);
        }
        shop_buidings_info_layouts[i]->addWidget(shop_building_infos[i][0]);
        shop_buidings_info_layouts[i]->addWidget(shop_building_infos[i][1]);
        shop_buidings_info_layouts[i]->addWidget(shop_building_infos[i][2]);
        shop_buidings_info_layouts[i]->addWidget(shop_building_infos[i][3]);
        shop_main_layout->addLayout(shop_buidings_layouts[i]);
    }
    shop_buidings_pictures[0]->setPixmap(house1_front_red_pix.scaled(100, 100, Qt::KeepAspectRatio));
    shop_building_infos[0][0]->setText("House 1");
    shop_building_infos[0][1]->setText("Income: +800K");
    shop_building_infos[0][2]->setText("Cost: 5M");
    shop_building_infos[0][3]->setText("Building: 3 months");

    shop_buidings_pictures[1]->setPixmap(house2_front_red_pix.scaled(80, 80, Qt::KeepAspectRatio));
    shop_building_infos[1][0]->setText("House 2");
    shop_building_infos[1][1]->setText("Income: +500K");
    shop_building_infos[1][2]->setText("Cost: 2M");
    shop_building_infos[1][3]->setText("Building: 2 months");

    shop_buidings_pictures[2]->setPixmap(house3_front_red_pix.scaled(75, 75, Qt::KeepAspectRatio));
    shop_building_infos[2][0]->setText("House 3");
    shop_building_infos[2][1]->setText("Income: +350K");
    shop_building_infos[2][2]->setText("Cost: 1M");
    shop_building_infos[2][3]->setText("Building: 1 month");

    shop_buidings_pictures[3]->setPixmap(shop1_btn_pix.scaled(75, 75, Qt::KeepAspectRatio));
    shop_building_infos[3][0]->setText("Supermarket 1");
    shop_building_infos[3][1]->setText("Income: +200K");
    shop_building_infos[3][2]->setText("Cost: 10M");
    shop_building_infos[3][3]->setText("Building: 6 months");

    shop_buidings_pictures[4]->setPixmap(shop2_btn_pix.scaled(50, 50, Qt::KeepAspectRatio));
    shop_building_infos[4][0]->setText("Supermarket 2");
    shop_building_infos[4][1]->setText("Income: +100K");
    shop_building_infos[4][2]->setText("Cost: 5M");
    shop_building_infos[4][3]->setText("Building: 3 months");
}

void PocketEconomic::ShopIsShown() {
    QObject::connect(info_btn, &QPushButton::clicked, [&]() {
        if (!shop_information->isVisible()) {
            personal_info->setGeometry(personal_info->pos().x() - shop_information->size().width() - 5, personal_info->pos().y(), personal_info->size().width(), personal_info->size().height());
            next_step_btn->setGeometry(personal_info->pos().x() + 10, personal_info->pos().y() + personal_info->size().height() + 5, personal_info->size().width() - 20, 25);
            shop_information->setVisible(true);
            int x_pos = fullscreen_width - 305, y_pos = personal_info->pos().y();
            int x_size, y_size;
            if (players_info_btn->isVisible()) {
                x_size = 300;
                y_size = 750;
            }
            else {
                x_size = 300;
                y_size = 750 + players_info_btn->size().height();
            }
            shop_information->setGeometry(x_pos, y_pos, x_size, y_size);
        }
        else {
            shop_information->setVisible(false);
            personal_info->setGeometry(personal_info->pos().x() + shop_information->size().width() + 5, personal_info->pos().y(), personal_info->size().width(), personal_info->size().height());
            next_step_btn->setGeometry(personal_info->pos().x() + 10, personal_info->pos().y() + personal_info->size().height() + 5, personal_info->size().width() - 20, 25);
        }
        news->setVisible(false);
        players_info->setVisible(false);
        offer->setVisible(false);
        land_resort_information->setVisible(false);

        background_picture_->setPixmap(background_pix);
        });
    /*qobject::connect(close_shop_btn, &qpushbutton::clicked, [&]() {
        shop_information->setvisible(false);
        personal_info->setgeometry(personal_info->pos().x() + shop_information->size().width() + 5, personal_info->pos().y(), personal_info->size().width(), personal_info->size().height());
        background_picture_->setpixmap(background_pix);
        });*/
}

void PocketEconomic::PrepareLandAnsResortInformation() {
    land_resort_information->setGeometry(100, 100, 250, 50);
    land_resort_information->setParent(window);
    land_resort_information->setVisible(false);

    QHBoxLayout* tmp = new QHBoxLayout();
    tmp->addWidget(land_resort_information_txt);
    tmp->addWidget(land_resort_information_owner_txt);
    tmp->setAlignment(Qt::AlignLeft);

    land_resort_information->setLayout(tmp);
    land_resort_information_txt->setText("This land belongs to");
    land_resort_information_owner_txt->setText("you");

    close_land_resort_information_btn->setGeometry(land_resort_information->size().width() - 22, 2, 20, 20);
    close_land_resort_information_btn->setParent(land_resort_information);
    close_land_resort_information_btn->setIcon(QPixmap(cross_pix).scaled(12, 12, Qt::KeepAspectRatio));
}

void PocketEconomic::LandAnsResortInformationIsShown() {
    QObject::connect(close_land_resort_information_btn, &QPushButton::clicked, [&]() {
        land_resort_information->setVisible(false);
        background_picture_->setPixmap(background_pix);
        return;
        });
    QObject::connect(land_resort_information_advertising_btn, &QPushButton::clicked, [&]() {
        land_resort_information->setVisible(false);
        background_picture_->setPixmap(background_pix);
        return;
        });
    QObject::connect(land_resort_information_updating_resort_btn, &QPushButton::clicked, [&]() {
        land_resort_information->setVisible(false);
        background_picture_->setPixmap(background_pix);
        return;
        });
}

void PocketEconomic::MakeNews() {
    tmp_news.resize(30);
    for (int i = 0; i < tmp_news.size(); ++i) {
        int col = rand() % 6;
        tmp_news[i].first += "       ";
        if (col == player->Red) {
            tmp_news[i].first += "Red:";
        }
        else if (col == player->Orange) {
            tmp_news[i].first += "Orange:";
        }
        else if (col == player->Yellow) {
            tmp_news[i].first += "Yellow:";
        }
        else if (col == player->Blue) {
            tmp_news[i].first += "Blue:";
        }
        else if (col == player->Violet) {
            tmp_news[i].first += "Violet:";
        }
        tmp_news[i].first += "       ";
    }
    tmp_news[0].second = "is delayed due to adverse weather conditions, the builders refused to go on shift.";
    tmp_news[1].second = "is delayed: a virus attacked the construction crew.";
    tmp_news[2].second = "is delayed: the construction crew cannot manage their own time.";
    tmp_news[3].second = "is delayed: there were difficulties in connecting the object to communications: no electricity.";
    tmp_news[4].second = "is delayed: there were difficulties in connecting the object to communications: no water.";
    tmp_news[5].second = "is delayed: the state commission does not accept the object.";
    tmp_news[6].second = "is delayed: defects caused by the works of the general contractor were found.";
    tmp_news[7].second = "is delayed: defects caused by poor-quality materials were found.";
    tmp_news[8].second = "is delayed: defects caused by non-compliance with construction technology were found.";
    tmp_news[9].second = "is delayed: there were problems with documentation.";
    tmp_news[10].second = "is delayed: the designer did not draw a complex node of the frame structure. It is necessary to correct the drawings.";
    tmp_news[11].second = "is delayed: the designer did not specify the dimensions of the parts in the drawings. It is necessary to send the diagrams for revision.";
    tmp_news[12].second = "is delayed: the hired universal builders refused to carry out the finishing. The customer is looking for a specialized team.";
    tmp_news[13].second = "is delayed: documents for the commissioning of housing have not been agreed with the utilities.";
    tmp_news[14].second = "is delayed due to insufficient qualifications of workers and engineering staff.";
    tmp_news[15].second = "is delayed due to the introduction of new legislative norms and rules in the design process.";
    tmp_news[16].second = "is delayed: it became necessary to obtain additional approvals for the project with environmental services.";
    tmp_news[17].second = "is delayed due to the discovery of archaeological finds on the site.";
    tmp_news[18].second = "is delayed due to legal proceedings on land issues.";
    tmp_news[19].second = "is delayed: it became necessary to conduct additional material tests.";
    tmp_news[20].second = "is delayed: the designer did not draw a complex node of the frame structure. It is necessary to correct the drawings.";
    tmp_news[21].second = "is delayed: the designer did not specify the dimensions of the parts in the drawings. It is necessary to send the diagrams for revision.";
    tmp_news[22].second = "is delayed: the hired universal builders refused to carry out the finishing. The customer is looking for a specialized team.";
    tmp_news[23].second = "is delayed: documents for the commissioning of housing have not been agreed with the utilities.";
    tmp_news[24].second = "is delayed due to insufficient qualifications of workers and engineering staff.";
    tmp_news[25].second = "is delayed due to the introduction of new legislative norms and rules in the design process.";
    tmp_news[26].second = "is delayed: it became necessary to obtain additional approvals for the project with environmental services.";
    tmp_news[27].second = "is delayed due to the discovery of archaeological finds on the site.";
    tmp_news[28].second = "is delayed due to legal proceedings on land issues.";
    tmp_news[29].second = "is delayed: it became necessary to conduct additional material tests.";
}

void PocketEconomic::PrepareNews() {
    news->setParent(window);
    news->setVisible(false);
    news->setGeometry(0, news_btn->size().height() + 15, news_btn->size().width(), fullscreen_height - news_btn->size().height() - house1_btn->size().height() - 30);
    news->setLayout(news_layout);
    news_layout->addWidget(news_table);
    news_layout->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    news_table->setFixedSize(news->size().width() - 25, news->size().height() - 50);
    news_table->setShowGrid(false);
    news_table->setRowCount(0);
    news_table->setColumnCount(2);
    news_table->setColumnWidth(0, 250);
    news_table->setColumnWidth(1, 1000);
    news_table->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    news_table->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
    news_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    news_table->setSelectionMode(QAbstractItemView::NoSelection);

    MakeNews();

    for (auto& el : tmp_news) {
        int row = news_table->rowCount();
        news_table->insertRow(row);
        news_table->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(el.first)));
        news_table->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(el.second)));
    }

    // add months
    tmp_news[5] = { "May", "" };
    tmp_news[10] = { "June", "" };
    //merge cells for months
    news_table->setSpan(5, 0, 1, 2);
    news_table->item(5, 0)->setBackground(QColor(0, 0, 0, 25));
    news_table->setSpan(10, 0, 1, 2);
    news_table->item(10, 0)->setBackground(QColor(0, 0, 0, 25));

    for (int i = 0; i < news_table->rowCount(); ++i) {
        QTableWidgetItem* cur = news_table->item(i, 0);
        std::string color = (cur->text()).toStdString();
        if (color.find("Red") != std::string::npos) cur->setForeground(red_color);
        else if (color.find("Orange") != std::string::npos) cur->setForeground(orange_color);
        else if (color.find("Yellow") != std::string::npos) cur->setForeground(yellow_color);
        else if (color.find("Blue") != std::string::npos) cur->setForeground(blue_color);
        else if (color.find("Violet") != std::string::npos) cur->setForeground(violet_color);
    }
}

void PocketEconomic::NewsIsShown() {
    QObject::connect(news_btn, &QPushButton::clicked, [&]() {
        news->setVisible(!news->isVisible());
        news_table->scrollToBottom();
        news_table->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
        if (news_table->rowCount()) news_table->scrollToItem(news_table->item(news_table->rowCount() - 1, 0));
        if (shop_information->isVisible()) {
            shop_information->setVisible(false);
            personal_info->setGeometry(personal_info->pos().x() + shop_information->size().width() + 5, personal_info->pos().y(), personal_info->size().width(), personal_info->size().height());
            next_step_btn->setGeometry(personal_info->pos().x() + 10, personal_info->pos().y() + personal_info->size().height() + 5, personal_info->size().width() - 20, 25);
        }
        players_info->setVisible(false);
        offer->setVisible(false);
        land_resort_information->setVisible(false);
        background_picture_->setPixmap(background_pix);
        return;
        });
}

void PocketEconomic::PreparePlayersInfo() {
    players_info->setParent(window);
    players_info->setVisible(false);
    players_info->setGeometry(players_info_btn->pos().x(), news->pos().y(), fullscreen_width - players_info_btn->pos().x() - personal_info->size().width() - 25, news->size().height());
    players_info->setLayout(players_info_layout);
    players_info_layout->setAlignment(Qt::AlignCenter);
    QLabel* left_part = new QLabel();
    players_info_layout->addWidget(left_part);
    //players_info_layout->addWidget(right_part);

    left_part->setFixedSize(players_info->size().width() / 2 - 100, players_info->size().height() - 20);
    left_part->setLayout(players_info_vertical_layout);
    left_part->setAlignment(Qt::AlignCenter);
    left_part->setStyleSheet("background-color: white; border-width: 1px;");
    for (int i = 0; i < 5; ++i) {
        QHBoxLayout* layout = new QHBoxLayout();
        players_info_vertical_layout->addLayout(layout);
        /*players_info_icons[i] = new QLabel();
        players_info_icons[i]->setPixmap(players_info_profile_icon);
        players_info_icons[i]->setStyleSheet("background-color: red;");
        players_info_icons[i]->setAlignment(Qt::AlignCenter);
        players_info_icons[i]->setFixedSize(75, 75);*/

        players_info_icons[i] = new QPushButton();
        players_info_icons[i]->setIcon(players_info_profile_icon);
        players_info_icons[i]->setIconSize(QSize(70, 70));
        players_info_icons[i]->setStyleSheet("background-color: " + red_css);
        players_info_icons[i]->setFixedSize(75, 75);

        layout->addWidget(players_info_icons[i]);
        layout->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

        QVBoxLayout* info = new QVBoxLayout();
        info->setAlignment(Qt::AlignCenter);
        layout->addLayout(info);
        QLabel* player = new QLabel(QString::fromStdString("Player " + std::to_string(i + 1)));
        player->setStyleSheet(news_txt_style);
        info->addWidget(player);
        QLabel* nickname = new QLabel("Nickname");
        nickname->setStyleSheet(news_txt_style);
        info->addWidget(nickname);
    }

    players_info_place_for_profile->setFixedSize(players_info->size().width() - left_part->size().width() - 30, left_part->size().height());
    //right_part->setLayout(players_info_vertical_layout);
    players_info_place_for_profile->setAlignment(Qt::AlignCenter);
    players_info_place_for_profile->setStyleSheet("background-color: white; border-width: 1px;");
    players_info_layout->addWidget(players_info_place_for_profile);

    MakeProfile(red_profile);
    MakeProfile(blue_profile);
    MakeProfile(orange_profile);
    MakeProfile(yellow_profile);
    MakeProfile(violet_profile);

    players_info_icons[0]->setStyleSheet("background-color: " + red_css);
    players_info_icons[1]->setStyleSheet("background-color: " + orange_css);
    players_info_icons[2]->setStyleSheet("background-color: " + (player->availiable[2] ? yellow_css : grey_css));
    players_info_icons[3]->setStyleSheet("background-color: " + (player->availiable[3] ? blue_css : grey_css));
    players_info_icons[4]->setStyleSheet("background-color: " + (player->availiable[4] ? violet_css : grey_css));


    players_info_place_for_profile->setLayout(red_profile->layout());
}

void PocketEconomic::MakeProfile(QLabel* profile) {
    //delete players_info_place_for_profile->layout();
    bool need_to_change = false;
    if (profile == red_profile && player->availiable[0]) need_to_change = true;
    else if (profile == orange_profile && player->availiable[1]) need_to_change = true;
    else if (profile == yellow_profile && player->availiable[2]) need_to_change = true;
    else if (profile == blue_profile && player->availiable[3]) need_to_change = true;
    else if (profile == violet_profile && player->availiable[4]) need_to_change = true;
    if (need_to_change) {
        if (players_info_place_for_profile->layout()) {
            for (int i = 0; i < players_info_place_for_profile->layout()->count(); ++i)
            {
                delete players_info_place_for_profile->layout()->takeAt(i);
            }
        }
        else {
            players_info_place_for_profile->setLayout(new QHBoxLayout());
        }
        QColor color(0, 0, 0);
        if (profile == red_profile) color = red_color;
        else if (profile == orange_profile) color = orange_color;
        else if (profile == yellow_profile) color = yellow_color;
        else if (profile == blue_profile) color = blue_color;
        else if (profile == violet_profile) color = violet_color;
        std::vector<int> info_tmp = { 1, 1, 1, 5, 1 };
        QLayout* layout = players_info_place_for_profile->layout();
        profile->setStyleSheet("background-color: white; border-width: 1px;");
        profile->setLayout(layout);
        profile->setFixedSize(players_info->size().width() - 208 - 30, 717);
        profile->setAlignment(Qt::AlignCenter);
        profile->setStyleSheet("background-color: white; border-width: 1px;");

        QTableWidget* table = new QTableWidget();
        layout->addWidget(table);
        table->setRowCount(25);
        table->setColumnCount(2);
        table->setColumnWidth(1, 500);
        table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        table->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        table->setStyleSheet("color: black;");
        table->setIconSize(QSize(75, 75));
        table->row(0);
        table->setShowGrid(false);
        table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table->setSelectionMode(QAbstractItemView::NoSelection);
        table->horizontalHeader()->hide();
        table->verticalHeader()->hide();

        QString income = "Income: ", capital = "Capital: ";
        capital += QString::fromStdString("70M");
        income += QString::fromStdString("-30M");

        table->setSpan(0, 0, 2, 2);
        table->setItem(0, 0, new QTableWidgetItem(capital));
        table->setSpan(2, 0, 2, 2);
        table->setItem(2, 0, new QTableWidgetItem(income));
        QFont font = table->item(0, 0)->font();
        font.setPixelSize(20);
        table->item(0, 0)->setFont(font);
        table->item(2, 0)->setFont(font);

        table->setSpan(4, 0, 1, 2);
        table->setItem(4, 0, new QTableWidgetItem());
        table->setSpan(5, 0, 1, 2);
        table->setItem(5, 0, new QTableWidgetItem("Houses                                                                                                          "));
        table->item(5, 0)->setBackground(color);
        table->item(5, 0)->setForeground(QColor(255, 255, 255));
        int row = 6;
        for (int i = 0; i < 3; ++i) {
            if (info_tmp[i]) {
                table->setItem(row, 1, new QTableWidgetItem(QString::fromStdString("House " + std::to_string(i + 1))));
                QString income_house = "Income: ";
                income_house += "+50M";
                table->setItem(row + 1, 1, new QTableWidgetItem(income_house));
                QString amount_house = "Amount: ";
                amount_house += std::to_string(info_tmp[i]);
                table->setItem(row + 2, 1, new QTableWidgetItem(amount_house));
                table->setSpan(row, 0, 3, 1);
                QIcon icon;
                if (i == 0) {
                    if (profile == red_profile) icon = QIcon(house1_front_red_pix);
                    else if (profile == orange_profile) icon = QIcon(house1_front_orange_pix);
                    else if (profile == yellow_profile) icon = QIcon(house1_front_yellow_pix);
                    else if (profile == blue_profile) icon = QIcon(house1_front_blue_pix);
                    else if (profile == violet_profile) icon = QIcon(house1_front_violet_pix);
                }
                else if (i == 1) {
                    if (profile == red_profile) icon = QIcon(house2_front_red_pix);
                    else if (profile == orange_profile) icon = QIcon(house2_front_orange_pix);
                    else if (profile == yellow_profile) icon = QIcon(house2_front_yellow_pix);
                    else if (profile == blue_profile) icon = QIcon(house2_front_blue_pix);
                    else if (profile == violet_profile) icon = QIcon(house2_front_violet_pix);
                }
                else {
                    if (profile == red_profile) icon = QIcon(house3_front_red_pix);
                    else if (profile == orange_profile) icon = QIcon(house3_front_orange_pix);
                    else if (profile == yellow_profile) icon = QIcon(house3_front_yellow_pix);
                    else if (profile == blue_profile) icon = QIcon(house3_front_blue_pix);
                    else if (profile == violet_profile) icon = QIcon(house3_front_violet_pix);
                }
                table->setItem(row, 0, new QTableWidgetItem(icon, ""));

                table->setItem(row + 3, 0, new QTableWidgetItem());
                table->setSpan(row + 3, 0, 1, 2);
                row += 4;

            }
        }
        table->setSpan(row - 1, 0, 1, 2);
        table->setItem(row - 1, 0, new QTableWidgetItem());
        table->setSpan(row, 0, 1, 2);
        table->setItem(row, 0, new QTableWidgetItem("Supermarkets                                                                                                          "));
        table->item(row, 0)->setBackground(color);
        table->item(row, 0)->setForeground(QColor(255, 255, 255));
        row++;
        for (int i = 3; i < 5; ++i) {
            if (info_tmp[i]) {
                table->setItem(row, 1, new QTableWidgetItem(QString::fromStdString("Supermarket " + std::to_string(i - 2))));
                QString income_house = "Income: ";
                income_house += "+50M";
                table->setItem(row + 1, 1, new QTableWidgetItem(income_house));
                QString amount_house = "Amount: ";
                amount_house += std::to_string(info_tmp[i]);
                table->setItem(row + 2, 1, new QTableWidgetItem(amount_house));
                table->setSpan(row, 0, 3, 1);

                QIcon icon;
                if (i == 3) icon = QIcon(shop1_btn_pix);
                else icon = QIcon(shop2_btn_pix);
                table->setItem(row, 0, new QTableWidgetItem(icon, ""));

                table->setItem(row + 3, 0, new QTableWidgetItem());
                table->setSpan(row + 3, 0, 1, 2);
                row += 4;

            }
        }
    }
}

void PocketEconomic::PlayersInfoIsShown() {
    QObject::connect(players_info_btn, &QPushButton::clicked, [&]() {
        players_info->setVisible(!players_info->isVisible());
        if (players_info->isVisible()) {
            if (player->color == player->Red) MakeProfile(red_profile);
            else if (player->color == player->Orange) MakeProfile(orange_profile);
            else if (player->color == player->Yellow) MakeProfile(yellow_profile);
            else if (player->color == player->Blue) MakeProfile(blue_profile);
            else if (player->color == player->Violet) MakeProfile(violet_profile);
            players_info->update();
        }
        news->setVisible(false);
        offer->setVisible(false);
        land_resort_information->setVisible(false);
        if (shop_information->isVisible()) {
            shop_information->setVisible(false);
            personal_info->setGeometry(personal_info->pos().x() + shop_information->size().width() + 5, personal_info->pos().y(), personal_info->size().width(), personal_info->size().height());
            next_step_btn->setGeometry(personal_info->pos().x() + 10, personal_info->pos().y() + personal_info->size().height() + 5, personal_info->size().width() - 20, 25);
        }
        background_picture_->setPixmap(background_pix);
        return;
        });
    QObject::connect(players_info_icons[0], &QPushButton::clicked, [&]() {
        MakeProfile(red_profile);
        players_info->update();
        background_picture_->setPixmap(background_pix);
        return;
        });
    QObject::connect(players_info_icons[1], &QPushButton::clicked, [&]() {
        MakeProfile(orange_profile);
        players_info->update();
        background_picture_->setPixmap(background_pix);
        return;
        });
    QObject::connect(players_info_icons[2], &QPushButton::clicked, [&]() {
        MakeProfile(yellow_profile);
        players_info->update();
        background_picture_->setPixmap(background_pix);
        return;
        });
    QObject::connect(players_info_icons[3], &QPushButton::clicked, [&]() {
        MakeProfile(blue_profile);
        players_info->update();
        background_picture_->setPixmap(background_pix);
        return;
        });
    QObject::connect(players_info_icons[4], &QPushButton::clicked, [&]() {
        MakeProfile(violet_profile);
        players_info->update();
        background_picture_->setPixmap(background_pix);
        return;
        });
}

void PocketEconomic::CloseAllInfoWindows() {
    players_info->setVisible(false);
    news->setVisible(false);
    if (shop_information->isVisible()) {
        shop_information->setVisible(false);
        personal_info->setGeometry(personal_info->pos().x() + shop_information->size().width() + 5, personal_info->pos().y(), personal_info->size().width(), personal_info->size().height());
        next_step_btn->setGeometry(personal_info->pos().x() + 10, personal_info->pos().y() + personal_info->size().height() + 5, personal_info->size().width() - 20, 25);
    }
    offer->setVisible(false);
    land_resort_information->setVisible(false);
}

void PocketEconomic::NextStep() {
    QObject::connect(next_step_btn, &QPushButton::clicked, [&]() {
        
        game->nextPlayer();
        if (game->finished()) {
            results->setText(QString::fromStdString(game->getResults()));
            window->close();
            results->show();
        }        
        auto color = player->color;
        if (color == player->Red) {
            if (player->availiable[1]) player->color = player->Orange;
            else if (player->availiable[2]) player->color = player->Yellow;
            else if (player->availiable[3]) player->color = player->Blue;
            else if (player->availiable[4]) player->color = player->Violet;
        }
        else if (color == player->Orange) {
            if (player->availiable[2]) player->color = player->Yellow;
            else if (player->availiable[3]) player->color = player->Blue;
            else if (player->availiable[4]) player->color = player->Violet;
            else if (player->availiable[0]) player->color = player->Red;
        }
        else if (color == player->Yellow) {
            if (player->availiable[3]) player->color = player->Blue;
            else if (player->availiable[4]) player->color = player->Violet;
            else if (player->availiable[0]) player->color = player->Red;
            else if (player->availiable[1]) player->color = player->Orange;
        }
        else if (color == player->Blue) {
            if (player->availiable[4]) player->color = player->Violet;
            else if (player->availiable[0]) player->color = player->Red;
            else if (player->availiable[1]) player->color = player->Orange;
            else if (player->availiable[2]) player->color = player->Yellow;
        }
        else if (color == player->Violet) {
            if (player->availiable[0]) player->color = player->Red;
            else if (player->availiable[1]) player->color = player->Orange;
            else if (player->availiable[2]) player->color = player->Yellow;
            else if (player->availiable[3]) player->color = player->Blue;
        }
        CloseAllInfoWindows();
        ChangePlayer();
        });
}

void PocketEconomic::ChangePlayer() {
    Player_Owner::Color color = player->color;
    if (color == player->Red) {
        house1_btn->setIcon(house1_front_red_pix);
        house1_roof->setPixmap(house1_roof_red_pix);
        house2_btn->setIcon(house2_front_red_pix);
        house2_roof->setPixmap(house2_roof_red_pix);
        house3_btn->setIcon(house3_front_red_pix);
        house3_roof->setPixmap(house3_roof_red_pix);
        shop_buidings_pictures[0]->setPixmap(house1_front_red_pix.scaled(100, 100, Qt::KeepAspectRatio));
        shop_buidings_pictures[1]->setPixmap(house2_front_red_pix.scaled(100, 100, Qt::KeepAspectRatio));
        shop_buidings_pictures[2]->setPixmap(house3_front_red_pix.scaled(100, 100, Qt::KeepAspectRatio));

        personal_info->setStyleSheet(personal_info_red_border_style);
    }
    else if (color == player->Orange) {
        house1_btn->setIcon(house1_front_orange_pix);
        house1_roof->setPixmap(house1_roof_orange_pix);
        house2_btn->setIcon(house2_front_orange_pix);
        house2_roof->setPixmap(house2_roof_orange_pix);
        house3_btn->setIcon(house3_front_orange_pix);
        house3_roof->setPixmap(house3_roof_orange_pix);
        shop_buidings_pictures[0]->setPixmap(house1_front_orange_pix.scaled(100, 100, Qt::KeepAspectRatio));
        shop_buidings_pictures[1]->setPixmap(house2_front_orange_pix.scaled(100, 100, Qt::KeepAspectRatio));
        shop_buidings_pictures[2]->setPixmap(house3_front_orange_pix.scaled(100, 100, Qt::KeepAspectRatio));

        personal_info->setStyleSheet(personal_info_orange_border_style);
    }
    else if (color == player->Yellow) {
        house1_btn->setIcon(house1_front_yellow_pix);
        house1_roof->setPixmap(house1_roof_yellow_pix);
        house2_btn->setIcon(house2_front_yellow_pix);
        house2_roof->setPixmap(house2_roof_yellow_pix);
        house3_btn->setIcon(house3_front_yellow_pix);
        house3_roof->setPixmap(house3_roof_yellow_pix);
        shop_buidings_pictures[0]->setPixmap(house1_front_yellow_pix.scaled(100, 100, Qt::KeepAspectRatio));
        shop_buidings_pictures[1]->setPixmap(house2_front_yellow_pix.scaled(100, 100, Qt::KeepAspectRatio));
        shop_buidings_pictures[2]->setPixmap(house3_front_yellow_pix.scaled(100, 100, Qt::KeepAspectRatio));

        personal_info->setStyleSheet(personal_info_yellow_border_style);
    }
    else if (color == player->Blue) {
        house1_btn->setIcon(house1_front_blue_pix);
        house1_roof->setPixmap(house1_roof_blue_pix);
        house2_btn->setIcon(house2_front_blue_pix);
        house2_roof->setPixmap(house2_roof_blue_pix);
        house3_btn->setIcon(house3_front_blue_pix);
        house3_roof->setPixmap(house3_roof_blue_pix);
        shop_buidings_pictures[0]->setPixmap(house1_front_blue_pix.scaled(100, 100, Qt::KeepAspectRatio));
        shop_buidings_pictures[1]->setPixmap(house2_front_blue_pix.scaled(100, 100, Qt::KeepAspectRatio));
        shop_buidings_pictures[2]->setPixmap(house3_front_blue_pix.scaled(100, 100, Qt::KeepAspectRatio));

        personal_info->setStyleSheet(personal_info_blue_border_style);
    }
    else if (color == player->Violet) {
        house1_btn->setIcon(house1_front_violet_pix);
        house1_roof->setPixmap(house1_roof_violet_pix);
        house2_btn->setIcon(house2_front_violet_pix);
        house2_roof->setPixmap(house2_roof_violet_pix);
        house3_btn->setIcon(house3_front_violet_pix);
        house3_roof->setPixmap(house3_roof_violet_pix);
        shop_buidings_pictures[0]->setPixmap(house1_front_violet_pix.scaled(100, 100, Qt::KeepAspectRatio));
        shop_buidings_pictures[1]->setPixmap(house2_front_violet_pix.scaled(100, 100, Qt::KeepAspectRatio));
        shop_buidings_pictures[2]->setPixmap(house3_front_violet_pix.scaled(100, 100, Qt::KeepAspectRatio));

        personal_info->setStyleSheet(personal_info_violet_border_style);
    }
    house1_btn->setIconSize(QSize(48, 48));
    house2_btn->setIconSize(QSize(45, 45));
    house3_btn->setIconSize(QSize(45, 45));

    std::string new_capital = std::to_string(rand() % 100 - rand() % 10) + "M"; ///////////////////////// backend
    if (new_capital[0] == '-') {
        capital_number->setStyleSheet(personal_info_bad_value_style);
    }
    else {
        capital_number->setStyleSheet(personal_info_good_value_style);
    }
    capital_number->setText(QString::fromStdString(new_capital));

    std::string new_income = std::to_string(rand() % 100 - rand() % 10) + "M"; ///////////////////////// backend
    if (new_income[0] == '-') {
        income_number->setStyleSheet(personal_info_bad_value_style);
    }
    else {
        new_income = '+' + new_income;
        income_number->setStyleSheet(personal_info_good_value_style);
    }
    income_number->setText(QString::fromStdString(new_income));

    window->update();
}

void PocketEconomic::MakeMainWindow() {
    window->resize(fullscreen_width, fullscreen_height);

    window->setWindowTitle("PocketEconomic");
    window->installEventFilter(this);
    background_picture_->setMouseTracking(true);

    player->color = player->Red;

    AddHouse();
    MakeButtons();
    Styling();
    SetLandsCoors();
    PrepareBuildings();
    PrepareOffer();
    OfferIsShown();
    CapitalAndIncome();
    CreateShop();
    ShopIsShown();
    PrepareLandAnsResortInformation();
    LandAnsResortInformationIsShown();
    PrepareNews();
    NewsIsShown();
    PreparePlayersInfo();
    PlayersInfoIsShown();
    NextStep();
    ChangePlayer();


    //window->showMaximized();
    window->showFullScreen();
}

void PocketEconomic::InputCosts() {
    InputCostsSettings();
    InputCostsContinue();
    costs_window->showFullScreen();
}

void PocketEconomic::InputCostsSettings() {
    costs_window->setGeometry(0, 0, fullscreen_width, fullscreen_height - 50);
    costs_window->setWindowTitle("PocketEconomic");
    //costs_window->setStyleSheet("background-color: #1e1e1e");
    costs_window->setLayout(input_costs_settings_layout);
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, QColor(30, 30, 30));
    costs_window->setAutoFillBackground(true);
    costs_window->setPalette(pal);

    QString style =
        "QPushButton {"
        "  color: white;"
        "  font-size: 16px;"
        "  border-width: 2px;"
        "  border-color: #525252;"
        "  border-style: solid;"
        "  border-radius: 8px;"
        "}"
        "QPushButton:hover { "
        "  background-color: #0f0f0f;"
        "}"
        "QPushButton:pressed { "
        "  background-color: black;"
        "}"

        "QLabel { "
        "  font-size: 20px;"
        "}"
        //"QLineEdit { "
        //"  font-size: 16px;"
        //"  color: white;"
        ////"  background-color: white;"
        //"}"
        "QLineEdit { "
        "  background-color: #2d2d2d;"
        "  border: 1px solid gray;"
        "  padding: 0 8px;"
        "  font-size: 16px;"
        "}";
    costs_window->setStyleSheet(style);

    input_costs_settings_layout->addWidget(input_costs_settings_first_title, 0, 0, 1, 6);
    input_costs_settings_layout->addWidget(input_costs_settings_second_title, 2, 0, 1, 6);
    input_costs_settings_layout->addWidget(input_costs_settings_third_title, 4, 0, 1, 6);
    input_costs_settings_layout->addWidget(input_costs_settings_forth_title, 6, 0, 1, 6);
    input_costs_settings_layout->addWidget(input_costs_settings_fifth_title, 8, 0, 1, 2);
    input_costs_settings_layout->addWidget(input_costs_settings_sixth_title, 10, 0, 1, 2);

    input_costs_settings_house1_sqr->setPlaceholderText(QString::fromStdString(
        std::to_string(game->getCostOfSquareMeterMonolithicHouse())));
    input_costs_settings_layout->addWidget(input_costs_settings_house1_sqr, 1, 0, 1, 2);
    input_costs_settings_house1_sqr->setFixedSize(QSize(450, 25));
    input_costs_settings_house2_sqr->setPlaceholderText(QString::fromStdString(
        std::to_string(game->getCostOfSquareMeterPanelHouse())));
    input_costs_settings_layout->addWidget(input_costs_settings_house2_sqr, 1, 2, 1, 2);
    input_costs_settings_house2_sqr->setFixedSize(QSize(450, 25));
    input_costs_settings_house3_sqr->setPlaceholderText(QString::fromStdString(
        std::to_string(game->getCostOfSquareMeterBrickHouse())));
    input_costs_settings_layout->addWidget(input_costs_settings_house3_sqr, 1, 4, 1, 2);
    input_costs_settings_house3_sqr->setFixedSize(QSize(450, 25));

    input_costs_settings_house1_build->setPlaceholderText(QString::fromStdString(
        std::to_string(game->getCostOfBuildingMonolithicHouse())));
    input_costs_settings_layout->addWidget(input_costs_settings_house1_build, 3, 0, 1, 2);
    input_costs_settings_house1_build->setFixedSize(QSize(450, 25));
    input_costs_settings_house2_build->setPlaceholderText(QString::fromStdString(
        std::to_string(game->getCostOfBuildingPanelHouse())));
    input_costs_settings_layout->addWidget(input_costs_settings_house2_build, 3, 2, 1, 2);
    input_costs_settings_house2_build->setFixedSize(QSize(450, 25));
    input_costs_settings_house3_build->setPlaceholderText(QString::fromStdString(
        std::to_string(game->getCostOfBuildingBrickHouse())));
    input_costs_settings_layout->addWidget(input_costs_settings_house3_build, 3, 4, 1, 2);
    input_costs_settings_house3_build->setFixedSize(QSize(450, 25));


    input_costs_settings_shop1_product->setPlaceholderText(QString::fromStdString(
        std::to_string(game->getCostOfOneProductSupermarket())));
    input_costs_settings_layout->addWidget(input_costs_settings_shop1_product, 5, 0, 1, 2);
    input_costs_settings_shop1_product->setFixedSize(QSize(450, 25));
    input_costs_settings_shop2_product->setPlaceholderText(QString::fromStdString(
        std::to_string(game->getCostOfOneProductHypermarket())));
    input_costs_settings_layout->addWidget(input_costs_settings_shop2_product, 5, 2, 1, 2);
    input_costs_settings_shop2_product->setFixedSize(QSize(450, 25));


    input_costs_settings_shop1_build->setPlaceholderText(QString::fromStdString(
        std::to_string(game->getCostOfBuildingSupermarket())));
    input_costs_settings_layout->addWidget(input_costs_settings_shop1_build, 7, 0, 1, 2);
    input_costs_settings_shop1_build->setFixedSize(QSize(450, 25));
    input_costs_settings_shop2_build->setPlaceholderText(QString::fromStdString(
        std::to_string(game->getCostOfBuildingHypermarket())));
    input_costs_settings_layout->addWidget(input_costs_settings_shop2_build, 7, 2, 1, 2);
    input_costs_settings_shop2_build->setFixedSize(QSize(450, 25));

    input_costs_settings_cell_cost->setPlaceholderText(QString::fromStdString(
        std::to_string(game->getCostOfLandCell())));
    input_costs_settings_layout->addWidget(input_costs_settings_cell_cost, 9, 0, 1, 2);
    input_costs_settings_cell_cost->setFixedSize(QSize(450, 25));
    input_costs_settings_resort_cost->setPlaceholderText(QString::fromStdString(
        std::to_string(game->getCostOfResort())));
    input_costs_settings_layout->addWidget(input_costs_settings_resort_cost, 11, 0, 1, 2);
    input_costs_settings_resort_cost->setFixedSize(QSize(450, 25));

    input_costs_settings_ok->setFixedSize(QSize(450, 50));
    input_costs_settings_layout->addWidget(input_costs_settings_ok, 12, 2, 1, 2);

}

void PocketEconomic::InputCostsContinue() {
    QObject::connect(input_costs_settings_ok, &QPushButton::clicked, [&]() {
        try {
            game->setCostOfSquareMeterMonolithic(
                std::stoi(input_costs_settings_house1_sqr->text().toStdString()));
        }
        catch (const std::exception& e) {}

        try {
            game->setCostOfSquareMeterPanel(
                std::stoi(input_costs_settings_house2_sqr->text().toStdString()));
        }
        catch (const std::exception& e) {}

        try {
            game->setCostOfSquareMeterBrick(
                std::stoi(input_costs_settings_house3_sqr->text().toStdString()));
        }
        catch (const std::exception& e) {}



        try {
            game->setCostOfBuildingMonolithicHouse(
                std::stoi(input_costs_settings_house1_build->text().toStdString()));
        }
        catch (const std::exception& e) {}

        try {
            game->setCostOfBuildingPanelHouse(
                std::stoi(input_costs_settings_house2_build->text().toStdString()));
        }
        catch (const std::exception& e) {}

        try {
            game->setCostOfBuildingBrickHouse(
                std::stoi(input_costs_settings_house3_build->text().toStdString()));
        }
        catch (const std::exception& e) {}



        try {
            game->setCostOfOneProductSupermarket(
                std::stoi(input_costs_settings_shop1_product->text().toStdString()));
        }
        catch (const std::exception& e) {}

        try {
            game->setCostOfOneProductSupermarket(
                std::stoi(input_costs_settings_shop2_product->text().toStdString()));
        }
        catch (const std::exception& e) {}



        try {
            game->setCostOfBuildingSupermarket(
                std::stoi(input_costs_settings_shop1_build->text().toStdString()));
        }
        catch (const std::exception& e) {}

        try {
            game->setCostOfBuildingHypermarket(
                std::stoi(input_costs_settings_shop2_build->text().toStdString()));
        }
        catch (const std::exception& e) {}



        try {
            game->setCostOfLandCell(
                std::stoi(input_costs_settings_cell_cost->text().toStdString()));
        }
        catch (const std::exception& e) {}

        try {
            game->setCostOfResort(
                std::stoi(input_costs_settings_resort_cost->text().toStdString()));
        }
        catch (const std::exception& e) {}


        costs_window->close();



        InputSupplies();
        });
}


void PocketEconomic::InputSupplies() {
    InputSuppliesSettings();
    InputSuppliesContinue();
    supplies_window->showFullScreen();
}

void PocketEconomic::InputSuppliesSettings() {
    supplies_window->setGeometry(0, 0, fullscreen_width, fullscreen_height - 50);
    supplies_window->setWindowTitle("PocketEconomic");
    //supplies_window->setStyleSheet("background-color: white");
    supplies_window->setLayout(input_supplies_layout);
    supplies_window->setLayout(input_costs_settings_layout);
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, QColor(30, 30, 30));
    supplies_window->setAutoFillBackground(true);
    supplies_window->setPalette(pal);

    QString style =
        "QPushButton {"
        "  color: white;"
        "  font-size: 16px;"
        "  border-width: 2px;"
        "  border-color: #525252;"
        "  border-style: solid;"
        "  border-radius: 8px;"
        "}"
        "QPushButton:hover { "
        "  background-color: #0f0f0f;"
        "}"
        "QPushButton:pressed { "
        "  background-color: black;"
        "}"

        "QLabel { "
        "  font-size: 20px;"
        "}"
        "QLineEdit { "
        "  background-color: #2d2d2d;"
        "  border: 1px solid gray;"
        "  padding: 0 8px;"
        "  font-size: 16px;"
        "}";
    supplies_window->setStyleSheet(style);

    input_supplies_layout->addWidget(input_supplies_first_title, 0, 0, 1, 6);
    input_supplies_layout->addWidget(input_supplies_second_title, 2, 0, 1, 6);

    input_supplies_house1_demand->setPlaceholderText(QString::fromStdString(
        std::to_string(game->getDefaultMonolithicHouseDemand())));
    input_supplies_layout->addWidget(input_supplies_house1_demand, 1, 0, 1, 2);
    input_supplies_house1_demand->setFixedSize(QSize(450, 25));
    input_supplies_house2_demand->setPlaceholderText(QString::fromStdString(
        std::to_string(game->getDefaultPanelHouseDemand())));
    input_supplies_layout->addWidget(input_supplies_house2_demand, 1, 2, 1, 2);
    input_supplies_house2_demand->setFixedSize(QSize(450, 25));
    input_supplies_house3_demand->setPlaceholderText(QString::fromStdString(
        std::to_string(game->getDefaultBrickHouseDemand())));
    input_supplies_layout->addWidget(input_supplies_house3_demand, 1, 4, 1, 2);
    input_supplies_house3_demand->setFixedSize(QSize(450, 25));
    

    input_supplies_shop1_demand->setPlaceholderText(QString::fromStdString(
        std::to_string(game->getDefaultSupermarketDemand())));
    input_supplies_layout->addWidget(input_supplies_shop1_demand, 3, 0, 1, 2);
    input_supplies_shop1_demand->setFixedSize(QSize(450, 25));
    input_supplies_shop2_demand->setPlaceholderText(QString::fromStdString(
        std::to_string(game->getDefaultHypermarketDemand())));
    input_supplies_layout->addWidget(input_supplies_shop2_demand, 3, 2, 1, 2);
    input_supplies_shop2_demand->setFixedSize(QSize(450, 25));


    supplies_ok->setFixedSize(QSize(450, 50));
    input_supplies_layout->addWidget(supplies_ok, 5, 2, 2, 2);

}

void PocketEconomic::InputSuppliesContinue() {
    QObject::connect(supplies_ok, &QPushButton::clicked, [&]() {

        try {
            game->setDefaultMonolithicHouseDemand(
                std::stoi(input_supplies_house1_demand->text().toStdString()));
        }
        catch (const std::exception& e) {}

        try {
            game->setDefaultPanelHouseDemand(
                std::stoi(input_supplies_house2_demand->text().toStdString()));
        }
        catch (const std::exception& e) {}

        try {
            game->setDefaultBrickHouseDemand(
                std::stoi(input_supplies_house3_demand->text().toStdString()));
        }
        catch (const std::exception& e) {}


        try {
            game->setDefaultSupermarketDemand(
                std::stoi(input_supplies_shop1_demand->text().toStdString()));
        }
        catch (const std::exception& e) {}

        try {
            game->setDefaultHypermarketDemand(
                std::stoi(input_supplies_shop2_demand->text().toStdString()));
        }
        catch (const std::exception& e) {}


        supplies_window->close();


        InputPlayers();
        });
}

void PocketEconomic::InputPlayers() {
    InputPlayersSettings();
    InputPlayersContinue();
    input_players_window->showFullScreen();
}

void PocketEconomic::InputPlayersSettings() {
    QGridLayout* layout = new QGridLayout();
    QLabel* first_title = new QLabel("Players club");
    input_players_window->setGeometry(0, 0, fullscreen_width, fullscreen_height - 50);
    input_players_window->setWindowTitle("PocketEconomic");
    //input_players_window->setStyleSheet("background-color: white");
    input_players_window->setLayout(layout);
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, QColor(30, 30, 30));
    input_players_window->setAutoFillBackground(true);
    input_players_window->setPalette(pal);

    QString style =
        "QPushButton {"
        "  color: white;"
        "  font-size: 16px;"
        "  border-width: 2px;"
        "  border-color: #525252;"
        "  border-style: solid;"
        "  border-radius: 8px;"
        "}"
        "QPushButton:hover { "
        "  background-color: #0f0f0f;"
        "}"
        "QPushButton:pressed { "
        "  background-color: black;"
        "}"

        "QLabel { "
        "  font-size: 20px;"
        "}"
        "QLineEdit { "
        "  background-color: #2d2d2d;"
        "  border: 1px solid gray;"
        "  padding: 0 8px;"
        "  font-size: 16px;"
        "}";
    bot1->setStyleSheet("font-size: 16px; background-color: #2d2d2d; color: white;");
    bot2->setStyleSheet(bot1->styleSheet());
    bot3->setStyleSheet(bot1->styleSheet());
    bot4->setStyleSheet(bot1->styleSheet());
    bot5->setStyleSheet(bot1->styleSheet());
    input_players_window->setStyleSheet(style);

    layout->addWidget(first_title, 0, 0, 1, 2);
    layout->setAlignment(Qt::AlignHCenter);

    player1->setPlaceholderText("Player 1");
    layout->addWidget(player1, 1, 3, 1, 2);
    player1->setFixedSize(QSize(450, 25));
    player2->setPlaceholderText("Player 2");
    layout->addWidget(player2, 2, 3, 1, 2);
    player2->setFixedSize(QSize(450, 25));
    player3->setPlaceholderText("Player 3");
    layout->addWidget(player3, 3, 3, 1, 2);
    player3->setFixedSize(QSize(450, 25));
    player4->setPlaceholderText("Player 4");
    layout->addWidget(player4, 4, 3, 1, 2);
    player4->setFixedSize(QSize(450, 25));
    player5->setPlaceholderText("Player 5");
    layout->addWidget(player5, 5, 3, 1, 2);
    player5->setFixedSize(QSize(450, 25));

    player1->setVisible(false);
    player2->setVisible(false);
    player3->setVisible(false);
    player4->setVisible(false);
    player5->setVisible(false);


    layout->addWidget(bot1, 6, 3, 1, 2);
    bot1->setFixedSize(QSize(450, 25));
    layout->addWidget(bot2, 7, 3, 1, 2);
    bot2->setFixedSize(QSize(450, 25));
    layout->addWidget(bot3, 8, 3, 1, 2);
    bot3->setFixedSize(QSize(450, 25));
    layout->addWidget(bot4, 9, 3, 1, 2);
    bot4->setFixedSize(QSize(450, 25));
    layout->addWidget(bot5, 10, 3, 1, 2);
    bot5->setFixedSize(QSize(450, 25));


    bot1->setVisible(false);
    bot2->setVisible(false);
    bot3->setVisible(false);
    bot4->setVisible(false);
    bot5->setVisible(false);

    input_players_ok->setFixedSize(QSize(450, 50));
    layout->addWidget(input_players_ok, 11, 3, 1, 2);

    add_player->setFixedSize(QSize(150, 50));
    layout->addWidget(add_player, 0, 3);
    remove_player->setFixedSize(QSize(150, 50));
    layout->addWidget(remove_player, 0, 4);
    add_bot->setFixedSize(QSize(150, 50));
    layout->addWidget(add_bot, 0, 5);
    remove_bot->setFixedSize(QSize(150, 50));
    layout->addWidget(remove_bot, 0, 6);
}

void PocketEconomic::InputPlayersContinue() {
    QObject::connect(input_players_ok, &QPushButton::clicked, [&]() {
        if (players_cnt_on_players_window + bots_cnt_on_players_window >= 2
            && players_cnt_on_players_window + bots_cnt_on_players_window <= 5) {
          /* */
            for (int i = 0; i < players_cnt_on_players_window + bots_cnt_on_players_window; ++i) {
                player->availiable[i] = true;
            }
            if (player1->isVisible()) {
                Player* new_player = new Player();
                new_player->setNickname(player1->text().toStdString());
                game->pushPlayer(new_player);
            }
            if (player2->isVisible()) {
                Player* new_player = new Player();
                new_player->setNickname(player2->text().toStdString());
                game->pushPlayer(new_player);
            }
            if (player3->isVisible()) {
                Player* new_player = new Player();
                new_player->setNickname(player3->text().toStdString());
                game->pushPlayer(new_player);
            }
            if (player4->isVisible()) {
                Player* new_player = new Player();
                new_player->setNickname(player4->text().toStdString());
                game->pushPlayer(new_player);
            }
            if (player5->isVisible()) {
                Player* new_player = new Player();
                new_player->setNickname(player5->text().toStdString());
                game->pushPlayer(new_player);
            }
            for (int i = 0; i < bots_cnt_on_players_window; ++i) {
                game->pushBot();
            }
            input_players_window->close();
            MakeMainWindow();
            game->begin();
        }
        });

    QObject::connect(add_player, &QPushButton::clicked, [&]() {
        if (players_cnt_on_players_window + bots_cnt_on_players_window < 5
            && players_cnt_on_players_window < 5) {
            players_cnt_on_players_window++;
            if (!player1->isVisible()) {
                player1->setVisible(true);
                player1->clear();
                player1->setPlaceholderText("Player 1");
            }
            else if (!player2->isVisible()) {
                player2->setVisible(true);
                player2->clear();
                player2->setPlaceholderText("Player 2");
            }
            else if (!player3->isVisible()) {
                player3->setVisible(true);
                player3->clear();
                player3->setPlaceholderText("Player 3");
            }
            else if (!player4->isVisible()) {
                player4->setVisible(true);
                player4->clear();
                player4->setPlaceholderText("Player 4");
            }
            else if (!player5->isVisible()) {
                player5->setVisible(true);
                player5->clear();
                player5->setPlaceholderText("Player 5");
            }
        }
        });
    QObject::connect(remove_player, &QPushButton::clicked, [&]() {
        if (players_cnt_on_players_window + bots_cnt_on_players_window > 0
            && players_cnt_on_players_window > 0) {
            players_cnt_on_players_window--;
            if (player5->isVisible()) {
                player5->setVisible(false);
                player5->clear();
                player5->setPlaceholderText("Player 5");
            }
            else if (player4->isVisible()) {
                player4->setVisible(false);
                player4->clear();
                player4->setPlaceholderText("Player 4");
            }
            else if (player3->isVisible()) {
                player3->setVisible(false);
                player3->clear();
                player3->setPlaceholderText("Player 3");
            }
            else if (player2->isVisible()) {
                player2->setVisible(false);
                player2->clear();
                player2->setPlaceholderText("Player 2");
            }
            else if (player1->isVisible()) {
                player1->setVisible(false);
                player1->clear();
                player1->setPlaceholderText("Player 1");
            }
        }
        });


    QObject::connect(add_bot, &QPushButton::clicked, [&]() {
        if (players_cnt_on_players_window + bots_cnt_on_players_window < 5
            && bots_cnt_on_players_window < 5) {
            bots_cnt_on_players_window++;
            if (!bot1->isVisible()) {
                bot1->setVisible(true);
            }
            else if (!bot2->isVisible()) {
                bot2->setVisible(true);
            }
            else if (!bot3->isVisible()) {
                bot3->setVisible(true);
            }
            else if (!bot4->isVisible()) {
                bot4->setVisible(true);
            }
            else if (!bot5->isVisible()) {
                bot5->setVisible(true);
            }
        }
        });
    QObject::connect(remove_bot, &QPushButton::clicked, [&]() {
        if (players_cnt_on_players_window + bots_cnt_on_players_window > 0 
            && bots_cnt_on_players_window > 0) {
            bots_cnt_on_players_window--;
            if (bot5->isVisible()) {
                bot5->setVisible(false);
            }
            else if (bot4->isVisible()) {
                bot4->setVisible(false);
            }
            else if (bot3->isVisible()) {
                bot3->setVisible(false);
            }
            else if (bot2->isVisible()) {
                bot2->setVisible(false);
            }
            else if (bot1->isVisible()) {
                bot1->setVisible(false);
            }
        }
        });

}
