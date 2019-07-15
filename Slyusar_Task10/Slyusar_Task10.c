#include <stdio.h>
#include <conio.h>
#include <string.h>


void amountOfOne ( char string [] );

void shortestWord ( char string [][20] );

int isPolindrom ( char string [] );

void maxVowelsInWord ( char string [][20] );

int main()
{
//    char stringTask1 [90] = "one, two, one hundred, twenty one, one thousand";
//    amountOfOne (stringTask1);
//    char stringTask2 [4][20] = {"responsibility", "charge", "liability", "amenability"};
//    shortestWord (stringTask2);
//    char stringTask3 [90];
//    gets ( stringTask3 );
//    printf ( "Result: %i",  isPolindrom ( stringTask3 ) );
    char stringTask4 [5][20] = {"animal", "load", "reason", "early", "dream"};
    maxVowelsInWord (stringTask4);
    getch ();
    return 0;
}

void amountOfOne ( char string [] )
{
    int counter = 0, i = 0;
    char *temp;
    while ( 1 )
    {
        temp = strstr ( string + i, "one" );
        if ( temp != 0 )
        {
            counter++;
            i = temp - string + 3;
            printf ( "i = %i\n", i );
        }
        else
        {
            break;
        }
    }
    if ( counter == 0 )
    {
        printf ( "1" );
    }
    else
    {
        printf ( "Amount of \"one\" in string = %i", counter );
    }
}

void shortestWord ( char string [][20] )
{
    int i, minLength = 10000;
    for ( i = 0; i < 4; i++ )
    {
        if ( minLength > strlen ( string[i] ) )
        {
            minLength = strlen ( string[i] );
        }
    }
    for ( i = 0; i < 4; i++ )
    {
        if ( strlen ( string[i] ) == minLength )
        {
            printf ( "%s", string[i] );
            break;
        }
    }
}

int isPolindrom ( char string [] )
{
    int i;
    for ( i = 0; i < strlen ( string ) / 2; i++ )
    {
        if ( string [i] >= 'A' && string [i] <= 'Z' )
        {
            string[i] += 32;
        }
        if ( string [i] == ' ' || string[strlen ( string ) - ( i + 1 )] == ' ' )
        {
            continue;
        }
        if ( string [i] != string[strlen ( string ) - ( i + 1 )] )
        {
            return 0;
        }
    }
    return 1;
}

void maxVowelsInWord ( char string [][20] )
{
    char vowels [] = {'a', 'e', 'i', 'o', 'u', 'y'};
    int i, j, k, maxVowels = 0;
    int amountVowels [5] = {};
    for ( i = 0; i < 5; i++ )
    {
        for ( j = 0; j < strlen ( string[i]); j++ )
        {
            for ( k = 0; k < 6; k++ )
            {
                if ( string [i][j] == vowels[k] )
                {
                    amountVowels [i] ++;
                    break;
                }
            }
        }
        if ( maxVowels < amountVowels[i]){
            maxVowels = amountVowels[i];
        }
    }
    printf("max vow = %i\n", maxVowels);
    for (i = 0; i < 5; i++){
        printf("%i\n", amountVowels[i]);
    }
}
