#include "../../includes/input_windows/input_costs_window.h"
#include "../../includes/input_windows/input_demand_window.h"

void PocketEconomic::InputCostsWindow::InputCosts() {
    InputCostsSettings();
    InputCostsContinue();
    costs_window->showFullScreen();
}

void PocketEconomic::InputCostsWindow::InputCostsSettings() {
    costs_window->setGeometry(0, 0, fullscreen_width, fullscreen_height - 50);
    costs_window->setWindowTitle("PocketEconomic");
    costs_window->setStyleSheet("background-color: #1e1e1e");
    costs_window->setLayout(input_costs_settings_layout);

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
        "  background-color: #1e1e1e;"
        "}"
        "QLineEdit { "
        "  font-size: 16px;"
        "  color: white;"
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

void PocketEconomic::InputCostsWindow::setGame(Game* gamer) {
    game = gamer;
}

void PocketEconomic::InputCostsWindow::setInputDemandWindow(InputDemandWindow* input_demand_window) {
    input_demand_window_ = input_demand_window;
}

void PocketEconomic::InputCostsWindow::InputCostsContinue() {
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



        input_demand_window_->InputSupplies();
    });
}
