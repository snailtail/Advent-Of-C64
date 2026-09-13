#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Input bakas in som en headerfil, t.ex. "day1.h" med innehållet
 *   char input[] = "...";
 * Generera raden från input/dayX.txt med:
 *   sed ':a;N;$!ba;s/\n/\\n/g' input/dayX.txt
 * och klistra in resultatet i headern. Headern committas ALDRIG till
 * git (se .gitignore, mönstret day*.h).
 *
 * OBS: läs inte input via fopen/fread/fgets - det finns ett
 * bibliotekssamspel-fel i cc65 där strtok(), sscanf() och upprepade
 * strchr()-anrop slutar fungera korrekt efter att fread()/fgets()
 * anropats någonstans i programmet, oavsett vilken buffert de sedan
 * körs på. Så länge input aldrig varit i kontakt med filläsning
 * fungerar strtok/strchr/atoi som förväntat.
 *
 * OBS 2: `input` är en `const char[]` inbränd i binären vid
 * kompilering, inte något som allokerats med malloc/realloc. Anropa
 * aldrig free(input) - det finns inget att frigöra.
 */
#include "dayX.h"

/*
 * Exempel på radvis parsning (se day2-1.c för ett fullständigt
 * exempel): strtok används bara på YTTERSTA nivån (radindelningen).
 * Ett nytt strtok()-anrop för att dela upp en enskild rad skriver
 * över den sparade positionen för den yttre loopen - använd istället
 * t.ex. strchr()/atoi() för att plocka ut värden ur varje rad.
 *
 *   char* line = strtok(input, "\n");
 *   while (line != NULL) {
 *       ...
 *       line = strtok(NULL, "\n");
 *   }
 */

int solve(char* data)
{
    return 0;
}

int main(void)
{
    printf("***************************************\n");
    printf("* github.com/snailtail/Advent-Of-C64\n");
    printf("* Advent of C64 \n");
    printf("* 2015\n");
    printf("* Day  ?\n");
    printf("* Part ?\n");
    printf("***************************************\n\n");

    printf("\nTests:\n\n");

    printf("\n\nSolution:\n\n");
    solve(input);

    return 0;
}
