#!/usr/bin/env bash
#
# Delade hjälpfunktioner för build_d64.sh och build_and_run.sh.

# Skriver in./input/day<dag>.txt som DAY<dag>.IN (SEQ) på angiven D64.
# Konverterar LF -> CR i processen, eftersom cc65:s textlägesfunktioner
# (fgets m.fl.) förväntar sig CR som radslut (CBM/PETSCII-konventionen),
# inte LF som vanliga Linux-textfiler använder. Gör ingenting om
# input-filen saknas.
write_input_seq() {
    local d64="$1"
    local dag="$2"
    local inputfile="./input/day${dag}.txt"
    local tmpfile

    if [ ! -f "$inputfile" ]; then
        return 0
    fi

    tmpfile=$(mktemp)
    tr '\n' '\r' < "$inputfile" > "$tmpfile"
    c1541 "$d64" -write "$tmpfile" "DAY${dag}.IN,s" > /dev/null
    rm -f "$tmpfile"
}
