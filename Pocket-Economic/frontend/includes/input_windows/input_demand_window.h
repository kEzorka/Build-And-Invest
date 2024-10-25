#pragma once

#include "../main_window.h"

class PocketEconomic::InputDemandWindow {
public:
    void InputSupplies();
    void setGame(Game* gamer);
    void setInputPlayerWindow(InputPlayerWindow* input_player_window);

private:
    InputPlayerWindow* input_player_window_ = nullptr;
    void InputSuppliesContinue();
    void InputSuppliesSettings();

    Game* game = nullptr;

    int fullscreen_width = QRect(QGuiApplication::primaryScreen()->geometry()).width();
    int fullscreen_height = QRect(QGuiApplication::primaryScreen()->geometry()).height();

    QWidget* supplies_window = new QWidget();
    QPushButton* supplies_ok = new QPushButton("Continue");
    QGridLayout* input_supplies_layout = new QGridLayout();
    QLabel* input_supplies_first_title = new QLabel("Initial demand for houses");
    QLabel* input_supplies_second_title = new QLabel("Initial demand for supermarkets");
    QLineEdit* input_supplies_house1_demand = new QLineEdit();
    QLineEdit* input_supplies_house2_demand = new QLineEdit();
    QLineEdit* input_supplies_house3_demand = new QLineEdit();
    QLineEdit* input_supplies_shop1_demand = new QLineEdit();
    QLineEdit* input_supplies_shop2_demand = new QLineEdit();

};