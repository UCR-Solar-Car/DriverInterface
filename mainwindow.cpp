#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    renderBatteryWarning();
    renderSolarWarning();
    renderMotorWarning();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::renderBatteryWarning()
{
    int h = ui->warnLabelBatteryHeat->height();
    int w = ui->warnLabelBatteryHeat->width();
    QColor softBlackBG = QColor(27,30,35);
    QColor batteryGreen = QColor(0,169,0);

    // RENDERS BATTERY WARNING LABEL
    warnBattery_ON = QPixmap(w, h);
    QPainter paint(&warnBattery_ON);
    warnBattery_ON.fill(softBlackBG);
    renderRhombus(paint, h, w, 5 ,0);
    paint.drawText(0,0,w,h,Qt::AlignRight | Qt::AlignVCenter,QString("FAULT           "));
    paint.setBrush(batteryGreen);
    paint.setPen(batteryGreen);
    paint.drawRoundedRect(w*.095, h*.38, 30,11,2,2);//Battery Case
    paint.setBrush(softBlackBG);
    paint.setPen(softBlackBG);
    paint.drawRect(w*.095+9, h*.38, 1,11);//Battery Line 1
    paint.drawRect(w*.095+19, h*.38, 1,11);//Battery Line 2
    paint.end();



    // RENDERS EMPTY BATTERY WARNING LABEL
    warnBattery_OFF = QPixmap(w,h);
    QPainter paintOff(&warnBattery_OFF);
    warnBattery_OFF.fill(softBlackBG);
    paintOff.end();
}

void MainWindow::renderSolarWarning(){
    int h = ui->warnLabelSolarHeat->height();
    int w = ui->warnLabelSolarHeat->width();
    QColor softBlackBG = QColor(27,30,35);
    QColor solarBlue = QColor(2, 102, 250);


    // RENDERS SOLAR WARNING LABEL
    warnSolar_ON = QPixmap(w,h);
    QPainter paintON(&warnSolar_ON);
    warnSolar_ON.fill(softBlackBG);
    renderRhombus(paintON, h, w, 5, -5);
    paintON.drawText(0,0,w,h,Qt::AlignRight | Qt::AlignVCenter,QString("FAULT         "));

    //renders solar array
    int xCord = 2;
    int yCord = 3;
    paintON.setBrush(solarBlue);
    paintON.setPen(solarBlue);
    for(int i = 8; i < 50; i = i + 10){//rows
        for(int j = 8; j < 30; j = j + 9){//columns
            solarBlue.setHsv(210+i/3-j/3.4,230,240-i/3);// color gradient
            paintON.setBrush(solarBlue);
            paintON.setPen(solarBlue);
            paintON.drawRoundedRect(xCord + i, yCord + j, 7,7,1,1);
        }
    }
    paintON.end();


    // RENDERS EMPTY SOLAR WARNING LABEL
    warnSolar_OFF = QPixmap(w,h);
    QPainter paintOFF(&warnSolar_OFF);
    warnSolar_OFF.fill(softBlackBG);
    paintOFF.end();

}

void MainWindow::renderMotorWarning(){
    int h = ui->warnLabelMotor->height();
    int w = ui->warnLabelMotor->width();
    QColor softBlackBG = QColor(27,30,35);

    // RENDERS MOTOR WARNING LABEL
    warnMotor_ON = QPixmap(w,h);
    QPainter paintON(&warnMotor_ON);
    warnMotor_ON.fill(softBlackBG);
    renderRhombus(paintON, h, w, 5, 4);
    paintON.drawText(0,0,w,h,Qt::AlignRight | Qt::AlignVCenter,QString("FAULT         "));

    // RENDERS EMPTY MOTOR WARNING LABEL
    warnMotor_OFF = QPixmap(w,h);
    QPainter paintOFF(&warnMotor_OFF);
    warnMotor_OFF.fill(softBlackBG);
    paintOFF.end();
}

void MainWindow::renderRhombus(QPainter &paint, int h, int w, int vOff, int hOff){//sets brush and pen to red after call
    QColor warningRed = QColor(255,0,0);
    paint.setBrush(warningRed);
    paint.setPen(warningRed);
    QVector<QPoint> rhombusPattern;
    for(int vOffset = vOff; vOffset < h; vOffset = vOffset + h - 15){
        for(int hOffset = hOff; hOffset < w+10; hOffset = hOffset + 16){
            rhombusPattern.append(QPoint(0 + hOffset, 0 + vOffset)); //top left corner
            rhombusPattern.append(QPoint(-4 + hOffset, 4 + vOffset)); //bottom left corner
            rhombusPattern.append(QPoint(4 + hOffset, 4 + vOffset)); //bottom right corner
            rhombusPattern.append(QPoint(8 + hOffset, 0 + vOffset)); //top right corner
            paint.drawPolygon(QPolygon(rhombusPattern));
            rhombusPattern.pop_back(); rhombusPattern.pop_back(); rhombusPattern.pop_back(); rhombusPattern.pop_back();
        }
    }

}


void MainWindow::on_batteryWarning_ON_clicked()
{
    ui->warnLabelBatteryHeat->setPixmap(warnBattery_ON);
}

void MainWindow::on_batteryWarning_OFF_clicked()
{
    ui->warnLabelBatteryHeat->setPixmap(warnBattery_OFF);
}

void MainWindow::on_solarWarning_ON_clicked()
{
    ui->warnLabelSolarHeat->setPixmap(warnSolar_ON);
}


void MainWindow::on_solarWarning_OFF_clicked()
{
    ui->warnLabelSolarHeat->setPixmap(warnSolar_OFF);
}


void MainWindow::on_motorWarning_ON_clicked()
{
    ui->warnLabelMotor->setPixmap(warnMotor_ON);
}


void MainWindow::on_motorWarning_OFF_clicked()
{
    ui->warnLabelMotor->setPixmap(warnMotor_OFF);
}

