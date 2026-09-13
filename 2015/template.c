#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

/*
 * OBS: kör inte strtok() på resultatet av read_input_file() (eller
 * någon annan buffert som fyllts via fread()) - det finns ett
 * bibliotekssamspel-fel i cc65 dar strtok() slutar hitta separatorer
 * helt efter att fread() anropats, oavsett buffert/separator. Använd
 * read_line() nedan för radvis inläsning istället.
 */

/*
 * Läser en rad från f in i buf (högst size-1 tecken + nolltermination),
 * och tar bort ett eventuellt radslutstecken (\r och/eller \n) i
 * slutet. OBS: input-filen på disken måste ha CR (\r) som radslut for
 * att fgets() ska hitta radbrytningarna - se write_input_seq() i
 * lib.sh, som konverterar LF -> CR automatiskt vid paketering.
 * Returnerar buf, eller NULL vid EOF/fel.
 */
char* read_line(FILE* f, char* buf, size_t size)
{
    size_t len;

    if (!fgets(buf, size, f)) {
        return NULL;
    }
    len = strlen(buf);
    while (len > 0 && (buf[len - 1] == '\r' || buf[len - 1] == '\n')) {
        buf[--len] = '\0';
    }
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

