#!/bin/bash

if [ -z "$1" ]; then
  echo "mete un numero tolai"
  exit 1
fi

num_folders=$1

for ((i=0; i<num_folders; i++))
do
  folder_name=$(printf "ex%02d" $i)
  mkdir -p "$folder_name"
done
echo "Se han creado $num_folders carpetas."
