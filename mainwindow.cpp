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

    ui->warnLabelBatteryHeat->setPixmap(warnBattery_OFF);
    ui->warnLabelSolarHeat->setPixmap(warnSolar_OFF);
    ui->warnLabelMotor->setPixmap(warnMotor_OFF);
    ui->dayLight->setPixmap(QPixmap(blankImgPath));
    ui->nightLight->setPixmap(QPixmap(blankImgPath));
    ui->LeftBlinker->setPixmap(QPixmap(leftBlinkPath_OFF));
    ui->rightBlinker->setPixmap(QPixmap(rightBlinkPath_OFF));
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
    QColor motorSymbol = QColor(255, 211, 13);
    int xOff = 5;
    int yOff = -2;

    // RENDERS MOTOR WARNING LABEL
    warnMotor_ON = QPixmap(w,h);
    QPainter paintON(&warnMotor_ON);
    warnMotor_ON.fill(softBlackBG);
    renderRhombus(paintON, h, w, 5, 4);
    paintON.drawText(0,0,w,h,Qt::AlignRight | Qt::AlignVCenter,QString("FAULT         "));
    paintON.setBrush(softBlackBG);
    paintON.setPen(motorSymbol);
    paintON.drawEllipse( 7+xOff, 17+yOff, 22, 22);
    paintON.drawEllipse( 8+xOff, 18+yOff, 20, 20);//big circle
    paintON.drawEllipse(39+xOff,14+yOff, 12, 12);
    paintON.drawEllipse(40+xOff,15+yOff, 10, 10);//small circle
    paintON.drawLine(8+10+xOff,17+yOff,40+5+xOff,14+yOff);
    paintON.drawLine(8+10+xOff,18+yOff,40+5+xOff,15+yOff);//top belt
    paintON.drawLine(8+10+xOff,19+yOff+20,40+5+xOff,15+10+yOff);
    paintON.drawLine(8+10+xOff,19+21+yOff,40+5+xOff,15+11+yOff);//bottombelt

    paintON.setBrush(motorSymbol);
    paintON.drawEllipse( 7+10+xOff, 17+5-1+yOff, 2, 2);//top point
    paintON.drawEllipse( 7+10+xOff, 17+15+1+yOff, 2, 2);//bottom point
    paintON.drawEllipse( 7+15+1+xOff, 17+10+yOff, 2, 2);//right point
    paintON.drawEllipse( 7+5-1+xOff, 17+10+yOff, 2, 2);//left point

    paintON.drawEllipse( 7+9+xOff, 17+9+yOff, 4, 4);//middle point big circle
    paintON.drawEllipse( 44+xOff, 19+yOff, 2, 2);//middle point small circle


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
   ui->rightBlinker->setPixmap(QPixmap(rightBlinkPath_ON));

}


void MainWindow::on_TurOffBlinkers_clicked()
{
   ui->rightBlinker->setPixmap(QPixmap(rightBlinkPath_OFF));
}



void MainWindow::on_TurnOffLeftBlinker_clicked()
{
    ui->LeftBlinker->setPixmap(QPixmap(leftBlinkPath_ON));
}


void MainWindow::on_LeftBlinker_2_clicked()
{
    ui->LeftBlinker->setPixmap(QPixmap(leftBlinkPath_OFF));
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
        ui->lowBatteryWarning->setPixmap(QPixmap(lowbatteryImgPath));
    }
    else{
        ui->lowBatteryWarning->setPixmap(QPixmap(blankImgPath));
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
        ui->lowBatteryWarning->setPixmap(QPixmap(lowbatteryImgPath));
    }
    else{
        ui->lowBatteryWarning->setPixmap(QPixmap(blankImgPath));
    }
}

void MainWindow::on_dayLightButton_clicked()
{
    ui->dayLight->setPixmap(QPixmap(daylightImgPath));
    ui->nightLight->setPixmap(QPixmap(blankImgPath));
}

void MainWindow::on_offButton_clicked()
{
    ui->dayLight->setPixmap(QPixmap(blankImgPath));
    ui->nightLight->setPixmap(QPixmap(blankImgPath));
}


void MainWindow::on_pushButton_clicked()
{
    ui->nightLight->setPixmap(QPixmap(nightlightImgPath));
    ui->dayLight->setPixmap(QPixmap(blankImgPath));
}

