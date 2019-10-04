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
    getch();
    return 0;
}
