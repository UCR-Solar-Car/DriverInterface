#include "background.h"
#include "mainwindow.h"
//#include <wiringPi.h>

#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[]) {
  //wiringPiSetup();
  Background b;
  b.dark_theme();
  QApplication a(argc, argv);
  MainWindow w;
  //  QScreen* screen = QGuiApplication::primaryScreen();
  //  w.resize(1080,1920);
  w.setWindowState(Qt::WindowFullScreen);
  w.show();
  return a.exec();
}
