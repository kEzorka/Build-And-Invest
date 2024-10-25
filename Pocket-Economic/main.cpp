#include "frontend/includes/main_window.h"
#include "backend/includes/game/game.h"

int main(int argc, char* argv[]) {
    setlocale(0, "");
    QApplication app(argc, argv);
    PocketEconomic w;
    /*Game game;
    game.start();*/
    return app.exec();
}
