/*
 * (()) and ()() both result in floor 0.
((( and (()(()( both result in floor 3.
))((((( also results in floor 3.
()) and ))( both result in floor -1 (the first basement level).
))) and )())()) both result in floor -3.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "day1.h"

const char input1[]=")";
const char input2[]="()())";
const int answer1=1;
const int answer2=5;

int solve(const char* chars)
{
    size_t len = strlen(chars);
    size_t i=0;
    int sum=0;
    for(i=0; i<len;i++)
    {
        if(chars[i]=='(')
        {
            sum++;
        }
        else
        {
            sum--;
        }
        if(sum==-1)
        {
            return i+1;
        }
    }
    return 0;
}

int main(void)
{
    int result=0;
    printf("***************************************\n");
    printf("* github.com/snailtail/Advent-Of-C64\n");
    printf("* Advent of C64 \n");
    printf("* 2015\n");
    printf("* Day  1\n");
    printf("* Part 2\n");
    printf("***************************************\n\n");

    printf("\nTests:\n\n");

    result=solve(input1);
    printf("%s = %d (should be %d)\n", input1, result, answer1);
    result = solve(input2);
    printf("%s = %d (should be %d)\n", input2, result, answer2);
    printf("\n\nSolution:\n\n");
    result = solve(input);
    printf("Real input = %d\n", result);
}

