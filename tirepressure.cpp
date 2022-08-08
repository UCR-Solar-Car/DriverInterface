#include "tirepressure.h"

TirePressure::TirePressure() : threshold(34) {return;}

void TirePressure::setup(Ui::MainWindow *ui){
    this->ui = ui;
    warning_label = QPixmap(":/icons/warning.png");
    tire_label = QPixmap(":/icons/tire.png");
    car_label = QPixmap(":/icons/car.png");
    this->ui->carLabel->setPixmap(car_label);
    this->ui->frontLeft->setPixmap(tire_label);
    this->ui->frontRight->setPixmap(tire_label);
    this->ui->backLeft->setPixmap(tire_label);
    this->ui->backRight->setPixmap(tire_label);
}

void TirePressure::front_left_bad(){
    this->ui->frontLeft->setPixmap(warning_label);
}

void TirePressure::front_right_bad(){
    this->ui->frontRight->setPixmap(warning_label);
};

void TirePressure::back_left_bad(){
    this->ui->backLeft->setPixmap(warning_label);
};
void TirePressure::back_right_bad(){
    this->ui->backRight->setPixmap(warning_label);
};

void TirePressure::front_left_good(){
    this->ui->frontLeft->setPixmap(tire_label);
};

void TirePressure::front_right_good(){
    this->ui->frontRight->setPixmap(tire_label);
};

void TirePressure::back_left_good(){
    this->ui->backLeft->setPixmap(tire_label);
};

void TirePressure::back_right_good(){
    this->ui->backRight->setPixmap(tire_label);
};


