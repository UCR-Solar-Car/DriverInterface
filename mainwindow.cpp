#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->rightBlinker->setPixmap(QPixmap("C:/Users/justiny/Downloads/icons8-arrow-50 (3).png"));
    ui->LeftBlinker->setPixmap(QPixmap("C:/Users/justiny/Downloads/icons8-arrow-50_2.png"));
    renderBattery();
    ui->betterBattery->setPixmap(fullBattery);
    ui->BatteryPercent->setNum(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_IncreaseMPH_clicked()
{
    if(mph < 100){
        mph++;
        ui->MPH->display(mph);
    }
}


void MainWindow::on_DecreaseMPH_clicked()
{
    if(mph > 0){
        mph--;
        ui->MPH->display(mph);
    }
}


void MainWindow::on_ResetMPH_clicked()
{
    mph = 0;
    ui->MPH->display(mph);
}


void MainWindow::on_TurnRightBlinker_clicked()
{
   ui->rightBlinker->setPixmap(QPixmap("C:/Users/justiny/Downloads/icons8-arrow-50_1 (1).png"));

}


void MainWindow::on_TurOffBlinkers_clicked()
{
   ui->rightBlinker->setPixmap(QPixmap("C:/Users/justiny/Downloads/icons8-arrow-50 (3).png"));
}



void MainWindow::on_TurnOffLeftBlinker_clicked()
{
    ui->LeftBlinker->setPixmap(QPixmap("C:/Users/justiny/Downloads/icons8-arrow-50_2.png"));
}


void MainWindow::on_LeftBlinker_2_clicked()
{
    ui->LeftBlinker->setPixmap(QPixmap("C:/Users/justiny/Downloads/icons8-arrow-50_1 (3).png"));
}

void MainWindow::renderBattery(){

    int h = ui->betterBattery->height();
    int w = ui->betterBattery->width();
    QColor white = QColor(255, 255, 255);
    QColor batteryGreen = QColor(0,169,0);
    QColor softBlackBG = QColor(27,30,35);

    fullBattery = QPixmap(w, h);
    QPainter paint(&fullBattery);
    fullBattery.fill( softBlackBG);
    paint.setBrush(white);
    paint.setPen(white);
    //Parameters(shift right&left, shift up & down, change width, change height, rounded corners)
    paint.drawRoundedRect(w*.095+1, h*.38-38, 80,120,7,7);//Battery Case
    paint.setBrush(white);
    paint.drawRect(w*.095+30, h*.38-48, 20,14);// Left end of battery
    paint.setBrush(softBlackBG);
    paint.setPen(softBlackBG);
    paint.drawRect(w*.095+4, h*.38+7, 75,1);//Battery Line1
    paint.drawRect(w*.095+4, h*.38+45, 75,1);
    paint.setBrush(batteryGreen);
    paint.setPen(batteryGreen);
    paint.drawRect(w*.095+4, h*.38-25, 75,25);  //first rectangle
    paint.drawRect(w*.095+4, h*.38+14, 75,25);  //second rectangle
    paint.drawRect(w*.095+4, h*.38+52, 75,25);  //third rectangle
    paint.end();
}


void MainWindow::on_decreaseBattery_clicked()
{
    if(percentage >0){
        int h = ui->betterBattery->height();
        int w = ui->betterBattery->width();
        QColor white = QColor(255, 255, 255);
        QColor batteryGreen = QColor(0,169,0);
        QColor softBlackBG = QColor(27,30,35);

        fullBattery = QPixmap(w, h);
        QPainter paint(&fullBattery);
        fullBattery.fill( softBlackBG);
        paint.setBrush(white);
        paint.setPen(white);
        paint.drawRoundedRect(w*.095+1, h*.38-38, 80,120,7,7);//Battery Case
        paint.setBrush(white);
        paint.drawRect(w*.095+30, h*.38-48, 20,14);// Left end of battery
        paint.setBrush(softBlackBG);
        paint.setPen(softBlackBG);
        paint.drawRect(w*.095+4, h*.38+7, 75,1);//Battery Line1
        paint.drawRect(w*.095+4, h*.38+45, 75,1);
        paint.setBrush(batteryGreen);
        paint.setPen(batteryGreen);
        if(batteryHeight1 > 0.0){
            batteryHeight1 = batteryHeight1 - decrement;
            paint.drawRect(w*.095+4, h*.38-batteryHeight1, 75,batteryHeight1);
            paint.drawRect(w*.095+4, h*.38+14, 75,25);
            paint.drawRect(w*.095+4, h*.38+52, 75,25);
        }

        if(batteryHeight1 < 0 && batteryHeight2 > 0){
            Height2 = Height2 + decrement;
            batteryHeight2 = batteryHeight2 - decrement;
            paint.drawRect(w*.095+4, h*.38+Height2, 75,batteryHeight2);
            paint.drawRect(w*.095+4, h*.38+52, 75,25);
        }
        if(batteryHeight2 < 0 && batteryHeight3 > 0.5){
            Height3 = Height3 + decrement;
            batteryHeight3 = batteryHeight3 - decrement;
            paint.drawRect(w*.095+4, h*.38+Height3, 75,batteryHeight3);
        }

        paint.end();
        ui->betterBattery->setPixmap(fullBattery);
        percentage--;
        ui->BatteryPercent->setNum(percentage);
    }
}




void MainWindow::on_resetBattery_clicked()
{
    renderBattery();
    ui->betterBattery->setPixmap(fullBattery);
    ui->BatteryPercent->setNum(100);
    percentage = 100;
    batteryHeight1 = 25;
    batteryHeight2 = 25;
    batteryHeight3 = 25;
    Height2 = 14;
    Height3 = 52;
}


void MainWindow::on_increaseBattery_clicked()
{
   if(percentage < 100){
    int h = ui->betterBattery->height();
    int w = ui->betterBattery->width();
    QColor white = QColor(255, 255, 255);
    QColor batteryGreen = QColor(0,169,0);
    QColor softBlackBG = QColor(27,30,35);
                                                                                                                                                                                                                                                                                                                                                                                                                                                // put ur fat cock in my ass
    fullBattery = QPixmap(w, h);
    QPainter paint(&fullBattery);
    fullBattery.fill( softBlackBG);
    paint.setBrush(white);
    paint.setPen(white);
    paint.drawRoundedRect(w*.095+1, h*.38-38, 80,120,7,7);//Battery Case
    paint.setBrush(white);
    paint.drawRect(w*.095+30, h*.38-48, 20,14);// Left end of battery
    paint.setBrush(softBlackBG);
    paint.setPen(softBlackBG);
    paint.drawRect(w*.095+4, h*.38+7, 75,1);//Battery Line1
    paint.drawRect(w*.095+4, h*.38+45, 75,1);
    paint.setBrush(batteryGreen);
    paint.setPen(batteryGreen);
    if(batteryHeight3 < 0.5 && increaseHeight3 < 24.5){
        increaseHeight3 = increaseHeight3+decrement;
        lower3 = lower3 - decrement;
        paint.drawRect(w*.095+4, h*.38+52+lower3, 75,increaseHeight3);
    }
    if(increaseHeight3 > 24.5 && increaseHeight2 < 25){
        increaseHeight2 = increaseHeight2 + decrement;
        lower2 = lower2 - decrement;
        paint.drawRect(w*.095+4, h*.38+52+lower2, 75,increaseHeight2);
        paint.drawRect(w*.095+4, h*.38+52, 75,25);  //third rectangle
    }
    if(batteryHeight2 > 24.5 && increaseHeight1 < 25){
        batteryHeight1 = batteryHeight1 + decrement;
        paint.drawRect(w*.095+4, h*.38-25, 75,batteryHeight1);
        paint.drawRect(w*.095+4, h*.38+14, 75,25);
        paint.drawRect(w*.095+4, h*.38+52, 75,25);  //third rectangle
    }

    paint.end();
    ui->betterBattery->setPixmap(fullBattery);
    percentage++;
    ui->BatteryPercent->setNum(percentage);
   }
}

