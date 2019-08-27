#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void sort ( int arr[], int num[] );

void printArray ( int arr[], int num[] );

int main()
{
    srand ( time ( NULL ) );
    int arr[N], num[N];
    int i;
    for ( i = 0; i < N; i++ )
    {
        num[i] = i;
        arr[i] = rand() % 10;
    }
    printf ( "Origin arrays: \n" );
    printArray ( arr, num );
    sort ( arr, num );
    printf ( "\n\n\n\n" );
    printf ( "Sorted arrays: \n" );
    printArray ( arr, num );
    getch();
    return 0;
}

void sort ( int arr[], int num[] )
{
    int i, j, k, min = 1000, count;
    for ( i = 0; i < N; i++ )
    {
        for ( j = 0; j < N; j++ )
        {
            for ( k = 0; k <= i; k++ )
            {
                if ( arr[j] < min )
                {
                    if ( j == num[k] )
                    {
                        k++;
                        continue;
                    }
                    min = arr[j];
                    count = j;
                    printf ( "i = %i, j = %i, k = %i, min = %i, count = %i, num[k] = %i\n", i, j, k, min, count, num[k] );
                }

            }
        }
        num [i] = count;
        min = 1000;
    }
}

void printArray ( int arr[], int num[] )
{
    int i;
    for ( i = 0; i < N; i++ )
    {
        printf ( "%i  %i\n", num[i], arr[i] );
    }
}
