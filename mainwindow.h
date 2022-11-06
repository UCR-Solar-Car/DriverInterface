#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "headers/battery.h"
#include "headers/distance.h"
#include "headers/gears.h"
#include "headers/horn.h"
#include "headers/indicators.h"
#include "headers/lights.h"
#include "headers/motor.h"
#include "headers/speed.h"
#include "headers/tirepressure.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void gather_info();
  void update_speed();


private:
  Ui::MainWindow *ui;
  Battery battery;
  Indicators indicators;
  Lights lights;
  Motor motors;
  Speed speed;
  Distance distance;
  Horn horn;
  QTimer *timer;
  QTimer *timer2;
  //QTimer *timer3;
  bool blink;
  Gears gear;
  TirePressure tire;
  uint16_t seconds;
  uint16_t mseconds;
  //uint16_t xseconds;
};
#endif // MAINWINDOW_H
