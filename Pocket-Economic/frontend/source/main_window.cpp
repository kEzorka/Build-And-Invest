#include "../includes/main_window.h"

PocketEconomic::PocketEconomic(QWidget* parent) : QMainWindow(parent) {
    window->setWindowTitle("PocketEconomic");
    window->resize(1535, 793);

    window->installEventFilter(this); // устанавливаем фильтр
    background_picture_->setMouseTracking(true); // подключаем отслеживание курсора над фоном

    AddHouse();
    MakeButtons();
    Styling();
    SetLandsCoors();
    

    window->show();
}

void PocketEconomic::MakeButtons() {
    window->setMouseTracking(true);

    background_picture_->setGeometry(0, -50, 1535, 793);
    background_picture_->setParent(window);
    background_picture_->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    background_picture_->setPixmap(background_pix);
    //background_picture_->setVisible(false);

    int button_size = (window->size().width() - 50) / 5;
    house1_btn->setGeometry(0, window->size().height() - 50, button_size, 50);
    house1_btn->setParent(window);
    //house1_btn->setText("house 1");
    house1_btn->setIcon(house1_btn_pix);
    house1_btn->setIconSize(QSize(48, 48));

    house2_btn->setGeometry(button_size, house1_btn->pos().y(), house1_btn->size().width(), house1_btn->size().height());
    house2_btn->setParent(window);
    //house2_btn->setText("house 2");
    house2_btn->setIcon(house2_btn_pix);
    house2_btn->setIconSize(QSize(45, 45));

    house3_btn->setGeometry(button_size * 2, house1_btn->pos().y(), house1_btn->size().width(), house1_btn->size().height());
    house3_btn->setParent(window);
    house3_btn->setText("house 3");

    shop1_btn->setGeometry(button_size * 3, house1_btn->pos().y(), house1_btn->size().width(), house1_btn->size().height());
    shop1_btn->setParent(window);
    shop1_btn->setText("shop 1");

    shop2_btn->setGeometry(button_size * 4, house1_btn->pos().y(), house1_btn->size().width(), house1_btn->size().height());
    shop2_btn->setParent(window);
    shop2_btn->setText("shop 2");

    info_btn->setGeometry(button_size * 5, house1_btn->pos().y(), 50, 50);
    info_btn->setParent(window);
    info_btn->setText("i");


    house1_roof->setGeometry(QCursor::pos().x(), QCursor::pos().y(), 50, 50);
    house1_roof->setVisible(false);
    house1_roof->setParent(window);
    house1_roof->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    house1_roof->setPixmap(house1_roof_pix);

    house2_roof->setGeometry(QCursor::pos().x(), QCursor::pos().y(), 50, 50);
    house2_roof->setVisible(false);
    house2_roof->setParent(window);
    house2_roof->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    house2_roof->setPixmap(house2_roof_pix);

    house3_roof->setGeometry(QCursor::pos().x(), QCursor::pos().y(), 50, 50);
    house3_roof->setVisible(false);
    house3_roof->setParent(window);
    house3_roof->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    house3_roof->setPixmap(house3_roof_pix);


    bought_objects_.resize(400);
    for (auto& el : bought_objects_) {
        el = new QLabel(window);
        el->setVisible(false);
    }
    /*
    painter = new QPainter(window);
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setBrush(QBrush(Qt::green));
    painter->setPen(QPen(Qt::black));
    painter->drawRect(10, 10, 280, 180);*/
}

void PocketEconomic::Styling() {
    QString styler =
        "QPushButton {"
        "  border: 0px;"
        "  font-size: 16px;"
        "  background-color: #4fb6ff;"
        "  border-width: 1px;"
        "  border-color: #ffffff;"
        "  border-style: solid;"
        "  color: black;"
        "}"
        "QPushButton:hover { "
        "  background-color: #3499e0;"
        "}"
        "QPushButton:pressed { "
        "  background-color: #1b7bbf;"
        "}";

    house1_btn->setStyleSheet(styler);
    house2_btn->setStyleSheet(styler);
    house3_btn->setStyleSheet(styler);
    shop1_btn->setStyleSheet(styler);
    shop2_btn->setStyleSheet(styler);
    info_btn->setStyleSheet(styler);
}

void PocketEconomic::SetLandsCoors() {
    Land land = { 101, 122, 4, 4, 25 };

    lands_coors_and_amount_of_cells_.push_back(land);
    land;
}

void PocketEconomic::AddHouse() {
    QObject::connect(house1_btn, &QPushButton::clicked, [&]() {
        house1_buying_in_process ^= 1;
        house1_roof->setVisible(house1_buying_in_process);
        });
    QObject::connect(house2_btn, &QPushButton::clicked, [&]() {
        house2_buying_in_process ^= 1;
        house2_roof->setVisible(house2_buying_in_process);
        });
    QObject::connect(house3_btn, &QPushButton::clicked, [&]() {
        house3_buying_in_process ^= 1;
        house3_roof->setVisible(house3_buying_in_process);
        });
}


void PocketEconomic::SetBuilding(QLabel* roof, QPixmap& pix) {
    bought_objects_[index_bought_buildings_]->setGeometry(roof->pos().x(), roof->pos().y(), roof->size().width(), roof->size().height());
    bought_objects_[index_bought_buildings_]->setAlignment(roof->alignment());
    bought_objects_[index_bought_buildings_]->setPixmap(roof->pixmap());
    bought_objects_[index_bought_buildings_]->setVisible(true);
    index_bought_buildings_++;

    roof->setVisible(false);
    roof->setPixmap(pix);
}

void PocketEconomic::RotateBuilding(QLabel* roof) {
    QPixmap rotated = roof->pixmap().transformed(QTransform().rotate(-90));
    roof->setGeometry(roof->pos().x(), roof->pos().y(), roof->size().height(), roof->size().width());
    roof->setPixmap(rotated);
}

bool PocketEconomic::eventFilter(QObject* target, QEvent* event) //наш обработчик событий
{
    if (event->type() == QEvent::MouseMove)
    {
        QMouseEvent* mouseEvent = (QMouseEvent*)event;
        house1_roof->setGeometry(mouseEvent->pos().x(), std::min(std::max(mouseEvent->pos().y(), 0), window->size().height()), 50, 50);
        house2_roof->setGeometry(mouseEvent->pos().x(), std::min(std::max(mouseEvent->pos().y(), 0), window->size().height()), 50, 50);
        house3_roof->setGeometry(mouseEvent->pos().x(), std::min(std::max(mouseEvent->pos().y(), 0), window->size().height()), 50, 50);
        return true;    //возвращаю true, событие обработано, дальнейшая обработка не требуется
    }
    else if (event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent* mouseEvent = (QMouseEvent*)event;
        if (mouseEvent->button() == Qt::LeftButton) {
            if (house1_buying_in_process) {
                SetBuilding(house1_roof, house1_roof_pix);
                house1_buying_in_process = false;
            }
            else if (house2_buying_in_process) {
                SetBuilding(house2_roof, house2_roof_pix);
                house2_buying_in_process = false;
            }
            else if (house3_buying_in_process) {
                SetBuilding(house3_roof, house3_roof_pix);
                house3_buying_in_process = false;
            }
        }
        else {
            if (house1_buying_in_process) {
                RotateBuilding(house1_roof);
            }
            else if (house2_buying_in_process) {
                RotateBuilding(house2_roof);
            }
            else if (house3_buying_in_process) {
                RotateBuilding(house3_roof);
            }
        }
        return true;    
    }
    else if (event->type() == QEvent::Wheel) { // надо дописать с отцентровкой
        QWheelEvent* wheelEvent = (QWheelEvent*)event;
        QPoint numPixels = wheelEvent->angleDelta();
        if (numPixels.y() > 0) {
            if (scale_x < 3000 && scale_y < 1600) {
                scale_x *= 1.1;
                scale_y *= 1.1;
            }
        }
        else {
            if (scale_x > 1600 && scale_y > 900) {
                scale_x /= 1.1;
                scale_y /= 1.1;
            }
        }
        double x, y;
        //x = 
        house2_btn->setText(QString::fromStdString(std::to_string(scale_x) + " " + std::to_string(scale_y)));
        background_picture_->setPixmap(background_pix.scaled(scale_x, scale_y, Qt::KeepAspectRatio));
        return true;    
    }
    return false;    //Событие должно быть обработано родительским виджетом
};

