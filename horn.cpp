#include "horn.h"
#include "scaler.h"

Horn::Horn() : horn(OFF) {return;}


void Horn::setup(Ui::MainWindow *ui) {
  this->ui = ui;
  int topIconWH = .07 * screenWidth;
  hornSignal = QPixmap(":/icons/horn.png").scaled(topIconWH,topIconWH, Qt::KeepAspectRatio, Qt::SmoothTransformation);
  ui->hornSignal->move(5*screenWidth/6+hOff,vOff+5);
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
