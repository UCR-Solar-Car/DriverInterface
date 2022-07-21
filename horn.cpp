#include "horn.h"

Horn::Horn() : horn(OFF) {return;}


void Horn::setup(Ui::MainWindow *ui) {
  this->ui = ui;
  hornSignal = QPixmap(":/icons/horn.png");
  this->ui->hornSignal->setText("OFF");
}

void Horn::horn_on()
{
    this->horn = ON;
    this->ui->hornSignal->setPixmap(hornSignal);
}

void Horn::horn_off() {
  this->horn = OFF;
  this->ui->hornSignal->setText("OFF");
}
