#pragma once

#include "qt_headers.h"


class Player_Owner {
public:
    Player_Owner() {
        color = Nobody;
    }
    enum Color {
        Red,
        Orange,
        Yellow,
        Blue,
        Violet,
        Nobody
    };
    Color color = Nobody;
};

class Grid {
public:
    struct land_struct {
        int x = 0;
        int y = 0;
        int amount_x = -1;
        int amount_y = -1;
        std::vector<std::vector<bool>> free_space;
        Player_Owner owner;
    };
    int cell_size = 25;
    std::vector<land_struct> lands;
    std::vector<land_struct> resorts;
    bool isBuyingProcess = false;
    std::pair< land_struct*, land_struct*> chosen_land = { nullptr, nullptr };
};


class MyLabel : public QLabel {
public:
    void setGrid(Grid* grid) {
        grid_ = grid;
    }

    void setPlayer(Player_Owner* person) {
        player = person;
    }

protected:
    virtual void paintEvent(QPaintEvent* e) {
        QLabel::paintEvent(e);

        if (grid_->isBuyingProcess) {
            QPainter painter(this);
            painter.setRenderHint(QPainter::Antialiasing, true);
            painter.setBrush(QBrush(QColor(255, 255, 255, 50)));
            painter.setPen(QPen(QColor(255, 255, 255, 150), 1));
            for (Grid::land_struct& land : grid_->lands) {
                if (land.owner.color == player->color) {
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
private:
    Grid* grid_ = new Grid();
    Player_Owner* player = new Player_Owner();
};


class RoofLabel : public QLabel {
public:
    void setGrid(Grid* grid) {
        grid_ = grid;
    }

    void setPlayer(Player_Owner* person) {
        player = person;
    }

    bool object_can_be_built_here = false;
    int chosen_x = 0;
    int chosen_y = 0;
protected:
    virtual void paintEvent(QPaintEvent* e) {
        QLabel::paintEvent(e);
        object_can_be_built_here = false;
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);
        for (Grid::land_struct& land : grid_->lands) {
            auto x = pos().x(), y = pos().y() + 50;
            if (land.x < x && x < land.x + land.amount_x * grid_->cell_size &&
                land.y < y && y < land.y + land.amount_y * grid_->cell_size) {
                if (land.free_space.size()) {
                    int x_in_vector = (x - land.x) / grid_->cell_size;
                    int y_in_vector = (y - land.y) / grid_->cell_size;
                    if (land.free_space[x_in_vector][y_in_vector] == true && land.owner.color == player->color) {
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
private:
    Grid* grid_ = new Grid();
    Player_Owner* player = new Player_Owner();
};


class PocketEconomic : public QMainWindow {
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
    void PrepareBuildings();
    void BuyLandOrResort(int x, int y);
    void PrepareOffer();
    void OfferIsShown();
    void CapitalAndIncome();
    void CreateShop();
    void ShopIsShown();
    void PrepareLandAnsResortInformation();
    void LandAnsResortInformationIsShown();
    void PrepareNews();
    void NewsIsShown();
    void PreparePlayersInfo();
    void PlayersInfoIsShown();

    bool eventFilter(QObject*, QEvent* event);

    void MakeNews();

private:
    QWidget* window = new QWidget();


    int fullscreen_width = QRect(QGuiApplication::primaryScreen()->geometry()).width();
    int fullscreen_height = QRect(QGuiApplication::primaryScreen()->geometry()).height();


    QPixmap cursor_pix = QPixmap("../../../Pocket-Economic/frontend/assets/arrow_cursor.png").scaled(18, 18, Qt::KeepAspectRatio);
    QPixmap cursor_invisible_pix = QPixmap("../../../Pocket-Economic/frontend/assets/empty_cursor.png").scaled(18, 18, Qt::KeepAspectRatio);
   

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
    Player_Owner* player = new Player_Owner();

    QLabel* house1_roof = new RoofLabel();
    QLabel* house2_roof = new RoofLabel();
    QLabel* house3_roof = new RoofLabel();
    QLabel* shop1_roof = new RoofLabel();
    QLabel* shop2_roof = new RoofLabel();

    bool house1_buying_in_process = false;
    bool house2_buying_in_process = false;
    bool house3_buying_in_process = false;
    bool shop1_buying_in_process = false;
    bool shop2_buying_in_process = false;

    QPixmap background_pix = QPixmap("../../../Pocket-Economic/frontend/assets/background_full_mini.png").scaled(1600, 900, Qt::KeepAspectRatio);

    QPixmap house1_btn_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house1/house1-front-red.png");
    QPixmap house2_btn_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house2/house2-front-red.png");
    QPixmap house3_btn_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house3/house3-front-red.png");
    QPixmap shop1_btn_pix = QPixmap("../../../Pocket-Economic/frontend/assets/shops/shop1-front.png");
    QPixmap shop2_btn_pix = QPixmap("../../../Pocket-Economic/frontend/assets/shops/shop2-front.png");

    QPixmap house1_roof_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house1/house1-top-red.png").scaled(25, 25, Qt::KeepAspectRatio);
    QPixmap house2_roof_pix = QPixmap(QPixmap("../../../Pocket-Economic/frontend/assets/house2/house2-top-red.png").scaled(25, 25, Qt::KeepAspectRatio)).transformed(QTransform().rotate(180));
    QPixmap house3_roof_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house3/house3-top-red.png").scaled(25, 25, Qt::KeepAspectRatio);
    QPixmap shop1_roof_pix = QPixmap("../../../Pocket-Economic/frontend/assets/shops/shop1-top.png").scaled(25, 25, Qt::KeepAspectRatio);
    QPixmap shop2_roof_pix = QPixmap(QPixmap("../../../Pocket-Economic/frontend/assets/shops/shop2-top.png").scaled(25, 25, Qt::KeepAspectRatio)).transformed(QTransform().rotate(180));

    double scale_x = 1600, scale_y = 900;

    QPushButton* close_btn = new QPushButton();
    QPixmap cross_pix = QPixmap("../../../Pocket-Economic/frontend/assets/cross.png").scaled(40, 40, Qt::KeepAspectRatio);


    QLabel* offer = new QLabel();
    QLabel* offer_pic = new QLabel();
    QPixmap resort_pix = QPixmap("../../../Pocket-Economic/frontend/assets/resort_offer.png").scaled(140, 100, Qt::KeepAspectRatio);
    QPixmap land_pix = QPixmap("../../../Pocket-Economic/frontend/assets/land_offer.jpg").scaled(250, 250, Qt::KeepAspectRatio);
    QPushButton* buy_offer_btn = new QPushButton();
    QPushButton* close_offer_btn = new QPushButton();
    QLabel* offer_txt = new QLabel();
    QLabel* offer_cost_txt = new QLabel();
    bool is_offer_shown = false;

    QVBoxLayout* main_layout_offer = new QVBoxLayout();
    QVBoxLayout* horizontal_offer = new QVBoxLayout();
    QVBoxLayout* vertical_offer = new QVBoxLayout();

    QLabel* personal_info = new QLabel();
    QLabel* income = new QLabel();
    QLabel* capital = new QLabel();
    QLabel* income_number = new QLabel();
    QLabel* capital_number = new QLabel();
    QVBoxLayout* personal_info_layout = new QVBoxLayout();
    QHBoxLayout* income_layout = new QHBoxLayout();
    QHBoxLayout* capital_layout = new QHBoxLayout();


    QPushButton* news_btn = new QPushButton();
    QPushButton* players_info_btn = new QPushButton();


    QLabel* shop_information = new QLabel();
    QVBoxLayout* shop_main_layout = new QVBoxLayout();
    QHBoxLayout* shop_name_layout = new QHBoxLayout();
    QLabel* shop_name_const = new QLabel();


    std::vector<QHBoxLayout*> shop_buidings_layouts = std::vector<QHBoxLayout*>(5);
    std::vector<QVBoxLayout*> shop_buidings_info_layouts = std::vector<QVBoxLayout*>(5);
    std::vector<QLabel*> shop_buidings_pictures = std::vector<QLabel*>(5);
    std::vector<std::vector<QLabel*>> shop_building_infos = std::vector<std::vector<QLabel*>>(5);
    QString shopping_style;
    /*QHBoxLayout* shop_house1_layout = new QHBoxLayout();
    QVBoxLayout* shop_house1_info_layout = new QVBoxLayout();
    QLabel* shop_house1_picture = new QLabel();
    QLabel* shop_house1_info_name = new QLabel();
    QLabel* shop_house1_info_income = new QLabel();
    QLabel* shop_house1_info_cost = new QLabel();

    QHBoxLayout* shop_house2_layout = new QHBoxLayout();
    QVBoxLayout* shop_house2_info_layout = new QVBoxLayout();
    QLabel* shop_house2_picture = new QLabel();
    QLabel* shop_house2_info_name = new QLabel();
    QLabel* shop_house2_info_income = new QLabel();
    QLabel* shop_house2_info_cost = new QLabel();

    QHBoxLayout* shop_house3_layout = new QHBoxLayout();
    QVBoxLayout* shop_house3_info_layout = new QVBoxLayout();
    QLabel* shop_house3_picture = new QLabel();
    QLabel* shop_house3_info_name = new QLabel();
    QLabel* shop_house3_info_income = new QLabel();
    QLabel* shop_house3_info_cost = new QLabel();

    QHBoxLayout* shop_shop1_layout = new QHBoxLayout();
    QVBoxLayout* shop_shop1_info_layout = new QVBoxLayout();
    QLabel* shop_shop1_picture = new QLabel();
    QLabel* shop_shop1_info_name = new QLabel();
    QLabel* shop_shop1_info_income = new QLabel();
    QLabel* shop_shop1_info_cost = new QLabel();

    QHBoxLayout* shop_shop2_layout = new QHBoxLayout();
    QVBoxLayout* shop_shop2_info_layout = new QVBoxLayout();
    QLabel* shop_shop2_picture = new QLabel();
    QLabel* shop_shop2_info_name = new QLabel();
    QLabel* shop_shop2_info_income = new QLabel();
    QLabel* shop_shop2_info_cost = new QLabel();

    QPushButton* close_shop_btn = new QPushButton();*/


    QLabel* land_resort_information = new QLabel();
    QLabel* land_resort_information_txt = new QLabel();
    QLabel* land_resort_information_owner_txt = new QLabel();
    QPushButton* close_land_resort_information_btn = new QPushButton();

    QLabel* news = new QLabel();
    QString news_txt_style;
    QTableWidget* news_table = new QTableWidget();
    std::vector<std::pair<std::string, std::string>> tmp_news;
    QVBoxLayout* news_layout = new QVBoxLayout();


    //QLabel* players_info = new QLabel();
    //QHBoxLayout* players_info_layout = new QHBoxLayout();
    //QString players_info_txt_style;
    //QTableWidget* players_nicknames_table = new QTableWidget();/*
    //QPixmap players_info_profile_icon = QPixmap("../../../Pocket-Economic/frontend/assets/profile_icon.png").scaled(100, 100, Qt::KeepAspectRatio);*/
    //QPixmap players_info_profile_icon = QPixmap("../../../Pocket-Economic/frontend/assets/profile_icon.png");
    //std::vector<QLabel*> players_info_icons = std::vector<QLabel*>(5);
    //std::vector<std::vector<QLabel*>> players_info_nicknames_infos = std::vector<std::vector<QLabel*>>(5);
    //std::vector<std::pair<std::string, std::string>> tmp_players_info;

    //QTableWidget* players_info_table = new QTableWidget();

    QLabel* players_info = new QLabel();
    QHBoxLayout* players_info_layout = new QHBoxLayout();
    QVBoxLayout* players_info_vertical_layout = new QVBoxLayout();
    QString players_info_txt_style;
    QPixmap players_info_profile_icon = QPixmap("../../../Pocket-Economic/frontend/assets/profile_icon.png").scaled(70, 70, Qt::KeepAspectRatio);
   /* std::vector<QVBoxLayout*> players_info_layouts = std::vector<QVBoxLayout*>(5);
    std::vector<QLabel*> players_info_icons = std::vector<QLabel*>(5);
    std::vector<std::vector<QLabel*>> players_info_nicknames_infos = std::vector<std::vector<QLabel*>>(5);
    std::vector<std::pair<std::string, std::string>> tmp_players_info;*/


    std::vector<QPushButton*> players_info_icons = std::vector<QPushButton*>(5);
    std::vector<QLabel*> players_info_profiles = std::vector<QLabel*>(5);

};
