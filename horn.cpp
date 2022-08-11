#include "horn.h"
#include "scaler.h"

Horn::Horn() : horn(OFF) {return;}


void Horn::setup(Ui::MainWindow *ui) {
  this->ui = ui;
  int topIconWH = .07 * screenWidth;
  horn_icon = QPixmap(":/icons/horn.png").scaled(topIconWH,topIconWH, Qt::KeepAspectRatio, Qt::SmoothTransformation);
  ui->horn_label->move(5*screenWidth/6+hOff,vOff+5);
  this->ui->horn_label->setText("OFF");
}

void Horn::horn_on()
{
    this->horn = ON;
    this->ui->horn_label->setPixmap(horn_icon);
}

void Horn::horn_off() {
  this->horn = OFF;
  this->ui->horn_label->setText("OFF");
}
