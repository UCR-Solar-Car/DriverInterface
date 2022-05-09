#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QString>
#include <QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_IncreaseButton_clicked();

    void on_DecreaseButton_clicked();

    void on_ResetButton_clicked();

    void on_IncreaseMPH_clicked();

    void on_DecreaseMPH_clicked();

    void on_ResetMPH_clicked();

    void renderOverheatWarning();
private:
    Ui::MainWindow *ui;
    int number = 100;
    int mph = 0;
    QPixmap warnOverheatBattery_ON;  //Stores image of warning label when ON  and (x,y) where its placed
    QPixmap warnOverheatBattery_OFF; //Stores image of warning label when OFF and (x,y) where its placed
};


#endif
