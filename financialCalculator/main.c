#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "inputDate.h"
#include "finCalculations.h"
#include "outputDate.h"

//Основне меню програми, яке визначає режим її роботи
void menu ( Row *rows, float **result );
//виділення пам'яті
void getMemory ( int years, Row *rows );
//звільнення пам'яті
void freeMemory ( Row *rows, float **result );

int main ()
{
    SetConsoleCP ( 1251 );
    SetConsoleOutputCP ( 1251 );
    Row *rows = ( Row* ) calloc ( sizeof ( Row ), 160 );
    float **result = ( float** ) calloc ( sizeof ( float ), 23 );
    menu ( rows, result );
    freeMemory ( rows, result );
    getch();
    return 0;
}

void menu ( Row *rows, float **result )
{
    SetConsoleCP ( 1251 );
    SetConsoleOutputCP ( 1251 );
    int choice, years, firstYear, *pYears = &years, *pfirstYear = &firstYear;
    do
    {
        printf ( "Бажаєте додати нове підприємство? 1 - так; 2 - ні, бажаю використати вже додане." );
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
            else
            {
                getMemory ( years, rows );
                printf ( "Уведіть номер першого року: " );
                scanf ( "%i", &firstYear );
                if ( firstYear < 1000 || firstYear > 9999 )
                {
                    printf ( "Ви ввели не коректні дані.\n" );
                    continue;
                }
                crateNewFirma ( rows, years, firstYear );
            }
        }
        else if ( choice == 2 )
        {
            catchDateFile ( rows, pYears, pfirstYear );
        }
        else
        {
            printf ( "Ви ввели не коректні дані." );
            continue;
        }
        calculations ( years, result, rows );
        printOutTable ( years, firstYear, result );
        break;
    }
    while ( 1 );
}

void getMemory ( int years, Row *rows )
{
    int i;
    for ( i = 0; i < 160; i++ )
    {
        ( rows + i ) ->beginOfPeriod = ( float* ) calloc ( sizeof ( float ), years );
        ( rows + i ) ->endOfPeriod = ( float* ) calloc ( sizeof ( float ), years );
        ( rows + i ) ->average = ( float* ) calloc ( sizeof ( float ), years );
    }
}

void freeMemory ( Row *rows, float **result )
{
    int i;
    for ( i = 0; i < 160; i++ )
    {
        free ( ( rows + i ) ->beginOfPeriod );
        free ( ( rows + i ) ->endOfPeriod );
        free ( ( rows + i ) ->average );
    }
    free ( rows );
    rows = NULL;
    for ( i = 0; i < 22; i++ )
    {
        free ( * ( result + i ) ) ;
    }
    free ( result );
    result = NULL;
}
