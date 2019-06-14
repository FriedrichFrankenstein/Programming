#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define M 5
#define N 5

int main ()
{
    int i, j, Sum = 0;
    int SumArray[N] = {};
    int nMax = 0;
    int array[N][M] =
    {
        {2, 4, 6, 8, 10},
        {6, 3, 1, 5, 9},
        {7, 8, 10, 3, 1},
        {6, 2, 8, 3, 10},
        {11, 18, 3, 1, 2}
    };
    for ( i = 0; i < N; i++ )
    {
        for ( j = 0; j < N; j++ )
        {
            SumArray[i] += array[i][j];
            if ( SumArray [i] > SumArray[nMax] )
            {
                nMax = i;
            }
        }
    }
    printf ( "Number of line %i, value %i\n", nMax, SumArray[nMax] );
    for ( i = 0; i < N; i++){
        printf("SumArray [%i] = %i\n", i, SumArray[i]);
    }
    printf("\n\n");
    for ( i = 0; i < N; i++ )
    {
        for ( j = 0; j < M; j++ )
        {
            printf ( "array[%i][%i]-%i\n", i, j, array[i][j] );
        }
    }
}
