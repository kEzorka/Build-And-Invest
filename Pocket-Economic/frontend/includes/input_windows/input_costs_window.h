#pragma once

#include "../main_window.h"

class PocketEconomic::InputCostsWindow {
public:
    void InputCosts();
    void setGame(Game* gamer);
    void setInputDemandWindow(InputDemandWindow* input_demand_window);

private:
    PocketEconomic::InputDemandWindow* input_demand_window_ = nullptr;

    void InputCostsContinue();
    void InputCostsSettings();

    Game* game = nullptr;

    int fullscreen_width = QRect(QGuiApplication::primaryScreen()->geometry()).width();
    int fullscreen_height = QRect(QGuiApplication::primaryScreen()->geometry()).height();

    QWidget* costs_window = new QWidget();
    QPushButton* input_costs_settings_ok = new QPushButton("Continue");

    QGridLayout* input_costs_settings_layout = new QGridLayout();
    QLabel* input_costs_settings_first_title = new QLabel("Costs of square meter of houses");
    QLabel* input_costs_settings_second_title = new QLabel("Costs of building houses");
    QLabel* input_costs_settings_third_title = new QLabel("Costs of one unit of goods in supermarkets");
    QLabel* input_costs_settings_forth_title = new QLabel("Costs of building supermarkets");
    QLabel* input_costs_settings_fifth_title = new QLabel("Cost of one square of land");
    QLabel* input_costs_settings_sixth_title = new QLabel("Cost of a resort");
    QLineEdit* input_costs_settings_house1_sqr = new QLineEdit();
    QLineEdit* input_costs_settings_house2_sqr = new QLineEdit();
    QLineEdit* input_costs_settings_house3_sqr = new QLineEdit();
    QLineEdit* input_costs_settings_house1_build = new QLineEdit();
    QLineEdit* input_costs_settings_house2_build = new QLineEdit();
    QLineEdit* input_costs_settings_house3_build = new QLineEdit();
    QLineEdit* input_costs_settings_shop1_product = new QLineEdit();
    QLineEdit* input_costs_settings_shop2_product = new QLineEdit();
    QLineEdit* input_costs_settings_shop1_build = new QLineEdit();
    QLineEdit* input_costs_settings_shop2_build = new QLineEdit();
    QLineEdit* input_costs_settings_cell_cost = new QLineEdit();
    QLineEdit* input_costs_settings_resort_cost = new QLineEdit();

};
