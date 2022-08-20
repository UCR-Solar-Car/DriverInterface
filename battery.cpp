#include "battery.h"
#include "scaler.h"

Battery::Battery() : battery(100) { return; }

void Battery::setup(Ui::MainWindow *ui, int height, int width) {
  this->ui = ui;
  this->ui->battery->setValue(battery);
  range = battery * efficiency_constant;
  ui->range->display(int(range));

  ui->low_battery_label->resize(width * 10 / 100, width * 10 / 100);
  ui->low_battery_label->move((width - (width * ICON_COUNT) / 10) / 2 + ( ui->low_battery_label->width() * LOW_BATTERY_WARNING_ICON), 0);

  low_battery = QPixmap(":/icons/low-battery.png");
  this->ui->low_battery_label->setText("OFF");

  qDebug() << "LOW BATTERY" << width << ui->low_battery_label->width() << ui->low_battery_label->x() << ui->low_battery_label->y();

  ui->battery_label->resize(width * 10 / 100, width * 10 / 100);
  ui->battery_label->move((width - (width * ICON_COUNT) / 10) / 2 + (ui->battery_label->width() * BATTERY_WARNING_ICON), 0);

  battery_fault = QPixmap(":/icons/battery.png");
  this->ui->battery_label->setText("OFF");

 qDebug() << "BATTERY" << width << ui->battery_label->width() << ui->battery_label->x() << ui->battery_label->y();
}

void Battery::increase_battery(int val) {
  if (battery < 100 && battery > -1) {
    battery += val;
    this->ui->battery->setValue(battery);
    ui->battery->update();
    this->range += efficiency_constant;
    ui->range->display(int(range));

    check_range();
  }
}

void Battery::decrease_battery(int val) {
  if (battery < 101 && battery > 1) {
    battery -= val;
    this->ui->battery->setValue(battery);
    ui->battery->update();
    this->range -= efficiency_constant;
    ui->range->display(int(range));

    check_range();
  }
}

int Battery::get_battery() { return battery; }

int Battery::get_range() { return range; }

void Battery::on(warnings warning) {
  if (warning == LOW_BATTERY) {
    this->ui->low_battery_label->setPixmap(low_battery);
  } else if (warning == BATTERY_FAULT) {
    this->ui->battery_label->setPixmap(battery_fault);
  }
}

void Battery::off(warnings warning) {
  if (warning == LOW_BATTERY) {
    this->ui->low_battery_label->setText("OFF");
  }
  if (warning == BATTERY_FAULT) {
    this->ui->battery_label->setText("OFF");
  }
}

void Battery::check_range() {
  if (get_range() <= 30) {
    on(LOW_BATTERY);
  } else {
    off(LOW_BATTERY);
  }
}
