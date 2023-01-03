#include "../headers/battery.h"

Battery::Battery() : battery_val(0) {}

void Battery::setup(QProgressBar *battery_ptr, QLabel *range_label_ptr, QLabel *low_battery_label_ptr, QLabel *battery_label_ptr, QLCDNumber *range_ptr, QLabel *distance_label_ptr, QFrame *battery_line_1_ptr, QFrame *battery_line_2_ptr, QFrame *battery_line_3_ptr, QFrame *battery_line_4_ptr, uint16_t height, uint16_t width)
{

  battery = battery_ptr;
  range_label = range_label_ptr;
  low_battery_label = low_battery_label_ptr;
  battery_label = battery_label_ptr;
  range = range_ptr;

  battery->setValue(battery_val);
  range_val = battery_val * EFFICIENCY_CONSTANT;
  range->display(float(range_val));

  battery->resize(width * 12 / 100, height * 35 / 100);
  range_label->resize(width * 30 / 100, height * 20 / 100);
  range->resize(width * 20 / 100, height *9 / 100);
  low_battery_label->resize(width * 10 / 100, width * 10 / 100);

  uint16_t battery_height = battery->height();
  uint16_t battery_width = battery->width();

  battery->move(width * 3 / 100, height * 50 / 100 - battery_height / 2);
  range_label->move(width * 0.02 - width * 0.03, distance_label_ptr->y() - range->height() - height * 5/100);
  low_battery_label->move((width - (width * ICON_COUNT) / 10) / 2 + (low_battery_label->width() * LOW_BATTERY_WARNING_ICON), height * 0.07);
  range->move(width * 0.17, height - height * 8 / 100 - range_label->height());
  battery_line_1_ptr->resize(battery_width - 10, 3);
  battery_line_2_ptr->resize(battery_width - 10, 3);
  battery_line_3_ptr->resize(battery_width - 10, 3);
  battery_line_4_ptr->resize(battery_width - 10, 3);

  uint16_t battery_x = battery->x();
  uint16_t battery_y = battery->y();

  battery_line_1_ptr->move(battery_x + 5, battery_y + battery_height / SECTION_COUNT * 1);
  battery_line_2_ptr->move(battery_x + 5, battery_y + battery_height / SECTION_COUNT * 2);
  battery_line_3_ptr->move(battery_x + 5, battery_y + battery_height / SECTION_COUNT * 3);
  battery_line_4_ptr->move(battery_x + 5, battery_y + battery_height / SECTION_COUNT * 4);

  low_battery = QPixmap(":/icons/low-battery.png");
  low_battery_label->setText(" ");

  battery_label->resize(width * 10 / 100, width * 10 / 100);
  battery_label->move((width - (width * ICON_COUNT) / 10) / 2 + (battery_label->width() * BATTERY_WARNING_ICON), height * 0.07);

  battery_fault = QPixmap(":/icons/battery.png");
  battery_label->setText(" ");
  on(LOW_BATTERY);
  on(BATTERY_FAULT);
}

void Battery::increase_battery(uint8_t val)
{
  if (battery_val < 100)
  {
    battery_val += val;
    battery->setValue(battery_val);
    battery->update();
    range_val += EFFICIENCY_CONSTANT;
    range->display(uint8_t(range_val));
    check_range();
  }
}

void Battery::decrease_battery(uint8_t val)
{
  if (battery_val > 1)
  {
    battery_val -= val;
    battery->setValue(battery_val);
    battery->update();
    range_val -= EFFICIENCY_CONSTANT;
    range->display(uint8_t(range_val));
    check_range();
  }
}

void Battery::reset(){
    battery_val = 100;
    battery->setValue(battery_val);
    battery->update();
    range_val += EFFICIENCY_CONSTANT;
    range->display(uint8_t(range_val));
    check_range();
    off(LOW_BATTERY);
    off(BATTERY_FAULT);
}

uint8_t Battery::get_battery() const { return battery_val; }

uint8_t Battery::get_range() const { return range_val; }

void Battery::on(warnings warning)
{
  if (warning == LOW_BATTERY)
  {
    low_battery_label->setPixmap(low_battery);
  }
  else if (warning == BATTERY_FAULT)
  {
    battery_label->setPixmap(battery_fault);
  }
}

void Battery::off(warnings warning)
{
  if (warning == LOW_BATTERY)
  {
    low_battery_label->setText(" ");
  }
  if (warning == BATTERY_FAULT)
  {
    battery_label->setText(" ");
  }
}

void Battery::check_range()
{
  if (get_range() <= 30)
    on(LOW_BATTERY);
  else
    off(LOW_BATTERY);
}
