#pragma once

#include "qt_headers.h"

class PocketEconomic : public QMainWindow {
    Q_OBJECT

public:
    PocketEconomic(QWidget *parent = nullptr);
    ~PocketEconomic() = default;

private:
    QWidget* window = nullptr;
    QLabel* label = nullptr;
    QPushButton* button = nullptr;
};
