#!/bin/bash

echo "Mete un numero, sera el numero de carpetas creado desde ex00 asta ex0n"
echo ""

while true; do
	echo "Mete un numero valido porfa-pls:"
	read num_folders

	if [[ $num_folders =~ ^[0-9]+$ ]]; then
		echo "Se crearan $num_folders carpetas"
		echo ""
		break
	fi
done

SCRIPT_DIR=$(dirname "$(realpath "$0")")

for ((i=0; i<num_folders; i++))
do
  folder_name=$(printf "ex%02d" $i)
  mkdir -p "$folder_name"
  echo "Mete el nombre de la clse para $folder_name"
  echo ""
  read user_input
  echo ""
  cd $folder_name
  "$SCRIPT_DIR/Class_maker.sh" $user_input
  cd ..
done
echo "Se han creado $num_folders carpetas."
