#include "horn.h"
#include "scaler.h"

Horn::Horn() : horn(OFF) {return;}


void Horn::setup(Ui::MainWindow *ui) {
  this->ui = ui;
  hornSignal = QPixmap(":/icons/horn.png").scaled(topIconWH,topIconWH, Qt::KeepAspectRatio, Qt::SmoothTransformation);
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
