#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include "inputDate.h"
#include "finCalculations.h"



void menu ( Row *rows, float **result )
{
    SetConsoleCP ( 1251 );
    SetConsoleOutputCP ( 1251 );
    int choice, years, firstYear;
    do
    {
        printf ( "Бажаєте створити додати нове підприємство? 1 - так; 2 - ні, бажаю використати вже додане." );
        scanf ( "%i", &choice );
        if ( choice == 1 )
        {
            printf ( "Уведіть кільскість досліджувальних років (максимум 3) : " );
            scanf ( "%i", &years );
            if ( years > 3 || years < 1 )
            {
                printf ( "Ви ввели не коректні дані.\n" );
                continue;
            }
            else if ( years == 1 )
            {
                printf ( "Уведіть номер першого року: " );
                scanf ( "%i", &firstYear );
                if ( firstYear < 1000 || firstYear > 9999 )
                {
                    printf ( "Ви ввели не коректні дані.\n" );
                    continue;
                }
                crateNewFirma ( rows, years, firstYear );
                break;
            }
            else
            {
                printf ( "Уведіть номер першого року: " );
                scanf ( "%i", &firstYear );
            }
            crateNewFirma ( rows, years, firstYear, result );
            break;
        }
        else if ( choice == 2 )
        {
            catchDateFile ( rows );
            break;
        }
        else
        {
            printf ( "Ви ввели не коректні дані." );
            continue;
        }
    }
    while ( 1 );
}

void crateNewFirma ( Row *rows, int years, int firstYear, float **result )
{
    char nameCompany [100];
    FILE *output = fopen ( "listCompanies.dat", "ab" );
    int i;
    for ( i = 0; i < 160; i++ )
    {
        ( rows + i ) ->beginOfPeriod = ( float* ) calloc ( sizeof ( float ), years );
        ( rows + i ) ->endOfPeriod = ( float* ) calloc ( sizeof ( float ), years );
        ( rows + i ) ->average = ( float* ) calloc ( sizeof ( float ), years );
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
    calculations ( years, result, rows );
}

void printTable ( int years, int firstYear )
{
    int i, j;
    FILE *input = fopen ( "rowsName.dat", "rb" );
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
            scanf ( "%f", & ( rows + ( y - 6 ) / 2 )-> beginOfPeriod[ ( x - 100 ) / 17] );
        }
        else
        {
            scanf ( "%f", & ( rows + ( y - 6 ) / 2 )-> endOfPeriod[ ( ( x - 100 ) / 17 ) - 1] );
        }
    }
    else if ( table == 1 )
    {
        scanf ( "%f", & ( rows + 101 + ( y - 217 ) / 2 )-> average[ ( x - 100 ) / 17] );
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
    fwrite ( &years, sizeof ( int ), 1, output );
    fwrite ( &firstYear, sizeof ( int ), 1, output );
    fwrite ( rows, sizeof ( Row ), 160, output );
    fclose ( output );
}

void catchDateFile ( Row *rows )
{
    char string [100];
    int i = 1, numberCompany;
    FILE *listCompanies = fopen ( "listCompanies.dat", "rb" );
    while ( fread ( string, sizeof ( char ), 100, listCompanies ) != 0 )
    {
        printf ( "%i - %s\n", i, string );
        i++;
    }
    printf("Оберіть назву підприємства, яке Ви бажаєте обрати. Введіть його номер: ");
    scanf("%i", &numberCompany);
    fseek(listCompanies, (numberCompany - 1) * 100, SEEK_SET);
    fread ( string, sizeof ( char ), 100, listCompanies );
    fclose(listCompanies);
    FILE *input = fopen(string, "rb");
    fread ( rows, sizeof ( Row ), 160, input );
}
