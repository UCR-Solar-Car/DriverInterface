#include "mainwindow.h"
#include "background.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  Background b;
  b.darkTheme();
  QApplication a(argc, argv);
  MainWindow w;
  w.setWindowState(Qt::WindowFullScreen);
  w.show();
  return a.exec();
}
