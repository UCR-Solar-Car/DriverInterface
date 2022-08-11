#include "tirepressure.h"
#include "scaler.h"

TirePressure::TirePressure() : lowpressure(34) {return;}

void TirePressure::setup(Ui::MainWindow *ui){
    this->ui = ui;
    int topIconWH = .03 * screenWidth;
    low_pressure_icon = QPixmap(":/icons/lowpressure.png").scaled(topIconWH,topIconWH, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    normal_pressure_icon = QPixmap(":/icons/normalpressure.png").scaled(topIconWH,topIconWH, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    car_icon = QPixmap(":/icons/car.png");
    this->ui->car_label->setPixmap(car_icon);
    normal_pressure(FRONT_LEFT);
    normal_pressure(FRONT_RIGHT);
    normal_pressure(BACK_LEFT);
    normal_pressure(BACK_RIGHT);
}

void TirePressure::low_pressure(tires tire){
    if (tire == FRONT_LEFT) {
        this->ui->front_left->setPixmap(low_pressure_icon);
    }
    else if (tire == FRONT_RIGHT) {
        this->ui->front_right->setPixmap(low_pressure_icon);
    }
    else if (tire == BACK_LEFT){
        this->ui->back_left->setPixmap(low_pressure_icon);
    }
    else if (tire == BACK_RIGHT) {
        this->ui->back_right->setPixmap(low_pressure_icon);
    }
}

void TirePressure::normal_pressure(tires tire){
    if (tire == FRONT_LEFT) {
        this->ui->front_left->setPixmap(normal_pressure_icon);
    }
    else if (tire == FRONT_RIGHT) {
        this->ui->front_right->setPixmap(normal_pressure_icon);
    }
    else if (tire == BACK_LEFT){
        this->ui->back_left->setPixmap(normal_pressure_icon);
    }
    else if (tire == BACK_RIGHT){
        this->ui->back_right->setPixmap(normal_pressure_icon);
    }
}



