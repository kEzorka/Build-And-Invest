#pragma once

#include "qt_headers.h"

class PocketEconomic : public QMainWindow {
    Q_OBJECT

public:
    PocketEconomic(QWidget *parent = nullptr);
    ~PocketEconomic() = default;

private:
    QWidget* window = new QWidget();
    QLabel* label = new QLabel("123");
};
