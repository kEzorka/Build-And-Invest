#pragma once

#include "qt_headers.h"
#include "../../backend/includes/game/game.h"
#include "../includes/roof_label.h"


class PocketEconomic : public QMainWindow {
public:
    class InputCostsWindow;
    class InputDemandWindow;
    class InputPlayerWindow;

private:
    Q_OBJECT

public:
    PocketEconomic(QWidget* parent = nullptr);
    ~PocketEconomic() = default;



    void MakeMainWindow();
    void MakeButtons();
    void Styling();
    void AddHouse();
    void SetBuilding(QLabel* roof);
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
    void MakeProfile(QLabel* profile);
    void CloseAllInfoWindows();
    void NextStep();
    void ChangePlayer();
    void UpdatePersonalInfo();

    bool eventFilter(QObject*, QEvent* event);

    void MakeNews();

private:
    QWidget* window = new QWidget();

    InputCostsWindow* input_costs_window_ = nullptr;
    InputDemandWindow* input_demand_window_ = nullptr;
    InputPlayerWindow* input_player_window_ = nullptr;



    int fullscreen_width = QRect(QGuiApplication::primaryScreen()->geometry()).width();
    int fullscreen_height = QRect(QGuiApplication::primaryScreen()->geometry()).height();


    QPixmap cursor_pix = QPixmap("../../../Pocket-Economic/frontend/assets/arrow_cursor.png").scaled(18, 18, Qt::KeepAspectRatio);
    QPixmap cursor_invisible_pix = QPixmap("../../../Pocket-Economic/frontend/assets/empty_cursor.png").scaled(18, 18, Qt::KeepAspectRatio);
   

    QLabel* background_picture_ = nullptr;
    QPushButton* house1_btn = new QPushButton();
    QPushButton* house2_btn = new QPushButton();
    QPushButton* house3_btn = new QPushButton();
    QPushButton* shop1_btn = new QPushButton();
    QPushButton* shop2_btn = new QPushButton();
    QPushButton* info_btn = new QPushButton();

    std::vector<QLabel*> bought_objects_;
    int index_bought_buildings_ = 0;

    Grid* grid = nullptr;
    PlayerOwner* player_owner = nullptr;

    QLabel* house1_roof = nullptr;
    QLabel* house2_roof = nullptr;
    QLabel* house3_roof = nullptr;
    QLabel* shop1_roof = nullptr;
    QLabel* shop2_roof = nullptr;

    bool house1_buying_in_process = false;
    bool house2_buying_in_process = false;
    bool house3_buying_in_process = false;
    bool shop1_buying_in_process = false;
    bool shop2_buying_in_process = false;

    QPixmap background_pix = QPixmap("../../../Pocket-Economic/frontend/assets/background_full_mini.png").scaled(1600, 900, Qt::KeepAspectRatio);

    QPixmap house1_front_red_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house1/house1-front-red.png");
    QPixmap house1_front_orange_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house1/house1-front-orange.png");
    QPixmap house1_front_yellow_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house1/house1-front-yellow.png");
    QPixmap house1_front_blue_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house1/house1-front-blue.png");
    QPixmap house1_front_violet_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house1/house1-front-violet.png");

    QPixmap house2_front_red_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house2/house2-front-red.png");
    QPixmap house2_front_orange_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house2/house2-front-orange.png");
    QPixmap house2_front_yellow_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house2/house2-front-yellow.png");
    QPixmap house2_front_blue_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house2/house2-front-blue.png");
    QPixmap house2_front_violet_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house2/house2-front-violet.png");

    QPixmap house3_front_red_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house3/house3-front-red.png");
    QPixmap house3_front_orange_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house3/house3-front-orange.png");
    QPixmap house3_front_yellow_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house3/house3-front-yellow.png");
    QPixmap house3_front_blue_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house3/house3-front-blue.png");
    QPixmap house3_front_violet_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house3/house3-front-violet.png");

    QPixmap shop1_btn_pix = QPixmap("../../../Pocket-Economic/frontend/assets/shops/shop1-front.png");
    QPixmap shop2_btn_pix = QPixmap("../../../Pocket-Economic/frontend/assets/shops/shop2-front.png");

    QPixmap house1_roof_red_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house1/house1-top-red.png").scaled(25, 25, Qt::KeepAspectRatio);
    QPixmap house1_roof_orange_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house1/house1-top-orange.png").scaled(25, 25, Qt::KeepAspectRatio);
    QPixmap house1_roof_yellow_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house1/house1-top-yellow.png").scaled(25, 25, Qt::KeepAspectRatio);
    QPixmap house1_roof_blue_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house1/house1-top-blue.png").scaled(25, 25, Qt::KeepAspectRatio);
    QPixmap house1_roof_violet_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house1/house1-top-violet.png").scaled(25, 25, Qt::KeepAspectRatio);
    
    QPixmap house2_roof_red_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house2/house2-top-red.png").scaled(25, 25, Qt::KeepAspectRatio);
    QPixmap house2_roof_orange_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house2/house2-top-orange.png").scaled(25, 25, Qt::KeepAspectRatio);
    QPixmap house2_roof_yellow_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house2/house2-top-yellow.png").scaled(25, 25, Qt::KeepAspectRatio);
    QPixmap house2_roof_blue_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house2/house2-top-blue.png").scaled(25, 25, Qt::KeepAspectRatio);
    QPixmap house2_roof_violet_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house2/house2-top-violet.png").scaled(25, 25, Qt::KeepAspectRatio);

    QPixmap house3_roof_red_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house3/house3-top-red.png").scaled(25, 25, Qt::KeepAspectRatio);
    QPixmap house3_roof_orange_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house3/house3-top-orange.png").scaled(25, 25, Qt::KeepAspectRatio);
    QPixmap house3_roof_yellow_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house3/house3-top-yellow.png").scaled(25, 25, Qt::KeepAspectRatio);
    QPixmap house3_roof_blue_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house3/house3-top-blue.png").scaled(25, 25, Qt::KeepAspectRatio);
    QPixmap house3_roof_violet_pix = QPixmap("../../../Pocket-Economic/frontend/assets/house3/house3-top-violet.png").scaled(25, 25, Qt::KeepAspectRatio);

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
    

    QLabel* land_resort_information = new QLabel();
    QLabel* land_resort_information_txt = new QLabel();
    QLabel* land_resort_information_owner_txt = new QLabel();
    QPushButton* close_land_resort_information_btn = new QPushButton();
    QPushButton* land_resort_information_advertising_btn = new QPushButton();
    QPushButton* land_resort_information_updating_resort_btn = new QPushButton();

    QLabel* news = new QLabel();
    QString news_txt_style;
    QTableWidget* news_table = new QTableWidget();
    std::vector<std::pair<std::string, std::string>> tmp_news;
    QVBoxLayout* news_layout = new QVBoxLayout();

    QLabel* players_info = new QLabel();
    QHBoxLayout* players_info_layout = new QHBoxLayout();
    QVBoxLayout* players_info_vertical_layout = new QVBoxLayout();
    QString players_info_txt_style;
    QPixmap players_info_profile_icon = QPixmap("../../../Pocket-Economic/frontend/assets/profile_icon.png").scaled(70, 70, Qt::KeepAspectRatio);
   
    std::vector<QPushButton*> players_info_icons = std::vector<QPushButton*>(5);
    std::vector<QLabel*> players_info_profiles = std::vector<QLabel*>(5);
    QLabel* players_info_place_for_profile = new QLabel();
    QLabel* red_profile = new QLabel(), * orange_profile = new QLabel(), * yellow_profile = new QLabel(), * blue_profile = new QLabel(), * violet_profile = new QLabel();
    QVBoxLayout* main_layout_color_profile = new QVBoxLayout();

    QColor red_color = QColor(205, 0, 0);
    QColor orange_color = QColor(232, 116, 0);
    QColor yellow_color = QColor(180, 168, 0);
    QColor blue_color = QColor(0, 0, 224);
    QColor violet_color = QColor(133, 0, 208);

    QString red_css = "#cd0000;";
    QString orange_css = "#e87400;";
    QString yellow_css = "#b4a800;";
    QString blue_css = "#0000e0;";
    QString violet_css = "#8500d0;";
    QString grey_css = "#494949;";


    QString personal_info_red_border_style;
    QString personal_info_orange_border_style;
    QString personal_info_yellow_border_style;
    QString personal_info_blue_border_style;
    QString personal_info_violet_border_style;
    QString personal_info_good_value_style;
    QString personal_info_bad_value_style;

    QPushButton* next_step_btn = new QPushButton();
    QLabel* month_lbl = new QLabel();


    QLabel* results = new QLabel();
    Game* game = nullptr;

    QMessageBox* MsgBox = new QMessageBox();
};
