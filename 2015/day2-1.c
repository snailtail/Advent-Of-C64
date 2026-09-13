#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Input ligger som en include - C64:an beter sig inte när man ska läsa in från fil - det verkar ställa till det så att strtok() eller freads() inte funkar som de ska sen.
#include "day2.h"
const char testinput1[]="2x3x4";
const int testresult1=58;

long solve(char* data)
{
    char* line;
    char* p;
    int l, w, h;
    long sum=0;
    long packagesum=0;

    int area_lw;
    int area_wh;
    int area_hl;
    int smallest;

    line = strtok(data, "\n");
    while (line != NULL)
    {
        packagesum=0;
        // Parse till int, skippar från första x och resten
        l = atoi(line);
        
        // hitta pekare till första x i strängen
        p = strchr(line, 'x');
        p++;

        // konvertera resten till integer (struntar i allt från och med nästa x
        w = atoi(p);
        
        // hitta andra x:et - ja första x:et från nuvarande pekareposition då
        p = strchr(p, 'x');
        p++;
        // Konvertera resten till integer
        h = atoi(p);

        // Find the surface area of the box, which is 2*l*w + 2*w*h + 2*h*l. 
        // The elves also need a little extra paper for each present: the area of the smallest side.
        packagesum += (2 * l * w);
        packagesum += (2 * w * h);
        packagesum += (2 * h * l);
        // Räkna ut vilken area som är minst

        area_lw = l * w;
        area_wh = w * h;
        area_hl = h * l;
        smallest = area_lw;

        if (area_wh < smallest) smallest = area_wh;
        if (area_hl < smallest) smallest = area_hl;
        packagesum += smallest;
        sum+=packagesum;
        line = strtok(NULL, "\n");
    }
    return sum;
}

int main(void)
{
    long result;

    printf("***************************************\n");
    printf("* github.com/snailtail/Advent-Of-C64\n");
    printf("* Advent of C64 \n");
    printf("* 2015\n");
    printf("* Day  2\n");
    printf("* Part 1\n");
    printf("***************************************\n\n");

    printf("\nTests:\n\n");
    result=solve(testinput1);
    printf("Test1: %s = %ld (borde vara %d)\n\n",testinput1, result, testresult1); 

    printf("\n\nSolution:\n\n");
    result = solve(input);
    printf("Del 1 lösning: %ld\n", result);
    return 0;
}
