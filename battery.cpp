#include "battery.h"

Battery::Battery() : battery(100) { }

void Battery::setup(Ui::MainWindow *ui, uint16_t height, uint16_t width) {
  this->ui = ui;
  ui->battery->setValue(battery);
  range = battery * efficiency_constant;
  ui->range->display(float(range));

  ui->battery->resize(width * 10 / 100, height * 30 / 100);
  ui->range_label->resize(width * 15 / 100, height * 8 / 100);
  ui->range->resize(width * 15 / 100, height * 5 / 100);
  ui->low_battery_label->resize(width * 10 / 100, width * 10 / 100);

  uint16_t battery_height = ui->battery->height();
  uint16_t battery_width = ui->battery->width();

  ui->battery->move(width * 20 / 100, height * 50 / 100 - battery_height / 2);
  ui->range_label->move(ui->range_label->x(), ui->range_label->y() - ui->range->height());
  ui->low_battery_label->move((width - (width * ICON_COUNT) / 10) / 2 +(ui->low_battery_label->width() * LOW_BATTERY_WARNING_ICON), 0);
  ui->range->move(width - width * 90 / 100 + ui->range_label->width(), height - height * 15 / 100 - ui->range_label->height());
  ui->battery_line_1->resize(battery_width, 1);
  ui->battery_line_2->resize(battery_width, 1);
  ui->battery_line_3->resize(battery_width, 1);
  ui->battery_line_4->resize(battery_width, 1);

  uint16_t battery_x = ui->battery->x();
  uint16_t battery_y = ui->battery->y();

  ui->battery_line_1->move(battery_x, battery_y + battery_height / SECTION_COUNT * 1);
  ui->battery_line_2->move(battery_x, battery_y + battery_height / SECTION_COUNT * 2);
  ui->battery_line_3->move(battery_x, battery_y + battery_height / SECTION_COUNT * 3);
  ui->battery_line_4->move(battery_x, battery_y + battery_height / SECTION_COUNT * 4);

  low_battery = QPixmap(":/icons/low-battery.png");
  ui->low_battery_label->setText("");

  ui->battery_label->resize(width * 10 / 100, width * 10 / 100);
  ui->battery_label->move((width - (width * ICON_COUNT) / 10) / 2 +(ui->battery_label->width() * BATTERY_WARNING_ICON), 0);

  battery_fault = QPixmap(":/icons/battery.png");
  this->ui->battery_label->setText("");
}

void Battery::increase_battery(uint8_t val) {
  if (battery < 100) {
    battery += val;
    ui->battery->setValue(battery);
    ui->battery->update();
    range += efficiency_constant;
    ui->range->display(uint8_t(range));
    check_range();
  }
}

void Battery::decrease_battery(uint8_t val) {
  if (battery > 1) {
    battery -= val;
    ui->battery->setValue(battery);
    ui->battery->update();
    range -= efficiency_constant;
    ui->range->display(uint8_t(range));
    check_range();
  }
}

uint8_t Battery::get_battery() { return battery; }

uint8_t Battery::get_range() { return range; }

void Battery::on(warnings warning) {
  if (warning == LOW_BATTERY) {
    ui->low_battery_label->setPixmap(low_battery);
  } else if (warning == BATTERY_FAULT) {
    ui->battery_label->setPixmap(battery_fault);
  }
}

void Battery::off(warnings warning) {
  if (warning == LOW_BATTERY) {
    ui->low_battery_label->setText("");
  }
  if (warning == BATTERY_FAULT) {
    ui->battery_label->setText("");
  }
}

void Battery::check_range() {
  if (get_range() <= 30)
    on(LOW_BATTERY);
  else
    off(LOW_BATTERY);
}
