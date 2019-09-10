#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct
{
    char name [20];
    char city [20];
    int place;
    int score;
} Club;



int main()
{
    char teams [][30] = {"Ludogorec", "Dunav", "Beroe", "Beroe", "Cherno More", "Lokomotiv", "Etyr", "Neftohimik", "Botev", "Slavia"};
    char towns [][30] = {"Razgrad", "Ruse", "Stara Zagora", "Sofia", "Varna", "Plowdyv", "Veliko Tyrnovo", "Burgas","Plowdyv", "Sofia"};
    int i, n, j, max, place;
    Club temp;
    do{
    printf("Enter number of clubs for reading: ");
    scanf("%i", &n);
    } while (n < 1|| n > 10);
    Club *teamsA  = (Club*) calloc(sizeof(Club), n);
    for ( i = 0; i < n; i++ )
    {
        strcpy ( ( teamsA + i )->name, teams[i] );
        strcpy ( ( teamsA + i )->city, towns[i] );
        printf("Enter value of score for %s: ", ( teamsA + i )->name);
        scanf("%i", &( teamsA + i )->score);
       // printf ( "%s %s %i\n",( teamsA + i )->name, ( teamsA + i )->city,  (teamsA + i)->place );
    }
    for (i = 0; i < n; i++){
        place = i;
        for (j = i + 1; j < n; j++){
            if (( teamsA + j )->score > ( teamsA + place )->score){
                place = j;
            }
               //printf("TRUE");
        }
        temp = *( teamsA + place );
        *( teamsA + place ) = *( teamsA + i );
        *( teamsA + i ) = temp;

    }
    for (i = 0; i < n; i++){
        (teamsA + i)->place = i + 1;
        printf("Place - %i; Name - %s; city - %s; score - %i\n", ( teamsA + i )->place, ( teamsA + i )->name, ( teamsA + i )->city,  (teamsA + i)->score);
    }
    free(teamsA);
    getch();
    return 0;
}

