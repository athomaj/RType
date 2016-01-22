#!/bin/bash

SCRIPT=$(readlink -f "$0")
BASEDIR=$(dirname "$SCRIPT")

echo "==== Installing CSFML2.1 ===="
echo "=> Getting to installation dir..."
cd "$BASEDIR"
pwd

echo "=> Searching for an installed version..."
VEXIST=$(sudo find /lib* /usr/lib* /usr/local/lib* -name "libcsfml-*")
if [ "$VEXIST" != "" ];
then
    echo "WARNING: /!\=> A version of the CSFML is already installed."
    echo "Files found:"
    for file in $VEXIST
    do
	echo "-- $file"
    done
    read -n1 -r -p "Do you want to let me uninstall thoes files? (y/N)" resp
    CLEANOLD=0
    case $resp in
	[yY][eE][sS]|[yY])
	    CLEANOLD=1;;
	*)
	    ;;
    esac
    if [ $CLEANOLD == 1 ];
    then
	echo "=> Cleaning old version"
	for file in $VEXIST
	do
	    sudo rm -vrf $file
	done
    else
	echo "WARNING: If you dont uninstall the old version, it cound produce a conflict with the actual version."
    fi
fi

echo "=> Getting CSFML from git..."
git clone https://github.com/LaurentGomila/CSFML.git

echo "=> Generating the Makefile..."
mkdir CSFML/build
cd CSFML/build
cmake .. -DFREETYPE_INCLUDE_DIRS=/usr/include/freetype2/ -DCMAKE_MODULE_PATH="$BASEDIR/SFML/cmake/Modules/"
echo "=> Compiling the CSFML..."
make
[ $? != 0 ] && echo "    ERROR" && exit 1
echo "=> Installing the CSFML..."
sudo make install
[ $? != 0 ] && echo "     ERROR" && exit 1
cd "$BASEDIR"
echo "=> Executing ldconfig..."
sudo ldconfig
echo "==== CSFML installation done ===="