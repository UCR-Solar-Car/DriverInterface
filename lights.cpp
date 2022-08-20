#include "lights.h"
#include "scaler.h"

Lights::Lights() : day(OFF), night(OFF) { return; }

void Lights::setup(Ui::MainWindow *ui, int height, int width) {
  this->ui = ui;
  ui->night_lights->setText("OFF");
  ui->day_lights->setText("OFF");

  ui->day_lights->resize(width * 10 / 100, width * 10 / 100);
  ui->day_lights->move((width - (width * ICON_COUNT) / 10) / 2 + (ui->day_lights->width() * DAY_LIGHTS_ICON), 0);

  qDebug() << "DAY" << width << ui->day_lights->width() << ui->day_lights->x() << ui->day_lights->y();

  day_icon = QPixmap(":/icons/day.png");

  ui->night_lights->resize(width * 10 / 100, width * 10 / 100);
  ui->night_lights->move((width - (width * ICON_COUNT) / 10) / 2 + (ui->night_lights->width() * NIGHT_LIGHTS_ICON), 0);
  night_icon = QPixmap(":/icons/night.png");

    qDebug() << "NIGHT" << width << ui->night_lights->width() << ui->night_lights->x() << ui->night_lights->y();
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
