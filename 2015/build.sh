#!/usr/bin/env bash

if [ -z $1 ] || [ -z $2 ]; then
    echo "Användning: $0 <dag> <del>, exempel: $0 1 2 (för dag 1 del 2)."
    exit 1
fi
dag="$1"
del="$2"

# Bygg binär, inklusive label-fil.
cl65 -O -t c64 -g -Ln ./bin/day"$dag"-"$del".lbl -o ./bin/day"$dag"-"$del".prg day"$dag"-"$del".c
