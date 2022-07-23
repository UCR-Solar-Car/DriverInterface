#include "ui_mainwindow.h"
#include <QFile>
#include <QWidget>
#include <QApplication>

class Background : public QObject {

  Q_OBJECT

  public:
    Background();
    void darkTheme();
};
