#!/bin/bash

libs="libpthread-stubs0-dev
libgl1-mesa-dev
libx11-dev
libxrandr-dev
libfreetype6-dev
libglew1.5-dev
libjpeg8-dev
libsndfile1-dev
libopenal-dev
cmake
g++
libfreetype6-dev
libudev-dev"

command -v apt-get >/dev/null 2>&1 || {
    echo "Command 'apt-get' not found. You need to install libs yourself. Libs to install:"
    for lib in $libs
    do
	echo "=> $lib"
    done
    exit 1
}

sudo apt-get update

for lib in $libs
do
    sudo apt-get install $lib
    [ $? == 100 ] && echo "ERROR: Impossible to install $lib" && exit 1
done

exit 0