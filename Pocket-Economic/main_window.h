#pragma once

#include <QtWidgets/QMainWindow>

class PocketEconomic : public QMainWindow {
    Q_OBJECT

public:
    PocketEconomic(QWidget *parent = nullptr);
    ~PocketEconomic();

private:
    QWidget* window = new QWidget();
};
