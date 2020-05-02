#!bin/bash

git fetch --all
git pull --all

git pull origin master
git checkout master
git pull origin master

git merge rbabikow
git merge carson.su
git merge timeparsing
git merge main
git merge mohammad
git merge hfutch
git merge jhillStats

git push origin master
