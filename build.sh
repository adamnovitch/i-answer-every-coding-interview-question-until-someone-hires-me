#!/bin/sh
if [ -z $1 ]; then echo "Input required!"; exit 1; fi
to_run=`echo $1 | sed 's/\..*//g'`
mkdir -p bin
gcc $1 -o bin/$to_run
./bin/$to_run
