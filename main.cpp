#include "background.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  Background b;
  b.dark_theme();
  QApplication a(argc, argv);
  MainWindow w;
  w.setWindowState(Qt::WindowFullScreen);
  w.show();
  return a.exec();
}
