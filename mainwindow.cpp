#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    renderOverheatBatteryWarning();
    renderOverheatWarning();
    ui->warnLabelBatteryHeat->setPixmap(warnOverheatBattery_OFF);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::renderOverheatBatteryWarning()
{
    //   warnOverheatBattery_ON
    //  warnOverheatBattery_OFF
    int h = ui->warnLabelBatteryHeat->height();
    int w = ui->warnLabelBatteryHeat->width();
    QColor warningRed = QColor(255,0,0);
    QColor softBlackBG = QColor(27,30,35);
    QColor batteryGreen = QColor(0,169,0);
    QColor softGray = QColor(211,211,211);
    QColor limeGreen = QColor(57,255,20);

    //rendering: warnOverheatBattery_ON
    warnOverheatBattery_ON = QPixmap(w, h);
    QPainter paint(&warnOverheatBattery_ON);
    warnOverheatBattery_ON.fill(softBlackBG);
    paint.setBrush(warningRed);
    paint.setPen(warningRed);
    QVector<QPoint> rhombusPattern;
    for(int vOffset = 5; vOffset < h; vOffset = vOffset + h - 15){
        for(int hOffset = 0; hOffset < w+10; hOffset = hOffset + 16){
            rhombusPattern.append(QPoint(0 + hOffset, 0 + vOffset)); //top left corner
            rhombusPattern.append(QPoint(-4 + hOffset, 4 + vOffset)); //bottom left corner
            rhombusPattern.append(QPoint(4 + hOffset, 4 + vOffset)); //bottom right corner
            rhombusPattern.append(QPoint(8 + hOffset, 0 + vOffset)); //top right corner
            paint.drawPolygon(QPolygon(rhombusPattern));
            rhombusPattern.pop_back(); rhombusPattern.pop_back(); rhombusPattern.pop_back(); rhombusPattern.pop_back();
        }
    }
    paint.drawText(0,0,w,h,Qt::AlignRight | Qt::AlignVCenter,QString("OVERHEAT     "));
    paint.setBrush(batteryGreen);
    paint.setPen(batteryGreen);
    paint.drawRoundedRect(w*.095, h*.38, 30,11,2,2);//Battery Case
    paint.setBrush(softBlackBG);
    paint.setPen(softBlackBG);
    paint.drawRect(w*.095+9, h*.38, 1,11);//Battery Line 1
    paint.drawRect(w*.095+19, h*.38, 1,11);//Battery Line 2
    paint.end();

    //rendering: warnOverheatBattery_OFF
    warnOverheatBattery_OFF = QPixmap(w,h);
    QPainter paintOff(&warnOverheatBattery_OFF);
    warnOverheatBattery_OFF.fill(softBlackBG);
//    paintOff.setBrush(limeGreen);
//    paintOff.drawRoundedRect(0,0,w,h,10,10);
//    paintOff.setBrush(softBlackBG);
//    paintOff.drawRoundedRect(5,5,w-10,h-10,10,10);
//    paintOff.setPen(limeGreen);
//    paintOff.drawText(0,0,w,h,Qt::AlignRight | Qt::AlignVCenter,QString("TEMPERATURE   "));
//    paintOff.setBrush(batteryGreen);
//    paintOff.setPen(batteryGreen);
//    paintOff.drawRoundedRect(w*.095, h*.38, 30,11,2,2);//Battery Case
//    paintOff.setBrush(softBlackBG);
//    paintOff.setPen(softBlackBG);
//    paintOff.drawRect(w*.095+9, h*.38, 1,11);//Battery Line 1
//    paintOff.drawRect(w*.095+19, h*.38, 1,11);//Battery Line 2
//    paintOff.end();
}

