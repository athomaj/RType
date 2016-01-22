#!/bin/bash

libs="libpthread-stubs
mesa-devel
libx11-devel
libxrandr-devel
libfreetype6-devel
glew-devel
libjpeg8-devel
libsndfile-devel
openal-devel
cmake
g++
libudev-devel"

command -v zypper >/dev/null 2>&1 || {
    echo "Command 'zypper' not found. You need to install libs yourself. Libs to install:"
    for lib in $libs
    do
	echo "=> $lib"
    done
    exit 1
}

sudo zypper update

for lib in $libs
do
    sudo zypper install $lib
    [ $? == 100 ] && echo "ERROR: Impossible to install $lib" && exit 1
done

exit 0