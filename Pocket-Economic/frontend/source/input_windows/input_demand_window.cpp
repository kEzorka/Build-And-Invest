#include "../../includes/input_windows/input_demand_window.h"
#include "../../includes/input_windows/input_player_window.h"

void PocketEconomic::InputDemandWindow::InputSupplies() {
    InputSuppliesSettings();
    InputSuppliesContinue();
    supplies_window->showFullScreen();
}

void PocketEconomic::InputDemandWindow::InputSuppliesSettings() {
    supplies_window->setGeometry(0, 0, fullscreen_width, fullscreen_height - 50);
    supplies_window->setWindowTitle("PocketEconomic");
    //supplies_window->setStyleSheet("background-color: white");
    supplies_window->setLayout(input_supplies_layout);
    //supplies_window->setLayout(input_costs_settings_layout);
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
        "  color: white;"
        "  font-size: 20px;"
        "}"
        "QLineEdit { "
        "  color: white;"
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

void PocketEconomic::InputDemandWindow::InputSuppliesContinue() {
    QObject::connect(supplies_ok, &QPushButton::clicked, [&]() {

        try {
            game->setDefaultMonolithicHouseDemand(
                std::stod(input_supplies_house1_demand->text().toStdString()));
        }
        catch (const std::exception& e) {}

        try {
            game->setDefaultPanelHouseDemand(
                std::stod(input_supplies_house2_demand->text().toStdString()));
        }
        catch (const std::exception& e) {}

        try {
            game->setDefaultBrickHouseDemand(
                std::stod(input_supplies_house3_demand->text().toStdString()));
        }
        catch (const std::exception& e) {}


        try {
            game->setDefaultSupermarketDemand(
                std::stod(input_supplies_shop1_demand->text().toStdString()));
        }
        catch (const std::exception& e) {}

        try {
            game->setDefaultHypermarketDemand(
                std::stod(input_supplies_shop2_demand->text().toStdString()));
        }
        catch (const std::exception& e) {}


        supplies_window->close();


        input_player_window_->InputPlayers();
        });
}

void PocketEconomic::InputDemandWindow::setGame(Game* gamer) {
    game = gamer;
}

void PocketEconomic::InputDemandWindow::setInputPlayerWindow(InputPlayerWindow* input_player_window) {
    input_player_window_ = input_player_window;
}
