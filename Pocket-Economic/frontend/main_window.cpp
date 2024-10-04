#include "main_window.h"

PocketEconomic::PocketEconomic(QWidget *parent) : QMainWindow(parent) {
	window->setWindowTitle("21");
	window->resize(900, 100);

	window->show();
}

PocketEconomic::~PocketEconomic()
{}
