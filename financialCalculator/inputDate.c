#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include "inputDate.h"

void menu ( Row *rows )
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
            crateNewFirma ( rows, years, firstYear );
            break;
        }
        else if ( choice == 2 )
        {
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

void crateNewFirma ( Row *rows, int years, int firstYear )
{
    char nameCompany [100];
    FILE *output = fopen ( "listCompanies.txt", "a" );
    int i;
    for ( i = 0; i < 161; i++ )
    {
        (rows + i)->value = ( Values* ) calloc ( sizeof ( Values ), years );
    }
    printf ( "Введіть назву підприємтсва (без пробілів та англійською мовою): " );
    scanf ( "%s", nameCompany );
    strcat ( nameCompany, ".txt" );
    fprintf ( output, "%s\n", nameCompany );
    fclose ( output );
    clrscr();
    printTable (years, firstYear);
    cursorMoving ( rows, years );
}

void printTable (int years, int firstYear)
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
    for ( j = 0; j < years*2; j++ )
    {
        printf ( "_________________" );
    }
    printf ( "\n" );
    printf ( "___________________________________________________________________________________________________" );
    for ( j = 0; j < years*2; j++ )
    {
        printf ( "_________________" );
    }
    printf ( "\n" );
    for ( i = 0; i < 102; i++ )
    {
        fread ( string, sizeof ( char ), 100, input );
        printf ( "|%-97s", string );
        for ( j = 0; j < years*2; j ++ )
        {
            printf ( "|               |" );
        }
        printf ( "\n" );
        printf ( "___________________________________________________________________________________________________" );
        for ( j = 0; j < years*2; j++ )
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

void cursorMoving ( Row *rows, int years  )
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
           // catchDate ( *poz_x, *poz_y, rows, *table );
            break;
        }
        case 27:
        {
            clrscr();
            printf ( "Result = %i", 25 );
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
        if ( *poz_x > (years - 1)  * 34 + 117 )
        {
            *poz_x = (years - 1) * 34 + 117;
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
        if ( *poz_x > (years - 1) * 17 + 100 )
        {
            *poz_x = (years - 1) * 17 + 100;
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
//    if ( table == 0 )
//    {
//        if ( ( ( x - 100 ) / 17 ) % 2 != 0 )
//        {
//            scanf ( "%f", & ( rows + ( y - 6 ) / 2 )-> ( value + ( x - 100 ) / 17 )->beginOfPeriod );
//           scanf ( "%f", & (rows + x ) -> (value + y) ->beginOfPeriod );
//        }
//        else
//        {
//            scanf ( "%i", & ( rows + ( y - 6 ) / 2 )-> ( value + ( x - 100 ) / 17 )->endOfPeriod );
//        }
//    }
//    else if ( table == 1 )
//    {
//    }
//    else
//    {
//        printf ( "Не вірно введенні дані!\n" );
//    }
}

void clrscr()
{
    system ( "@cls||clear" );
}
