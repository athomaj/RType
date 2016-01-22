#!/bin/bash

echo "===================================================="
echo "======= Installation of SFML2.1 and CSFML2.1 ======="
echo "=======   Script made by AlexMog (moghra_a)  ======="
echo "=======     contact: moghra_a@epitech.eu     ======="
echo "===================================================="

OS=`uname -s`
REV=`uname -r`
MACH=`uname -m`
DIST=""

GetVersionFromFile()
{
    VERSION=`cat $1 | tr "\n" ' ' | sed s/.*VERSION.*=\ // `
}

if [ "${OS}" = "SunOS" ] ; then
    OS=Solaris
    ARCH=`uname -p` 
    OSSTR="${OS} ${REV}(${ARCH} `uname -v`)"
elif [ "${OS}" = "AIX" ] ; then
    OSSTR="${OS} `oslevel` (`oslevel -r`)"
elif [ "${OS}" = "Linux" ] ; then
    KERNEL=`uname -r`
    if [ -f /etc/redhat-release ] ; then
        DIST='RedHat'
        PSUEDONAME=`cat /etc/redhat-release | sed s/.*\(// | sed s/\)//`
        REV=`cat /etc/redhat-release | sed s/.*release\ // | sed s/\ .*//`
    elif [ -f /etc/SuSE-release ] ; then
        DIST="OpenSuse"
        REV=`cat /etc/SuSE-release | tr "\n" ' ' | sed s/.*=\ //`
    elif [ -f /etc/mandrake-release ] ; then
        DIST='Mandrake'
        PSUEDONAME=`cat /etc/mandrake-release | sed s/.*\(// | sed s/\)//`
        REV=`cat /etc/mandrake-release | sed s/.*release\ // | sed s/\ .*//`
    elif [ -f /etc/debian_version ] ; then
        DIST="Debian"
        REV=""

    fi
    OSSTR="${OS} ${DIST} ${REV}(${PSUEDONAME} ${KERNEL} ${MACH})"
fi

echo "OS found: ${OSSTR}, ${DIST}"

CLEANDIR=0

read -n1 -r -p "=> Do you want to clean the directory after installation? (Y/n)" clean
case $clean in
    [yY][eE][sS]|[yY])
	CLEANDIR=1;;
    *)
	;;
esac

echo ""

INSTALLDEP=0

read -n1 -r -p "=> Installer les dépendances? (Y/n)" installdep
case $installdep in
    [yY][eE][sS]|[yY])
	INSTALLDEP=1;;
    *)
	;;
esac

echo ""

SCRIPT=$(readlink -f "$0")
BASEDIR=$(dirname "$SCRIPT")

echo "==== Installing all the packages for CSFML and SFML ===="
cd "$BASEDIR"

echo "=> Setting rights..."
chmod +x ./lib-installers/*
chmod +x ./install-csfml.sh
chmod +x ./install-sfml.sh

if [ $INSTALLDEP == 1 ];
then
    echo "==== Installing dependencies ===="
    if [ -f "./lib-installers/${DIST}.sh" ];
    then
	./lib-installers/${DIST}.sh
    else
	libs="libpthread-stubs0-dev libgl1-mesa-dev libx11-dev libxrandr-dev libfreetype6-dev libglew1.5-dev libjpeg8-dev libsndfile1-dev libopenal-dev cmake  g++                                                                                                                 
libfreetype6-dev"
	echo "Your OS Version is not configured with that script."
	echo "Install thoes dependencies manually:"
	for lib in $libs
	do
	    echo "=> $lib"
	done
	echo "If you know then, create your own libinstaller in the lib-installer directory, and send it to me :)."
	echo "I will add it to the github. You can fork the project to add it: http://github.com/AlexMog/InstallSFMLScript/"
	echo "Aborting install"
	exit 1
    fi	
    [ $? != 0 ] && echo "    Aborting install." && exit 1
fi

./install-sfml.sh
[ $? != 0 ] && echo "Aborting SFML install." && exit 1
./install-csfml.sh
[ $? != 0 ] && echo "Aborting CSFML install." && exit 1

cd "$BASEDIR"

if [ $CLEANDIR == 1 ];
then
    echo "==== Cleaning installation directory ===="
    rm -irf "$BASEDIR"/CSFML
    rm -irf "$BASEDIR"/SFML
fi

echo "==== Installation ended with success ===="