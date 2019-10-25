#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include "outputDate.h"


void printOutTable ( int years, int firstYear, float **result )
{
    int i = 0, j;
    system ( "cls" );
    FILE *input = fopen ( "rowsOutName.dat", "rb" );
    if ( input == NULL )  		// якщо файл не існує -
    {
        printf ( "Файл з таким іменем відсутній" );
        getchar();
        return;
    }
    char string[100];
    printf ( "Результати розрахунків\n\n" );
    printf ( "|%-55s", "Стаття" );
    for ( j = 0; j < years; j ++ )
    {
        printf ( "|      %i     |", firstYear + j );
    }
    printf ( "\n" );
    printf ( "________________________________________________________" );
    for ( j = 0; j < years; j++ )
    {
        printf ( "_________________" );
    }
    printf ( "\n" );
    printf ( "________________________________________________________" );
    for ( j = 0; j < years; j++ )
    {
        printf ( "_________________" );
    }
    printf ( "\n" );
    for ( i = 0; i < 22; i++ )
    {
        fread ( string, sizeof ( char ), 100, input );
        printf ( "|%-55s", string );
        for ( j = 0; j < years; j ++ )
        {
            printf ( "|%-15.2f|", * ( * ( result + i ) + j ) ); //15  printf ( "|               |" ); //15
        }
        printf ( "\n" );
        printf ( "________________________________________________________" );
        for ( j = 0; j < years; j++ )
        {
            printf ( "_________________" );
        }
        printf ( "\n" );
    }
    fclose ( input );
}
