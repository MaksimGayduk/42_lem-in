#!/bin/sh

if [ $# -ne 2 ]; then
	echo "Usage: ./run [map] [interval in ms]"
	exit 1
fi

if [ ! -e $1 ]; then
	echo "The file doesn't exist"
	exit 1
fi

if  ./lem-in -e -p < $1; then
	./lem-in -e -p < $1 | ./visual/visual.py $2
fi
