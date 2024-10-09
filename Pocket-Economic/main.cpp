#include "frontend/includes/main_window.h"

int main(int argc, char *argv[]) {
    setlocale(0, "");
    QApplication a(argc, argv);
    PocketEconomic w;
    return a.exec();
}
