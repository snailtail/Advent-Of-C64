#!/usr/bin/env bash

if [ -z $1 ] || [ -z $2 ]; then
    echo "Användning: $0 <dag> <del>, exempel: $0 1 2 (för dag 1 del 2)."
    exit 1
fi
dag="$1"
del="$2"
./build.sh $dag $del
x64sc -autostart "./bin/day${dag}-${del}.prg" > /dev/null 2>&1 &
