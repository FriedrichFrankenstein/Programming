#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#define P 3.14

typedef struct
{
    int x;
    int y;
} Point;

float lengthLine ( Point first, Point second );

int main()
{
    Point first;
    Point second;
    printf ( "Enter x and y for first point: " );
    scanf ( "%i %i", &first.x, &first.y );
    printf ( "Enter x and y for second point: " );
    scanf ( "%i %i", &second.x, &second.y );
    printf("Result = %f",lengthLine(first, second) );
    getch();
    return 0;
}

float lengthLine ( Point first, Point second )
{
    float res;
    res = sqrt ( pow( ( second.x - first.x ),2) + pow( ( second.y - first.y ), 2 ));
    return res;
}
