#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct
{
    char name [20];
    char city [20];
    int place;
} Club;



int main()
{
    Club teamsA [7];
    char teams [][30] = {"Ludogorec", "Dunav", "Beroe", "Beroe", "Cherno More", "Lokomotiv", "Etyr"};
    char towns [][30] = {"Razgrad", "Ruse", "Stara Zagora", "Sofia", "Varna", "Plowdyv", "Veliko Tyrnovo"};
    int i;
    for ( i = 0; i < 7; i++ )
    {
        strcpy ( ( teamsA + i )->name, teams[i] );
        strcpy ( ( teamsA + i )->city, towns[i] );
        (teamsA + i)->place = i;
    }
    for (i = 6; i >= 0; i--){
         printf ( "%s %s %i\n",( teamsA + i )->name, ( teamsA + i )->city,  (teamsA + i)->place );
    }
    getch();
    return 0;
}