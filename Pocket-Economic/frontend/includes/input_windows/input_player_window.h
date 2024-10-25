#pragma once

#include "../main_window.h"

class PocketEconomic::InputPlayerWindow {
public:
    void InputPlayers();
    void setGame(Game* gamer);
    void setPocketEconomic(PocketEconomic* pocket_economic);
    void setPlayerOwner(PlayerOwner* player_ownerer);

private:
    PlayerOwner* player_owner = nullptr;
    PocketEconomic* pocket_economic_ = nullptr;
    Game* game;
    
    int fullscreen_width = QRect(QGuiApplication::primaryScreen()->geometry()).width();
    int fullscreen_height = QRect(QGuiApplication::primaryScreen()->geometry()).height();

    void InputPlayersSettings();
    void InputPlayersContinue();

    QWidget* input_players_window = new QWidget();
    QPushButton* input_players_ok = new QPushButton("Continue");
    QPushButton* add_player = new QPushButton("Add player");
    QPushButton* remove_player = new QPushButton("Remove player");
    QPushButton* add_bot = new QPushButton("Add bot");
    QPushButton* remove_bot = new QPushButton("Remove bot");
    QLineEdit* player1 = new QLineEdit();
    QLineEdit* player2 = new QLineEdit();
    QLineEdit* player3 = new QLineEdit();
    QLineEdit* player4 = new QLineEdit();
    QLineEdit* player5 = new QLineEdit();

    QLabel* bot1 = new QLabel("  Bot 1");
    QLabel* bot2 = new QLabel("  Bot 2");
    QLabel* bot3 = new QLabel("  Bot 3");
    QLabel* bot4 = new QLabel("  Bot 4");
    QLabel* bot5 = new QLabel("  Bot 5");
    int players_cnt_on_players_window = 0, bots_cnt_on_players_window = 0;
};