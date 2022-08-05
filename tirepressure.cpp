#include "tirepressure.h"

TirePressure::TirePressure() : front_left(GOOD), front_right(GOOD), back_left(GOOD), back_right(GOOD) { return; }

void TirePressure::setup(Ui::MainWindow *ui){
    this->ui = ui;
    warning_label = QPixmap(":/icons/warning.png");
    car_label = QPixmap(":/icons/car.png");
//    this->ui->carLabel->setPixmap(car_label);

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
    this->ui->frontLeft->setText("");
};
void TirePressure::front_right_good(){
    this->ui->frontRight->setText("");
};
void TirePressure::back_left_good(){
    this->ui->backLeft->setText("");
};
void TirePressure::back_right_good(){
    this->ui->backRight->setText("");
};


