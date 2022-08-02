#!/bin/sh 
cd /home/ucrsolarcar/UCRSolarCar2023/Driver-Interface-2022
git pull origin main
qmake DriverInterface.pro
make
./DriverInterface
