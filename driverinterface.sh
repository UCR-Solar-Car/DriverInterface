#!/bin/sh 

for FILE in *; do
  if [[ (${FILE: -4} == ".cpp") || (${FILE: -2} == ".h") ]]; then 
    echo "$FILE is being formatted..." 
    clang-format -i -style=Google ./$FILE
  fi
done