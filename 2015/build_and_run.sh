#!/usr/bin/env bash

if [ -z $1 ] || [ -z $2 ]; then
    echo "Användning: $0 <dag> <del>, exempel: $0 1 2 (för dag 1 del 2)."
    exit 1
fi
dag="$1"
del="$2"

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
source "${script_dir}/lib.sh"

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

# Bygg en liten D64 med bara den här dagens/delens prg (+ ev. delad
# input-fil), så att fopen("DAYx.IN", ...) fungerar likadant i Vice
# som på den fysiska maskinen via KFF2. Se build_d64.sh för den fulla
# paketeringen av samtliga dagar.
cbmname=$(echo "day${dag}-${del}" | tr '[:lower:]' '[:upper:]')  # DAY1-1
d64="./bin/day${dag}-${del}.d64"

rm -f "$d64"
c1541 -format "aoc2015,15" d64 "$d64" -write "./bin/day${dag}-${del}.prg" "$cbmname" > /dev/null
write_input_seq "$d64" "$dag"

x64sc -keepmonopen -autostart "${d64}:${cbmname}" -initbreak "0x${mainaddr}" > /dev/null 2>&1 &
