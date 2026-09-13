#!/usr/bin/env bash

if [ -z $1 ] || [ -z $2 ]; then
    echo "Användning: $0 <dag> <del>, exempel: $0 1 2 (för dag 1 del 2)."
    exit 1
fi
dag="$1"
del="$2"
./build.sh $dag $del

# Hämta körtidsadressen för _main ur label-filen och sätt brytpunkten
# direkt på den adressen. Vice's -initbreak stannar då exekveringen
# exakt vid _main, innan något av programmet hunnit köra.
lblfil="./bin/day${dag}-${del}.lbl"
mainaddr=$(grep '\._main$' "$lblfil" | head -1 | awk '{print $2}')
if [ -z "$mainaddr" ]; then
    echo "Kunde inte hitta _main i $lblfil"
    exit 1
fi

x64sc -keepmonopen -autostart "./bin/day${dag}-${del}.prg" -initbreak "0x${mainaddr}" > /dev/null 2>&1 &
