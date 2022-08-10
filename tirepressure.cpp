#include "tirepressure.h"

TirePressure::TirePressure() : lowpressure(34) {return;}

void TirePressure::setup(Ui::MainWindow *ui){
    this->ui = ui;
    lowpressure_label = QPixmap(":/icons/lowpressure.png");
    normalpressure_label = QPixmap(":/icons/normalpressure.png");
    car_label = QPixmap(":/icons/car.png");
    this->ui->carLabel->setPixmap(car_label);
    normalPressure(FRONT_LEFT);
    normalPressure(FRONT_RIGHT);
    normalPressure(BACK_LEFT);
    normalPressure(BACK_RIGHT);
}

void TirePressure::lowPressure(tires tire){
    if (tire == FRONT_LEFT) {
        this->ui->frontLeft->setPixmap(lowpressure_label);
    }
    else if (tire == FRONT_RIGHT) {
        this->ui->frontRight->setPixmap(lowpressure_label);
    }
    else if (tire == BACK_LEFT){
        this->ui->backLeft->setPixmap(lowpressure_label);
    }
    else if (tire == BACK_RIGHT) {
        this->ui->backRight->setPixmap(lowpressure_label);
    }
}

void TirePressure::normalPressure(tires tire){
    if (tire == FRONT_LEFT) {
        this->ui->frontLeft->setPixmap(normalpressure_label);
    }
    else if (tire == FRONT_RIGHT) {
        this->ui->frontRight->setPixmap(normalpressure_label);
    }
    else if (tire == BACK_LEFT){
        this->ui->backLeft->setPixmap(normalpressure_label);
    }
    else if (tire == BACK_RIGHT){
        this->ui->backRight->setPixmap(normalpressure_label);
    }
}



