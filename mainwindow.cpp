#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QScreen>
#include <QTimer>
#include <wiringPi.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  ui->ucr_solar_car_logo->setPixmap(QPixmap(":/icons/logo.png"));
  QScreen *screen = QGuiApplication::primaryScreen();
  uint16_t screen_width = 800;
  uint16_t screen_height = 480;

  ui->stackedWidget->resize(screen_width, screen_height);
  ui->stackedWidget->move(0, 0);

  uint16_t center_width = screen_width / 2 - (0.6 * screen_width) / 2;
  uint16_t center_height = screen_height / 2 - (0.3 * screen_height) / 2;

  ui->ucr_solar_car_logo->resize(0.6 * screen_width, 0.3 * screen_height);
  ui->ucr_solar_car_logo->move(center_width, center_height);

  ui->ucr_solar_car_logo->setScaledContents(true);
  ui->stackedWidget->setCurrentIndex(1);

  indicators.setup(ui->left_indicator, ui->right_indicator, screen_height, screen_width);
  lights.setup(ui->day_lights, ui->night_lights, screen_width, screen_height);
  motors.setup(ui->motor_label, screen_width, screen_height);
  speed.setup(ui->speed, ui->mph, screen_height, screen_width);
  distance.setup(ui->distance_label, ui->distance, screen_height, screen_width);
  battery.setup(ui->battery, ui->range_label, ui->low_battery_label, ui->battery_label, ui->range, ui->distance_label, ui->battery_line_1, ui->battery_line_2, ui->battery_line_3, ui->battery_line_4, screen_height, screen_width);

  timer = new QTimer();
  blink = true;
  connect(timer, SIGNAL(timeout()), this, SLOT(gather_info()));
  timer->start(500);

  horn.setup(ui->horn_label, screen_width, screen_height);
  gear.setup(ui->park_label, ui->cruise_control, screen_height, screen_width);
  tire.setup(ui->front_left, ui->front_right, ui->back_left, ui->back_right,
             ui->front_left_lcd, ui->front_right_lcd, ui->back_left_lcd, ui->back_right_lcd, screen_height, screen_width);

  // timer2 = new QTimer();
  // connect(timer2, SIGNAL(timeout()), this, SLOT(update_speed()));
  // timer2->start(65);

  //  timer3 = new QTimer();
  //  connect(timer3, SIGNAL(timeout()),this, SLOT(update_tires()));
  //  timer3->start(500);

  move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());

  seconds = 0;
  // mseconds = 0;

  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::gather_info()
{

  if (seconds <= 9)
  {
    if (seconds == 9)
    {
      lights.reset();
      motors.reset();
      battery.reset();
      horn.horn_off();
      indicators.hazard_off();
      gear.cruise_off();
      speed.reset();
      distance.reset();
      battery.reset();
    }

    if (seconds >= 2 && seconds <= 8)
    {
      if (seconds % 2 == 0)
      {
        gear.reset();
      }
      speed.increase_speed(5);
      distance.increase_distance(5);
      battery.increase_battery(5);
    }

    if (indicators.get_right_indicator_state() == OFF && indicators.get_left_indicator_state() == ON && blink)
      indicators.left_on();

    if (indicators.get_right_indicator_state() == ON && indicators.get_left_indicator_state() == OFF && blink)
      indicators.right_on();

    if (indicators.get_right_indicator_state() == ON && indicators.get_left_indicator_state() == ON && blink)
      indicators.hazard_on();

    if (!blink)
      indicators.off();

    if (seconds == 2)
    {
      ui->stackedWidget->setCurrentIndex(0);
    }
    blink = !blink;
    seconds += 1;
  }
  else
  {
    uint16_t indicators_pin = analogRead(3);
    if (indicators_pin >= 0 && indicators_pin <= 256)
      indicators.hazard_off();
    else if (indicators_pin >= 257 && indicators_pin <= 512)
      indicators.left_on();
    else if (indicators_pin >= 513 && indicators_pin <= 768)
      indicators.right_on();
    else
      indicators.hazard_on();

    uint16_t gear_pin = analogRead(1);

    if (gear_pin >= 0 && gear_pin <= 256)
      gear.switch_gears(PARK);
    else if (gear_pin >= 257 && gear_pin <= 512)
      gear.switch_gears(DRIVE);
    else if (gear_pin >= 513 && gear_pin <= 768)
      gear.switch_gears(NEUTRAL);
    else
      gear.switch_gears(REVERSE);

    uint16_t battery_pin = digitalRead(5);
    if (battery_pin == 1)
    {
      battery.increase_battery(1);
    }
    else
    {
      battery.decrease_battery(1);
    }

    if (digitalRead(2))
      horn.horn_on();
    else
      horn.horn_off();
  }

  for (int i = 0; i <= 7; i++)
  {
    std::cout << "\"" << i << "\": " << i << ", ";
  }
  std::cout << std::endl;
}

// void MainWindow::update_speed()
// {
//   if (mseconds >= 0 && mseconds < 65)
//   {
//     speed.increase_speed(1);
//     distance.increase_distance(1);
//     battery.increase_battery(2);
//   }

//   if (mseconds == 75)
//   {
//     speed.reset();
//     distance.reset();
//     battery.reset();
//   }

//   mseconds += 1;
// }

// void MainWindow::update_tires(){
//     if (xseconds >= 0 && xseconds < 40){
//         tire.increasePressureNum();
//     }

//    xseconds += 1;

//    if (xseconds == 40){
//        tire.reset();
//    }

//}
