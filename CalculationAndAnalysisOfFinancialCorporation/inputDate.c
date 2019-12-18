#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include "inputDate.h"
#include "finCalculations.h"
#include "outputDate.h"



void crateNewFirma ( Row *rows, int years, int firstYear, float **result )
{
    char nameCompany [100];
    FILE *output = fopen ( "listCompanies.dat", "ab" );
    if ( output == NULL )  		// якщо файл не існує -
    {
        printf ( "Файл з таким іменем відсутній" );
        getchar();
        return;
    }
    printf ( "Введіть назву підприємтсва (без пробілів та англійською мовою): " );
    scanf ( "%s", nameCompany );
    strcat ( nameCompany, ".dat" );
    fwrite ( nameCompany, sizeof ( char ), 100, output );
    fclose ( output );
    system ( "cls" );
    printTable ( years, firstYear );
    cursorMoving ( rows, years );
    createAvarage ( rows, years );
    saveData ( rows, years, firstYear, nameCompany );
    fclose ( output );
}

void printTable ( int years, int firstYear )
{
    int i, j;
    FILE *input = fopen ( "rowsName.dat", "rb" );
    if ( input == NULL )  		// якщо файл не існує -
    {
        printf ( "Файл з таким іменем відсутній" );
        getchar();
        return;
    }
    char string[100];
    printf ( "БАЛАНС\n" );
    printf ( "|%-97s", "Стаття" );
    for ( j = 0; j < years; j ++ )
    {
        printf ( "|            %i                |", firstYear + j );
    }
    printf ( "\n" );
    printf ( "                                                                                                  " );
    for ( j = 0; j < years; j ++ )
    {
        printf ( "__________________________________" );
    }
    printf ( "\n" );
    printf ( "                                                                                                  " );
    for ( j = 0; j < years; j ++ )
    {
        printf ( "|Початок періоду|" );
        printf ( "|Кінець періоду |" );
    }
    printf ( "\n" );
    printf ( "___________________________________________________________________________________________________" );
    for ( j = 0; j < years * 2; j++ )
    {
        printf ( "_________________" );
    }
    printf ( "\n" );
    printf ( "___________________________________________________________________________________________________" );
    for ( j = 0; j < years * 2; j++ )
    {
        printf ( "_________________" );
    }
    printf ( "\n" );
    for ( i = 0; i < 102; i++ )
    {
        fread ( string, sizeof ( char ), 100, input );
        printf ( "|%-97s", string );
        for ( j = 0; j < years * 2; j ++ )
        {
            printf ( "|               |" );
        }
        printf ( "\n" );
        printf ( "___________________________________________________________________________________________________" );
        for ( j = 0; j < years * 2; j++ )
        {
            printf ( "_________________" );
        }
        printf ( "\n" );
    }
    printf ( "\n\nЗВІТ ПРО ФІНАНСОВИЙ РЕЗУЛЬТАТ\n\n" );
    printf ( "|%-97s", "Стаття" );
    for ( j = 0; j < years; j ++ )
    {
        printf ( "|      %i     |", firstYear + j );
    }
    printf ( "\n" );
    printf ( "___________________________________________________________________________________________________" );
    for ( j = 0; j < years; j++ )
    {
        printf ( "_________________" );
    }
    printf ( "\n" );
    printf ( "___________________________________________________________________________________________________" );
    for ( j = 0; j < years; j++ )
    {
        printf ( "_________________" );
    }
    printf ( "\n" );
    for ( ; i < 161; i++ )
    {
        fread ( string, sizeof ( char ), 100, input );
        printf ( "|%-97s", string );
        for ( j = 0; j < years; j ++ )
        {
            printf ( "|               |" );
        }
        printf ( "\n" );
        printf ( "___________________________________________________________________________________________________" );
        for ( j = 0; j < years; j++ )
        {
            printf ( "_________________" );
        }
        printf ( "\n" );
    }
    fclose ( input );
}

void gotoxy ( int x, int y )
{
    static HANDLE h = NULL;
    if ( !h )
        h = GetStdHandle ( STD_OUTPUT_HANDLE );
    COORD c = { x, y };
    SetConsoleCursorPosition ( h, c );
}

void cursorMoving ( Row *rows, int years )
{
    int Keys, x, y, tab = 0, *table = &tab;
    int *poz_x = &x ;
    int *poz_y = &y ;
    *poz_x = 100;
    *poz_y = 6; //6
    gotoxy ( *poz_x, *poz_y );
    while ( 1 )
    {
        Keys = getch();
        switch ( Keys )
        {
        case 77:
            *poz_x += 17;
            checkCordinate ( poz_x, poz_y, table, years );
            break;
        case 75:
            *poz_x -= 17;
            checkCordinate ( poz_x, poz_y, table, years );
            break;
        case 72:
            *poz_y -= 2;
            checkCordinate ( poz_x, poz_y, table, years );
            break;
        case 80:
            *poz_y += 2;
            checkCordinate ( poz_x, poz_y, table, years );
            break;
        case 13:
        {
            checkCordinate ( poz_x, poz_y, table, years );
            catchDate ( *poz_x, *poz_y, rows, *table );
            checkCordinate ( poz_x, poz_y, table, years );
            break;
        }
        case 27:
        {
            system ( "cls" );
            return;
        }
        }
    }
}

void checkCordinate ( int* poz_x, int* poz_y, int* table, int years )
{
    switch ( *poz_y )
    {
    case 210:
    {
        *table = 1;
        * poz_y = 217;
        break;
    }
    case 215:
    {
        *table = 0;
        * poz_y = 208;
        break;
    }
    }
    if ( *table == 0 )
    {
        if ( *poz_x < 100 )
        {
            *poz_x = 100;
        }
        if ( *poz_x > ( years - 1 )  * 34 + 117 )
        {
            *poz_x = ( years - 1 ) * 34 + 117;
        }
        if ( *poz_y < 6 )
        {
            *poz_y = 6;
        }
    }
    if ( *table == 1 )
    {
        if ( *poz_x < 100 )
        {
            *poz_x = 100;
        }
        if ( *poz_x > ( years - 1 ) * 17 + 100 )
        {
            *poz_x = ( years - 1 ) * 17 + 100;
        }
        if ( *poz_y > 333 )
        {
            *poz_y = 333;
        }
    }
    gotoxy ( *poz_x, *poz_y );
}

void catchDate ( int x, int y, Row *rows, int table )
{
    if ( table == 0 )
    {
        if ( ( ( x - 100 ) / 17 ) % 2 == 0 )
        {
            ( rows + ( y - 6 ) / 2 )-> beginOfPeriod[ ( x - 100 ) / 34]  = funScanFloat();
        }
        else
        {
            ( rows + ( y - 6 ) / 2 )-> endOfPeriod[ ( ( x - 117 ) / 34 )] = funScanFloat();
        }
    }
    else if ( table == 1 )
    {
        ( rows + 102 + ( y - 217 ) / 2 )-> average[ ( x - 100 ) / 17] = funScanFloat();
    }
    else
    {
        printf ( "Не вірно введенні дані!\n" );
    }
}

void createAvarage ( Row *rows, int years )
{
    int i, j;
    for ( i = 0; i < 102; i++ )
    {
        for ( j = 0; j < years; j++ )
        {
            ( rows + i )->average [j] = ( ( rows + i )->endOfPeriod [j] + ( rows + i )->beginOfPeriod [j] ) / 2;
        }
    }
}

void saveData ( Row *rows, int years, int firstYear,  char* nameCompany )
{
    FILE *output = fopen ( nameCompany, "wb" );
    int i;
    if ( output == NULL )  		// якщо файл не існує -
    {
        printf ( "Файл з таким іменем відсутній" );
        getchar();
        exit ( 0 );
    }
    fwrite ( &years, sizeof ( int ), 1, output );
    fwrite ( &firstYear, sizeof ( int ), 1, output );
    for ( i = 0; i < 160; i++ )
    {
        fwrite ( ( rows + i ) ->average, sizeof ( float ), years, output );
    }
    fclose ( output );
}

void catchDateFile ( Row *rows, int* pYears, int* pfirstYear )
{
    char string [100];
    int i = 1, numberCompany;
    FILE *listCompanies = fopen ( "listCompanies.dat", "rb" );
    if ( listCompanies == NULL )  		// якщо файл не існує -
    {
        printf ( "Файл з таким іменем відсутній" );
        getchar();
        exit ( 0 );
    }
    while ( fread ( string, sizeof ( char ), 100, listCompanies ) != 0 )
    {
        printf ( "%i - %s\n", i, string );
        i++;
    }
    printf ( "Оберіть назву підприємства, яке Ви бажаєте обрати. Введіть його номер: " );
    numberCompany = funScanInt();
    fseek ( listCompanies, ( numberCompany - 1 ) * 100, SEEK_SET );
    fread ( string, sizeof ( char ), 100, listCompanies );
    fclose ( listCompanies );
    FILE *input = fopen ( string, "rb" );
    fread ( pYears, sizeof ( int ), 1, input );
    fread ( pfirstYear, sizeof ( int ), 1, input );
    system ( "cls" );
    for ( i = 0; i < 160; i++ )
    {
        ( rows + i ) ->average = ( float* ) calloc ( sizeof ( float ), *pYears );
        fread ( ( rows + i ) ->average, sizeof ( float ), *pYears, input );
        printf ( "%i  ", i );
    }
}

float funScanFloat ()
{
    char string [40];
    scanf ( "%s", string );
    float num = strtof ( string, NULL );
    if ( num < 1 )
    {
        return 0;
    }
    else
    {
        return num;
    }
}

int funScanInt ()
{
    char string [40];
    scanf ( "%s", string );
    float num = strtof ( string, NULL );
    if ( num < 1 )
    {
        return 0;
    }
    else
    {
        return num;
    }
}

