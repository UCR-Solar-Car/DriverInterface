#include "headers/background.h"
#include "mainwindow.h"

// #include <wiringPi.h>

#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
  // wiringPiSetup();
  Background b;
  b.dark_theme();
  QApplication a(argc, argv);
  MainWindow w;
  w.setFixedSize(800,480);
  w.show();
  return a.exec();
}
