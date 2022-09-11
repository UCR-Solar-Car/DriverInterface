#!/bin/sh 

cd /home/ucrsolarcar/UCRSolarCar2023/Driver-Interface-2022

res=$(git pull origin main | grep Already)

if [[ ${res} =~ 'Already' ]]
then
    echo 'No updates have been made :)'
else
  done
  qmake DriverInterface.pro
  make
fi

./DriverInterface
