#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>



int main()
{
    srand ( time ( NULL ) );
    int M, N, i, h, M1, N1, additionalVariation;
    printf ( "Enter length of array M and N: " );
    scanf ( "%i%i", &M, &N );
    printf ( "Enter number of line and column M and N: " );
    scanf ( "%i%i", &M1, &N1 );
    printf ( "M = %i, N = %i\n", M, N );
    int array [100][100];
    for ( i = 0; i < M; i++ )
    {
        for ( h = 0; h < N; h++ )
        {
            array [i][h] = i;
        }
    }
    for ( i = 0; i < M; i++ )
    {
        for ( h = 0; h < N; h++ )
        {
            printf ( "%i  ", i, h, array [i][h] );
        }
        printf("\n");
    }
   // if ( M == N  )
  //  {
    printf("m1 = %i, n1 = %i", M1, N1);
        for ( i = 0; i < M; i++ )
        {
            //if ( M1 > N1 && i == M1 )
           // {
           //     continue;
           // }
          // else if ( M1 < N1 && i == N1 )
           // {
           //     continue;
           // }
           // else if ( M1 == N1 && i == N1 )
          //  {
           //     continue;
           // }
            additionalVariation = array [M1][i];
            array [M1][i] = array [i][N1];
            array [i][N1] = additionalVariation;
        }


//    else if ( M > N )
   // {
        for ( i = 0; i < N; i++ )
        {
            additionalVariation = array [M1][i];
            array [M1][i] = array [i][N1];
            array [i][N1] = additionalVariation;
        }
        printf ( "__________\n" );
    for ( i = 0; i < M; i++ )
    {

        for ( h = 0; h < N; h++ )
        {
            printf ( "%i  ", i, h, array [i][h] );
        }
        printf("\n");
        getchar();
    return 0;
    }


    }













