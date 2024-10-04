#include "frontend/main_window.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    PocketEconomic w;
    return a.exec();
}
