#include "horn.h"

Horn::Horn() : horn(OFF) {return;}

void Horn::setup(Ui::MainWindow *ui) {
  this->ui = ui;
  this->ui->hornSignal->setText("OFF");
}

void Horn::horn_on()
{
    this->horn = ON;
    this->ui->hornSignal->setPixmap(
        QPixmap("C:\\Users\\kavin\\OneDrive\\Desktop\\School\\Solar Car\\Driver-Interface-2022\\horn.png"));
}

void Horn::horn_off() {
  this->horn = OFF;
  this->ui->hornSignal->setText("OFF");
}
