#include "battery.h"
#include "scaler.h"

Battery::Battery() : battery(100) { return; }

void Battery::setup(Ui::MainWindow *ui, uint16_t height, uint16_t width) {
  this->ui = ui;
  this->ui->battery->setValue(battery);
  range = battery * efficiency_constant;
  ui->range->display(float(range));

  ui->battery->resize(width * 10 / 100, height * 30 / 100);
  ui->battery->move(width * 20 / 100,
                    height * 50 / 100 - ui->battery->height() / 2);

  ui->range_label->resize(width * 15 / 100, height * 8 / 100);
  ui->range->resize(width * 15 / 100, height * 15 / 100);
  ui->range_label->move(width - width * 90 / 100, height - height * 20 / 100);

  ui->range->move(width - width * 90 / 100 + ui->range_label->width(),
                  height - height * 15 / 100 - ui->range_label->height());
  ui->range->resize(width * 15 / 100, height * 5 / 100);

  ui->range_label->move(ui->range_label->x(),
                        ui->range_label->y() - ui->range->height());

  qDebug() << "RANGE" << ui->range_label->x() << ui->range_label->y()
           << ui->range->x() << ui->range->y();

  ui->low_battery_label->resize(width * 10 / 100, width * 10 / 100);
  ui->low_battery_label->move(
      (width - (width * ICON_COUNT) / 10) / 2 +
          (ui->low_battery_label->width() * LOW_BATTERY_WARNING_ICON),
      0);

  low_battery = QPixmap(":/icons/low-battery.png");
  this->ui->low_battery_label->setText("OFF");

  qDebug() << "LOW BATTERY" << width << ui->low_battery_label->width()
           << ui->low_battery_label->x() << ui->low_battery_label->y();

  ui->battery_label->resize(width * 10 / 100, width * 10 / 100);
  ui->battery_label->move(
      (width - (width * ICON_COUNT) / 10) / 2 +
          (ui->battery_label->width() * BATTERY_WARNING_ICON),
      0);

  battery_fault = QPixmap(":/icons/battery.png");
  this->ui->battery_label->setText("OFF");

  qDebug() << "BATTERY" << width << ui->battery_label->width()
           << ui->battery_label->x() << ui->battery_label->y();
}

void Battery::increase_battery(uint8_t val) {
  if (battery < 100 && battery > -1) {
    battery += val;
    this->ui->battery->setValue(battery);
    ui->battery->update();
    this->range += efficiency_constant;
    ui->range->display(uint8_t(range));

    check_range();
  }
}

void Battery::decrease_battery(uint8_t val) {
  if (battery < 101 && battery > 1) {
    battery -= val;
    this->ui->battery->setValue(battery);
    ui->battery->update();
    this->range -= efficiency_constant;
    ui->range->display(uint8_t(range));

    check_range();
  }
}

uint8_t Battery::get_battery() { return battery; }

uint8_t Battery::get_range() { return range; }

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
