#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int** func1 ( int n )
{
    int i;
    int **p;
    p = ( int** ) calloc ( sizeof ( int ), n );
    for ( i = 0; i < n; i++ )
    {
        * ( p + i ) = ( int* ) calloc ( 2, sizeof ( int ) );
    }
    return p;
}

void givev ( int n, int **p )
{
    srand ( time ( 0 ) );
    int i, j;
    for ( i = 0; i < n; i++ )
    {
        for ( j = 0; j < 2; j++ ){
            p[i][j] = 5;
        printf ( "%i ",  p[i][j] );
        }
    }
}


int main()
{
    int N;
    printf ( "Enter N " );
    scanf ( "%i", &N );
    printf ( "Enter N = %i\n ", N );
    int **pointer;
    pointer = func1 ( N );
    givev ( N, pointer );
    return 0;
}


