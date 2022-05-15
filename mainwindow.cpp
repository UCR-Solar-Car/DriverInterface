#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->batteryPercent->setNum(percentage);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_decreaseBattery_clicked()
{
    if(percentage > 0){
       percentage--;
    }

    ui->batteryPercent->setNum(percentage);
    if(height1 > 0 && percentage < 99){
        height1--;
        verticalShift1++;
        ui->batteryHeight1->setFixedHeight(height1);
        ui->batteryHeight1->setGeometry(670, 300+verticalShift1, 71, height1);
    }
    else if(height1 == 0 && height2 > 0){
        height2--;
        verticalShift2++;
        ui->batteryHeight2->setFixedHeight(height2);
        ui->batteryHeight2->setGeometry(670, 340+verticalShift2, 71, height2);
    }
    else if(height2 == 0 && height3 > 0){
        height3--;
        verticalShift3++;
        ui->batteryHeight3->setFixedHeight(height3);
        ui->batteryHeight3->setGeometry(670, 380+verticalShift3, 71, height3);
    }
    if(percentage <= 20){
        ui->lowBatteryWarning->setPixmap(QPixmap("C:/Users/justiny/Downloads/icons8-battery-alert-48.png"));
    }
    else{
        ui->lowBatteryWarning->setPixmap(QPixmap("blank"));
    }

}




void MainWindow::on_resetBattery_clicked()
{
    percentage = 100;
    ui->batteryPercent->setNum(percentage);
    height1 = 33;
    verticalShift1 = 0;
    ui->batteryHeight1->setFixedHeight(height1);
    ui->batteryHeight1->setGeometry(670, 300, 71, height1);

    height2 = 33;
    verticalShift2 = 0;
    ui->batteryHeight2->setFixedHeight(height2);
    ui->batteryHeight2->setGeometry(670, 340, 71, height2);

    height3 = 33;
    verticalShift3 = 0;
     ui->batteryHeight3->setFixedHeight(height3);
    ui->batteryHeight3->setGeometry(670, 380, 71, height3);
}


void MainWindow::on_increaseBattery_clicked()
{
    if(percentage < 100){
       percentage++;
    }

    ui->batteryPercent->setNum(percentage);
    if(height3 < 33){
        height3++;
        verticalShift3--;
        ui->batteryHeight3->setFixedHeight(height3);
        ui->batteryHeight3->setGeometry(670, 380+verticalShift3, 71, height3);
    }
    else if(height3 == 33 && height2 < 33){
        height2++;
        verticalShift2--;
        ui->batteryHeight2->setFixedHeight(height2);
        ui->batteryHeight2->setGeometry(670, 340+verticalShift2, 71, height2);
    }
    else if(height2 == 33 && height1 < 33){
        height1++;
        verticalShift1--;
        ui->batteryHeight1->setFixedHeight(height1);
        ui->batteryHeight1->setGeometry(670, 300+verticalShift1, 71, height1);
    }
    if(percentage <= 20){
        ui->lowBatteryWarning->setPixmap(QPixmap("C:/Users/justiny/Downloads/icons8-battery-alert-48.png"));
    }
    else{
        ui->lowBatteryWarning->setPixmap(QPixmap("blank"));
    }
}

