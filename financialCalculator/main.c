#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "inputDate.h"



int main ()
{
    SetConsoleCP ( 1251 );
    SetConsoleOutputCP ( 1251 );
    Row *rows = (Row*) calloc(sizeof(Row), 161);
    menu (rows);
    system ( "cls" );
    int i;
    for ( i = 0; i < 161; i++){
        printf("Begin %f\n", (rows+i)->beginOfPeriod[0]);
        printf("End %f\n", (rows+i)->endOfPeriod[0]);
       // printf("Avarage %f\n", (rows+i)->avarage[0]);
    }
    getch();
    return 0;
}
