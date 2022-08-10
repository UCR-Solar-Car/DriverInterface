#include "horn.h"

Horn::Horn() : horn(OFF) {return;}


void Horn::setup(Ui::MainWindow *ui) {
  this->ui = ui;
  horn_icon = QPixmap(":/icons/horn.png");
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
