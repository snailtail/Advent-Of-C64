#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Läser in en hel fil (t.ex. "DAYx.IN" på device 8, se build_d64.sh) till
 * en malloc:ad, nolltermimerad buffert. Anroparen äger minnet och ska
 * free() det. Returnerar NULL om filen inte kunde öppnas.
 *
 * Ger dig hela filens innehåll som en sträng. Om pusslet vill ha en
 * array med rader istället får man stycka upp den (t.ex. med strtok
 * på '\n') efter att den lästs in - det är olika nog från dag till dag
 * att det inte finns någon generell lösning för det här.
 */
#define READ_CHUNK_SIZE 256

char* read_input_file(const char* filename)
{
    FILE* f;
    char* buf;
    size_t size;
    size_t n;

    f = fopen(filename, "r");
    if (!f) {
        return NULL;
    }

    buf = NULL;
    size = 0;
    for (;;) {
        buf = realloc(buf, size + READ_CHUNK_SIZE);
        n = fread(buf + size, 1, READ_CHUNK_SIZE, f);
        size += n;
        if (n < READ_CHUNK_SIZE) {
            break;
        }
    }
    fclose(f);

    buf = realloc(buf, size + 1);
    buf[size] = '\0';
    return buf;
}

int solve()
{
    return 0;
}

int main(void)
{
    char* input;

    printf("***************************************\n");
    printf("* github.com/snailtail/Advent-Of-C64\n");
    printf("* Advent of C64 \n");
    printf("* 2015\n");
    printf("* Day  ?\n");
    printf("* Part ?\n");
    printf("***************************************\n\n");

    printf("\nTests:\n\n");

    /* Byt "DAYx.IN" mot rätt filnamn för dagen, se build_d64.sh. */
    input = read_input_file("DAYx.IN");
    if (!input) {
        printf("Kunde inte oppna input-filen!\n");
        return 1;
    }

    printf("\n\nSolution:\n\n");

    free(input);
    return 0;
}

