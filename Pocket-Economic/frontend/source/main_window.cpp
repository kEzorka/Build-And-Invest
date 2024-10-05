#include "../includes/main_window.h"

PocketEconomic::PocketEconomic(QWidget* parent) : QMainWindow(parent) {
	window->setWindowTitle("21");
	window->resize(900, 100);

	label->setGeometry(100, 50, 500, 70);
	label->setText("1142");

    label->setParent(window);

    QString LabelStyler =
        "QLabel {"
        "  border: 0px;"
        "  font-size: 16px;"
        "  background-color: #F5E2D8;"
        "  border-width: 4px;"
        "  border-color: #CE8468;"
        "  border-style: solid;"
        "  border-radius: 7px;"
        "}";

    label->setStyleSheet(LabelStyler);

	window->show();
}
