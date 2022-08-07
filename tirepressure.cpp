#include "tirepressure.h"

TirePressure::TirePressure() : frontLeftVal(36), frontRightVal(36), backLeftVal(36), backRightVal(36), threshold(34) { return; }

void TirePressure::setup(Ui::MainWindow *ui){
    this->ui = ui;
    warning_label = QPixmap(":/icons/warning.png");
    tire_label = QPixmap(":/icons/tire.png");
    (frontLeftVal < threshold) ? front_left_bad() : front_left_good();
    (frontRightVal < threshold) ? front_right_bad() : front_right_good();
    (backLeftVal < threshold) ? back_left_bad() : back_left_good();
    (backRightVal < threshold) ? back_right_bad() : back_right_good();
}

void TirePressure::front_left_bad(){
    front_left = BAD;
    this->ui->frontLeft->setPixmap(warning_label);
}
void TirePressure::front_right_bad(){
    front_right = BAD;
    this->ui->frontRight->setPixmap(warning_label);
};
void TirePressure::back_left_bad(){
    back_left = BAD;
    this->ui->backLeft->setPixmap(warning_label);
};
void TirePressure::back_right_bad(){
    back_right = BAD;
    this->ui->backRight->setPixmap(warning_label);
};
void TirePressure::front_left_good(){
    front_left = GOOD;
    this->ui->frontLeft->setPixmap(tire_label);
};
void TirePressure::front_right_good(){
    front_right = GOOD;
    this->ui->frontRight->setPixmap(tire_label);
};
void TirePressure::back_left_good(){
    back_left = GOOD;
    this->ui->backLeft->setPixmap(tire_label);
};
void TirePressure::back_right_good(){
    back_right = GOOD;
    this->ui->backRight->setPixmap(tire_label);
};


