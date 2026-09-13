#!/usr/bin/env bash
#
# Bygger samtliga day<dag>-<del>.c och paketerar alla .prg-filer, plus
# tillhörande input-filer (input/day<dag>.txt), i en gemensam D64-avbild.
# Avbilden kan sedan kopieras rakt av till Kung Fu Flash 2:ans SD-kort och
# köras på riktig hårdvara - inget behöver bakas in i källkoden/binären.
#
# Ett program läser sin input via t.ex.
#   FILE *f = fopen("DAY1.IN", "r");
# (se read_input_file() i template.c).

set -euo pipefail

d64="./bin/aoc2015.d64"

rm -f "$d64"
c1541 -format "aoc2015,15" d64 "$d64"

declare -A input_written

for src in $(ls day*-*.c 2>/dev/null | sort -V); do
    base="${src%.c}"          # day1-1
    daydel="${base#day}"      # 1-1
    dag="${daydel%-*}"        # 1
    del="${daydel#*-}"        # 1

    ./build.sh "$dag" "$del"

    cbmname=$(echo "$base" | tr '[:lower:]' '[:upper:]')   # DAY1-1
    c1541 "$d64" -write "./bin/${base}.prg" "$cbmname"

    inputfile="./input/day${dag}.txt"
    if [ -f "$inputfile" ] && [ -z "${input_written[$dag]:-}" ]; then
        c1541 "$d64" -write "$inputfile" "DAY${dag}.IN,s"
        input_written[$dag]=1
    fi
done

c1541 "$d64" -list

echo
echo "Klart: $d64"
echo "Kopiera filen till KFF2:ans SD-kort för att köra på fysisk maskin."
