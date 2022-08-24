#!/bin/sh 

cd /home/ucrsolarcar/UCRSolarCar2023/Driver-Interface-2022

res=$(git pull origin main | grep Already)

if [[ ${res} =~ 'Already' ]]
then
  echo 'No updates have been made :)'
else
  for FILE in *; do
  if [[ (${FILE: -4} == ".cpp") || (${FILE: -2} == ".h") ]]; then 
    echo "$FILE is being formatted..." 
    clang-format -i -style=Google ./$FILE
  fi
done
  qmake DriverInterface.pro
  make
fi

./DriverInterface