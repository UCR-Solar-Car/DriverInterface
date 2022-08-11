#include "lights.h"
#include "scaler.h"

Lights::Lights() : day(OFF), night(OFF) { return; }

void Lights::setup(Ui::MainWindow *ui) {
  this->ui = ui;
  ui->night_lights->setText("OFF");
  ui->day_lights->setText("OFF");
  int topIconWH = .07 * screenWidth;
  day_icon = QPixmap(":/icons/day.png").scaled(topIconWH,topIconWH, Qt::KeepAspectRatio, Qt::SmoothTransformation);
  night_icon = QPixmap(":/icons/night.png").scaled(topIconWH,topIconWH, Qt::KeepAspectRatio, Qt::SmoothTransformation);
  ui->day_lights->move(2*screenWidth/6 + hOff,vOff+5);
  ui->night_lights->move(3*screenWidth/6 + hOff,vOff+1);

}

void Lights::day_on() {
  day = ON;
  night = OFF;
  ui->day_lights->setPixmap(day_icon);
  ui->night_lights->setText("OFF");
}

void Lights::day_off() {
  day = OFF;
  ui->day_lights->setText("OFF");
}

void Lights::night_on() {
  day = OFF;
  night = ON;
  ui->night_lights->setPixmap(night_icon);
  ui->day_lights->setText("OFF");
}

void Lights::night_off() {
  night = OFF;
  ui->night_lights->setText("OFF");
}

void Lights::off() {
  day = OFF;
  night = OFF;
  ui->night_lights->setText("OFF");
  ui->day_lights->setText("OFF");
}
