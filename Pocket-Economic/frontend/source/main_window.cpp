#include "../includes/main_window.h"
#include <QDebug>
#include <iostream>


PocketEconomic::PocketEconomic(QWidget* parent) : QMainWindow(parent) {
    window->setWindowTitle("PocketEconomic");
    window->resize(1535, 793);

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

    window->showFullScreen();
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
    house1_btn->setIcon(house1_btn_pix);
    house1_btn->setIconSize(QSize(48, 48));

    house2_btn->setGeometry(button_size, house1_btn->pos().y(), house1_btn->size().width(), house1_btn->size().height());
    house2_btn->setParent(window);
    house2_btn->setIcon(house2_btn_pix);
    house2_btn->setIconSize(QSize(45, 45));

    house3_btn->setGeometry(button_size * 2, house1_btn->pos().y(), house1_btn->size().width(), house1_btn->size().height());
    house3_btn->setParent(window);
    house3_btn->setIcon(house3_btn_pix);
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
    close_btn->setVisible(false);

    news_btn->setParent(window);
    news_btn->setGeometry(0, 0, (fullscreen_width - close_btn->size().width() - 5) / 2, close_btn->size().height() + 5);
    news_btn->setText("News");
    news_btn->setVisible(false);

    players_info_btn->setParent(window);
    players_info_btn->setGeometry(news_btn->size().width(), 0, news_btn->size().width(), close_btn->size().height() + 5);
    players_info_btn->setText("Player's information");
    players_info_btn->setVisible(false);
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
        "  border-width: 2px;"
        "  border-color: #ffffff;"
        "  border-style: solid;"
        "  border-radius: 17px;"
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

    QString personal_info_red_border_style =
        "QLabel { "
        "  background-color: #ffffff;"
        "  border-width: 3px;"
        "  border-color: #d10b0b;"
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

    QString personal_info_good_value_style =
        "QLabel { "
        "  font-size: 16px;"
        "  background-color: #ffffff;"
        "  color: black;"
        "  border-color: white;"
        "}";

    QString personal_info_bad_value_style =
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

    QString shopping_style =
        "QLabel { "
        "  border: 0px;"
        "  font-size: 16px;"
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
        //"  border: 0px;"
        "  font-size: 16px;"
        "  color: black;"
        "  font-size: 16px;"

        "  background-color: white;"
        "  border-width: 2px;"
        "  border-color: #dbdbda;"
        "  border-style: solid;"
        "  border-radius: 8px;"
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

    shop_house1_picture->setStyleSheet(shopping_style);
    shop_house1_info_name->setStyleSheet(shopping_style);
    shop_house1_info_income->setStyleSheet(shopping_style);
    shop_house1_info_cost->setStyleSheet(shopping_style);

    shop_house2_picture->setStyleSheet(shopping_style);
    shop_house2_info_name->setStyleSheet(shopping_style);
    shop_house2_info_income->setStyleSheet(shopping_style);
    shop_house2_info_cost->setStyleSheet(shopping_style);

    shop_house3_picture->setStyleSheet(shopping_style);
    shop_house3_info_name->setStyleSheet(shopping_style);
    shop_house3_info_income->setStyleSheet(shopping_style);
    shop_house3_info_cost->setStyleSheet(shopping_style);

    shop_shop1_picture->setStyleSheet(shopping_style);
    shop_shop1_info_name->setStyleSheet(shopping_style);
    shop_shop1_info_income->setStyleSheet(shopping_style);
    shop_shop1_info_cost->setStyleSheet(shopping_style);

    shop_shop2_picture->setStyleSheet(shopping_style);
    shop_shop2_info_name->setStyleSheet(shopping_style);
    shop_shop2_info_income->setStyleSheet(shopping_style);
    shop_shop2_info_cost->setStyleSheet(shopping_style);

    close_shop_btn->setStyleSheet(close_shop_style);

    land_resort_information->setStyleSheet(offer_background_style);
    land_resort_information_txt->setStyleSheet(offer_buttons_label_style);
    land_resort_information_owner_txt->setStyleSheet(offer_buttons_label_style);
    close_land_resort_information_btn->setStyleSheet(close_offer_style);

    news->setStyleSheet(news_background_style);
}

void PocketEconomic::SetLandsCoors() {
    grid->lands.resize(18ll * 4 + 5);
    int delta_x = 400;
    for (int k = 0; k < 3; ++k) {
        // 1 column
        grid->lands[k * grid->lands.size() / 4] = { 101 + k * delta_x, 122, 4, 4, std::vector<std::vector<bool>>(4, std::vector<bool>(4, true)) };
        grid->lands[k * grid->lands.size() / 4 + 1] = { 101 + k * delta_x, 260, 4, 5, std::vector<std::vector<bool>>(4, std::vector<bool>(5, true)) };
        grid->lands[k * grid->lands.size() / 4 + 2] = { 101 + k * delta_x, 423, 4, 4, std::vector<std::vector<bool>>(4, std::vector<bool>(4, true)) };
        grid->lands[k * grid->lands.size() / 4 + 3] = { 101 + k * delta_x, 561, 4, 5, std::vector<std::vector<bool>>(4, std::vector<bool>(5, true)) };
        grid->lands[k * grid->lands.size() / 4 + 4] = { 101 + k * delta_x, 723, 4, 4, std::vector<std::vector<bool>>(4, std::vector<bool>(4, true)) };

        // 2 column
        grid->lands[k * grid->lands.size() / 4 + 5] = { 241 + k * delta_x, 122, 4, 4, std::vector<std::vector<bool>>(4, std::vector<bool>(4, true)) };
        grid->lands[k * grid->lands.size() / 4 + 7] = { 240 + k * delta_x, 260, k == 2 ? 0 : 8, 5, std::vector<std::vector<bool>>(k == 2 ? 0 : 8, std::vector<bool>(5, true)) };
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

    grid->lands[3 * grid->lands.size() / 4] = { 101 + 3 * delta_x, 122, 4, 4, std::vector<std::vector<bool>>(4, std::vector<bool>(4, true)) };
    grid->lands[3 * grid->lands.size() / 4 + 1] = { 101 + 3 * delta_x, 260, 4, 5, std::vector<std::vector<bool>>(4, std::vector<bool>(5, true)) };
    grid->lands[3 * grid->lands.size() / 4 + 2] = { 101 + 3 * delta_x, 423, 4, 4, std::vector<std::vector<bool>>(4, std::vector<bool>(4, true)) };
    grid->lands[3 * grid->lands.size() / 4 + 3] = { 101 + 3 * delta_x, 561, 4, 5, std::vector<std::vector<bool>>(4, std::vector<bool>(5, true)) };
    grid->lands[3 * grid->lands.size() / 4 + 4] = { 101 + 3 * delta_x, 723, 4, 4, std::vector<std::vector<bool>>(4, std::vector<bool>(4, true)) };

    grid->resorts.resize(3);
    grid->resorts[0] = { 0, 122, 3, 4, std::vector<std::vector<bool>>(3, std::vector<bool>(4, true)) };
    grid->resorts[1] = { 240 + 2 * delta_x + 3 * grid->cell_size, 260, 5, 5, std::vector<std::vector<bool>>(5, std::vector<bool>(5, true)) };
    grid->resorts[2] = { 241 + delta_x, 723, 4, 4, std::vector<std::vector<bool>>(4, std::vector<bool>(4, true)) };
}

void PocketEconomic::AddHouse(){
    QObject::connect(house1_btn, &QPushButton::clicked, [&]() {
        house1_buying_in_process ^= 1;
        house1_roof->setVisible(house1_buying_in_process);
        grid->isBuyingProcess = house1_buying_in_process;
        QGuiApplication::setOverrideCursor(QCursor(cursor_invisible_pix));
        });
    QObject::connect(house2_btn, &QPushButton::clicked, [&]() {
        house2_buying_in_process ^= 1;
        house2_roof->setVisible(house2_buying_in_process);
        grid->isBuyingProcess = house2_buying_in_process;
        QGuiApplication::setOverrideCursor(QCursor(cursor_invisible_pix));
        });
    QObject::connect(house3_btn, &QPushButton::clicked, [&]() {
        house3_buying_in_process ^= 1;
        house3_roof->setVisible(house3_buying_in_process);
        grid->isBuyingProcess = house3_buying_in_process;
        QGuiApplication::setOverrideCursor(QCursor(cursor_invisible_pix));
        });
    QObject::connect(shop1_btn, &QPushButton::clicked, [&]() {
        shop1_buying_in_process ^= 1;
        shop1_roof->setVisible(shop1_buying_in_process);
        grid->isBuyingProcess = shop1_buying_in_process;
        QGuiApplication::setOverrideCursor(QCursor(cursor_invisible_pix));
        });
    QObject::connect(shop2_btn, &QPushButton::clicked, [&]() {
        shop2_buying_in_process ^= 1;
        shop2_roof->setVisible(shop2_buying_in_process);
        grid->isBuyingProcess = shop2_buying_in_process;
        QGuiApplication::setOverrideCursor(QCursor(cursor_invisible_pix));
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
        bought_objects_[index_bought_buildings_]->setMouseTracking(true);
        index_bought_buildings_++;
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
    else if (event->type() == QEvent::KeyPress) {
        QKeyEvent* keyEvent = (QKeyEvent*)event;
        if (keyEvent->key() == Qt::Key::Key_Escape) {
            close_btn->setVisible(!close_btn->isVisible());
            news_btn->setVisible(!news_btn->isVisible());
            players_info_btn->setVisible(!players_info_btn->isVisible());
            if (close_btn->isVisible()) {
                personal_info->setGeometry(personal_info->pos().x(), personal_info->pos().y() + 50, personal_info->size().width(), personal_info->size().height());
            }
            else {
                personal_info->setGeometry(personal_info->pos().x(), personal_info->pos().y() - 50, personal_info->size().width(), personal_info->size().height());
            }
            background_picture_->setPixmap(background_pix);
            //window->close();
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
            land->y < y && y < land->y + land->amount_y * grid->cell_size) {
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
            }
            else {
                land_resort_information_txt->setText("This land belongs to");
                if (x + land_resort_information->size().width() >= fullscreen_width) x_pos -= land_resort_information->size().width();
                if (y + land_resort_information->size().height() >= fullscreen_height - house1_btn->size().height()) y_pos -= land_resort_information->size().height();
                land_resort_information->setGeometry(x_pos, y_pos, land_resort_information->size().width(), land_resort_information->size().height());
                land_resort_information->setVisible(true);
                if (land->owner.color != player->color) {
                    land_resort_information_owner_txt->setText("someone"); // add name from backend
                }
                else {
                    land_resort_information_owner_txt->setText("you");
                }
                if (land->owner.color == player->Red) land_resort_information_owner_txt->setStyleSheet("color: #d10b0b; border: 0px");
                /*else if () {

                }*/
                background_picture_->setPixmap(background_pix);
                LandAnsResortInformationIsShown();
                return;
            }
        }
    }
    for (Grid::land_struct& resort : grid->resorts) {
        if (resort.x < x && x < resort.x + resort.amount_x * grid->cell_size &&
            resort.y < y && y < resort.y + resort.amount_y * grid->cell_size) {
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
                if (x + land_resort_information->size().width() >= fullscreen_width) x_pos -= land_resort_information->size().width();
                if (y + land_resort_information->size().height() >= fullscreen_height - house1_btn->size().height()) y_pos -= land_resort_information->size().height();
                land_resort_information->setGeometry(x_pos, y_pos, land_resort_information->size().width(), land_resort_information->size().height());
                land_resort_information->setVisible(true);               
                if (resort.owner.color != player->color) {
                    land_resort_information_owner_txt->setText("someone"); // add name from backend
                }
                else {
                    land_resort_information_owner_txt->setText("you");
                }
                if (resort.owner.color == player->Red) land_resort_information_owner_txt->setStyleSheet("color: #d10b0b; border: 0px");
                /*else if () {

                }*/
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
        //shop2_btn->setText("closed");
        is_offer_shown = false;
        background_picture_->setPixmap(background_pix);
        return;
        });
    QObject::connect(buy_offer_btn, &QPushButton::clicked, [&]() {
        offer->setVisible(false);
        is_offer_shown = false;
        (grid->chosen_land.first)->owner = *player;
        if (grid->chosen_land.second) (grid->chosen_land.second)->owner = *player;
        //shop2_btn->setText("closed");
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
}

void PocketEconomic::CreateShop() {
    shop_information->setVisible(false);
    shop_information->setParent(window);
    shop_information->setGeometry(fullscreen_width - 305, fullscreen_height - info_btn->size().height() - 765, 300, 750);
    shop_information->setLayout(shop_main_layout);

    shop_name_const->setText("SHOP");
    shop_name_layout->addWidget(shop_name_const);
    shop_name_layout->setAlignment(Qt::AlignCenter);
    shop_main_layout->addLayout(shop_name_layout);

    /*
    QLabel* trying = new QLabel();
    trying->setText("House 0\nIncome: +500000\nCost: 8000000\n");
    trying->setStyleSheet("color: white;");
    trying->setIcon(shop_house1_picture->pixmap());
    shop_main_layout->addWidget(trying);*/


    shop_house1_picture->setFixedSize(100, 100);
    shop_house1_picture->setAlignment(Qt::AlignCenter);
    shop_house1_layout->addWidget(shop_house1_picture);
    shop_house1_layout->addLayout(shop_house1_info_layout);
    shop_house1_info_layout->addWidget(shop_house1_info_name);
    shop_house1_info_layout->addWidget(shop_house1_info_income);
    shop_house1_info_layout->addWidget(shop_house1_info_cost);
    shop_house1_info_layout->setAlignment(Qt::AlignVCenter);
    shop_main_layout->addLayout(shop_house1_layout);
    shop_house1_picture->setPixmap(house1_btn_pix.scaled(100, 100, Qt::KeepAspectRatio));
    shop_house1_info_name->setText("House 1");
    shop_house1_info_income->setText("Income: +500000");
    shop_house1_info_cost->setText("Cost: 800000");

    shop_house2_picture->setFixedSize(100, 100);
    shop_house2_picture->setAlignment(Qt::AlignCenter);
    shop_house2_layout->addWidget(shop_house2_picture);
    shop_house2_layout->addLayout(shop_house2_info_layout);
    shop_house2_info_layout->addWidget(shop_house2_info_name);
    shop_house2_info_layout->addWidget(shop_house2_info_income);
    shop_house2_info_layout->addWidget(shop_house2_info_cost);
    shop_house2_info_layout->setAlignment(Qt::AlignVCenter);
    shop_main_layout->addLayout(shop_house2_layout);
    shop_house2_picture->setPixmap(house2_btn_pix.scaled(75, 75, Qt::KeepAspectRatio));
    shop_house2_info_name->setText("House 2");
    shop_house2_info_income->setText("Income: +250000");
    shop_house2_info_cost->setText("Cost: 400000");

    shop_house3_picture->setFixedSize(100, 100);
    shop_house3_picture->setAlignment(Qt::AlignCenter);
    shop_house3_layout->addWidget(shop_house3_picture);
    shop_house3_layout->addLayout(shop_house3_info_layout);
    shop_house3_info_layout->addWidget(shop_house3_info_name);
    shop_house3_info_layout->addWidget(shop_house3_info_income);
    shop_house3_info_layout->addWidget(shop_house3_info_cost);
    shop_house3_info_layout->setAlignment(Qt::AlignVCenter);
    shop_main_layout->addLayout(shop_house3_layout);
    shop_house3_picture->setPixmap(house3_btn_pix.scaled(70, 70, Qt::KeepAspectRatio));
    shop_house3_info_name->setText("House 3");
    shop_house3_info_income->setText("Income: +10000");
    shop_house3_info_cost->setText("Cost: 100000");

    shop_shop1_picture->setFixedSize(100, 100);
    shop_shop1_picture->setAlignment(Qt::AlignCenter);
    shop_shop1_layout->addWidget(shop_shop1_picture);
    shop_shop1_layout->addLayout(shop_shop1_info_layout);
    shop_shop1_info_layout->addWidget(shop_shop1_info_name);
    shop_shop1_info_layout->addWidget(shop_shop1_info_income);
    shop_shop1_info_layout->addWidget(shop_shop1_info_cost);
    shop_shop1_info_layout->setAlignment(Qt::AlignVCenter);
    shop_main_layout->addLayout(shop_shop1_layout);
    shop_shop1_picture->setPixmap(shop1_btn_pix.scaled(65, 65, Qt::KeepAspectRatio));
    shop_shop1_info_name->setText("Supermarket 1");
    shop_shop1_info_income->setText("Income: +500000");
    shop_shop1_info_cost->setText("Cost: 800000");

    shop_shop2_picture->setFixedSize(100, 100);
    shop_shop2_picture->setAlignment(Qt::AlignCenter);
    shop_shop2_layout->addWidget(shop_shop2_picture);
    shop_shop2_layout->addLayout(shop_shop2_info_layout);
    shop_shop2_info_layout->addWidget(shop_shop2_info_name);
    shop_shop2_info_layout->addWidget(shop_shop2_info_income);
    shop_shop2_info_layout->addWidget(shop_shop2_info_cost);
    shop_shop2_info_layout->setAlignment(Qt::AlignVCenter);
    shop_main_layout->addLayout(shop_shop2_layout);
    shop_shop2_picture->setPixmap(shop2_btn_pix.scaled(50, 50, Qt::KeepAspectRatio));
    shop_shop2_info_name->setText("Supermarket 2");
    shop_shop2_info_income->setText("Income: +350000");
    shop_shop2_info_cost->setText("Cost: 600000");


    close_shop_btn->setIcon(cross_pix);
    close_shop_btn->setIconSize(QSize(15, 15));
    close_shop_btn->setParent(shop_information);
    close_shop_btn->setGeometry(shop_information->size().width() - 30, 5, 25, 25);
}

void PocketEconomic::ShopIsShown() {
    QObject::connect(info_btn, &QPushButton::clicked, [&]() {
        if (!shop_information->isVisible()) {
            shop_information->setVisible(true);
            personal_info->setGeometry(personal_info->pos().x() - shop_information->size().width() - 5, personal_info->pos().y(), personal_info->size().width(), personal_info->size().height());
            background_picture_->setPixmap(background_pix);
        }
        });
    QObject::connect(close_shop_btn, &QPushButton::clicked, [&]() {
        shop_information->setVisible(false);
        personal_info->setGeometry(personal_info->pos().x() + shop_information->size().width() + 5, personal_info->pos().y(), personal_info->size().width(), personal_info->size().height());
        background_picture_->setPixmap(background_pix);
        });
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
}

void PocketEconomic::PrepareNews() {
    news_txt_who_info.resize(20);
    news->setAlignment(Qt::AlignCenter);
    news->setParent(window);
    news->setVisible(false);


    //making random news
    for (int i = 0; i < news_txt_who_info.size(); ++i) {
        int col = rand() % 6;
        news_txt_who_info[i].first = new QLabel(news);
        if (col == player->Red) {
            (news_txt_who_info[i].first)->setText("Red: ");
        }
        else if (col == player->Orange) {
            (news_txt_who_info[i].first)->setText("Orange: ");
        }
        else {
            (news_txt_who_info[i].first)->setText("namenamenamename: ");
        }
        int len = rand() % 100;
        QString str;
        while (len--) {
            char c = '0' + (rand() % 90);
            str += c;
        }
        news_txt_who_info[i].second = new QLabel(str, news);
    }

    int max_news_len = 0, max_name_len = 0;
    for (int i = 0; i < news_txt_who_info.size(); ++i) {
        QFontMetrics fm((news_txt_who_info[i].first)->font());
        max_name_len = std::max(max_name_len, fm.horizontalAdvance((news_txt_who_info[i].first)->text()));
        max_news_len = std::max(max_news_len, fm.horizontalAdvance((news_txt_who_info[i].second)->text()));
    }

    for (int i = 0; i < news_txt_who_info.size(); ++i) {
        (news_txt_who_info[i].first)->setGeometry(15, 15 + 35 * i, max_name_len + 15, 25);
        (news_txt_who_info[i].second)->setGeometry(50 + max_name_len, 15 + 35 * i, max_news_len + 15, 25);
        (news_txt_who_info[i].first)->setStyleSheet(news_txt_style);
        (news_txt_who_info[i].second)->setStyleSheet(news_txt_style);
    }

    news->setGeometry(0, news_btn->size().height() + 15, max_name_len + max_news_len + 50, 35 * news_txt_who_info.size() + 20);
}


void PocketEconomic::NewsIsShown() {
    QObject::connect(news_btn, &QPushButton::clicked, [&]() {
        news->setVisible(!news->isVisible());
        background_picture_->setPixmap(background_pix);
        return;
        });
}