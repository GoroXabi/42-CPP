#!/bin/bash

if [ -z "$1" ] || [ -z "$2" ]; then
  echo "mete el nuevo mail y la shh del repo en el que estoy"
  exit 1
fi

mail=$1
repo=$2

cd

git clone $repo to_change

cd to_change

git config --global user.email $mail
git config user.email $mail

cd

pip install git-filter-repo

cd -

~/.local/bin/git-filter-repo --email-callback "return b\"$mail\""

git remote add origin $2

git push origin --force --all
git push origin --force --tags

cd

rm -fr to_change

#un goro estuvo aqui
