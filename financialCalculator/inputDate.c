#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "inputDate.h"


void printTable ()
{
    int i, j;
    char string[] = "WORLDKLjnfkjsd fsdfsdjfns";
    for ( i = 0; i < 10; i++ )
    {
        //  printf("---------\n");
        printf ( "||%s", string );
        for ( j = 0; j < 5; j ++){
            printf("|       |");
          //  printf("");
        }
        printf("\n");
        printf ( "___________________________" );
        for (j = 0; j < 5; j++){
            printf("_________");
        }
        printf("\n");
    }
}

void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if(!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD c = { x, y };
	SetConsoleCursorPosition(h,c);
}

void cursorMoving (){
    printTable();
    int Keys, num1;
    int poz_x = 31;
    int poz_y = 0;
    gotoxy(poz_x,poz_y);
    while(1)
	{
    	Keys = getch();
    	switch (Keys)
    	{
    		case 77:
				poz_x+=9;
				gotoxy(poz_x,poz_y);
				break;
			case 75:
				poz_x-=9;
            	gotoxy(poz_x,poz_y);
            	break;
            case 72:
				poz_y-=2;
            	gotoxy(poz_x,poz_y);
            	break;
            case 80:
            	poz_y+=2;
            	gotoxy(poz_x,poz_y);
            	break;
            case 13:{
                scanf("%i", &num1);
                gotoxy(poz_x,poz_y);
                break;
            }
            case 27:{
                gotoxy(0,20);
                printf("Result = %i", num1);
                 return;
            }
		}
	}
}
