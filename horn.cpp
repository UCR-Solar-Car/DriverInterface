#include "horn.h"
#include "scaler.h"

Horn::Horn() : horn(OFF) {}

void Horn::setup(Ui::MainWindow *ui, int height, int width) {
  this->ui = ui;
  int topIconWH = topIconScaler * screenWidth;

  horn_icon = QPixmap(":/icons/horn.png")
                  .scaled(topIconWH, topIconWH, Qt::KeepAspectRatio,
                          Qt::SmoothTransformation);
                          
  ui->horn_label->move(screenWidth / 2 + topIconWH * 2.5 + hOff * 4, vOff + 2);
  this->ui->horn_label->setText("OFF");
}

void Horn::horn_on() {
  this->horn = ON;
  this->ui->horn_label->setPixmap(horn_icon);
}

void Horn::horn_off() {
  this->horn = OFF;
  this->ui->horn_label->setText("OFF");
}
