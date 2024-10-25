#include "../../includes/input_windows/input_player_window.h"

void PocketEconomic::InputPlayerWindow::setGame(Game* gamer) {
    game = gamer;
}

void PocketEconomic::InputPlayerWindow::setPocketEconomic(PocketEconomic* pocket_economic) {
    pocket_economic_ = pocket_economic;
}

void PocketEconomic::InputPlayerWindow::setPlayerOwner(PlayerOwner* player_ownerer) {
    player_owner = player_ownerer;
}

void PocketEconomic::InputPlayerWindow::InputPlayers() {
    InputPlayersSettings();
    InputPlayersContinue();
    input_players_window->showFullScreen();
}

void PocketEconomic::InputPlayerWindow::InputPlayersSettings() {
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

void PocketEconomic::InputPlayerWindow::InputPlayersContinue() {
    QObject::connect(input_players_ok, &QPushButton::clicked, [&]() {
        if (players_cnt_on_players_window + bots_cnt_on_players_window >= 2
            && players_cnt_on_players_window + bots_cnt_on_players_window <= 5) {
            /* */
            for (int i = 0; i < players_cnt_on_players_window + bots_cnt_on_players_window; ++i) {
                player_owner->availiable[i] = true;
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
            pocket_economic_->MakeMainWindow();
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
            } else if (!player2->isVisible()) {
                player2->setVisible(true);
                player2->clear();
                player2->setPlaceholderText("Player 2");
            } else if (!player3->isVisible()) {
                player3->setVisible(true);
                player3->clear();
                player3->setPlaceholderText("Player 3");
            } else if (!player4->isVisible()) {
                player4->setVisible(true);
                player4->clear();
                player4->setPlaceholderText("Player 4");
            } else if (!player5->isVisible()) {
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
            } else if (player4->isVisible()) {
                player4->setVisible(false);
                player4->clear();
                player4->setPlaceholderText("Player 4");
            } else if (player3->isVisible()) {
                player3->setVisible(false);
                player3->clear();
                player3->setPlaceholderText("Player 3");
            } else if (player2->isVisible()) {
                player2->setVisible(false);
                player2->clear();
                player2->setPlaceholderText("Player 2");
            } else if (player1->isVisible()) {
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
            } else if (!bot2->isVisible()) {
                bot2->setVisible(true);
            } else if (!bot3->isVisible()) {
                bot3->setVisible(true);
            } else if (!bot4->isVisible()) {
                bot4->setVisible(true);
            } else if (!bot5->isVisible()) {
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
            } else if (bot4->isVisible()) {
                bot4->setVisible(false);
            } else if (bot3->isVisible()) {
                bot3->setVisible(false);
            } else if (bot2->isVisible()) {
                bot2->setVisible(false);
            } else if (bot1->isVisible()) {
                bot1->setVisible(false);
            }
        }
        });
}
