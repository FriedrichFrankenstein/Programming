#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void printArray ( int A [], int size )
{
    int i;
    for ( i = 0; i < size; i++ )
    {
        printf ( "Array [%i] = %i\n", i, A [i] );
    }
    printf ( "\n" );
}

void sortArrayMax ( int a[], int size )
{
    int index, j, i, temp;
    for ( j = 0; j < 4; j++ )
    {
        index = j;
        for ( i = j + 1; i < 5; i++ )
        {
            if ( a[index] < a [i] )
                index = i;
        }
        temp = a [index];
        a [index] = a [j];
        a [j] = temp;
        pri
    }
}
void sortArrayMin ( int a[], int size )
{
    int index, j, i, temp;
    for ( j = 0; j < 4; j++ )
    {
        index = j;
        for ( i = j + 1; i < 5; i++ )
        {
            if ( a[index] > a [i] )
                index = i;
        }
        temp = a [index];
        a [index] = a [j];
        a [j] = temp;
    }
}


int main()
{
    int a [5] = {5, 8, 3, 9, 7};
    sortArrayMax ( a, 5 );
    printArray ( a, 5 );
    sortArrayMin ( a, 5 );
    printArray ( a, 5 );
    return 0;
}
