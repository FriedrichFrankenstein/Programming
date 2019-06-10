#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void nullLocalMax ()
{
    //ƒан массив. ќбнулить все его локальные максимумы(числа больше своих  соседей).
    int lengthArray, i;
    printf ( "Enter array length: " );
    scanf ( "%i", &lengthArray );
    int array [100];
    for ( i = 0; i < lengthArray; i++ )
    {
        array[i] = rand() % 10;
        printf ( "Array1 [%i] = %i\n", i, array[i] );
    }
    for ( i = 0; i < lengthArray; i++ )
    {
        if ( array[i] > array[i - 1] && array [i] > array [i + 1] && i > 0 )
        {
            array [i] = 0;
        }
        if ( i == 0 && array [i] > array [i + 1] )
        {
            array [i] = 0;
        }
        if ( array[i] > array[i - 1] && i == lengthArray - 1 )
        {
            array [i] = 0;
        }
    }
    printf("_________________________________\n");
    for ( i = 0; i < lengthArray; i++ )
    {
        printf ("Array1 [%i] = %i\n", i, array[i] );
    }
}


int main()
{
    int choice;
    srand ( time ( NULL ) );
    nullLocalMax();
    /* while ( 1 )
     {
         printf ( "\nEnter which function do you want to see\n" );
         printf ( "1 -  nullLocalMax\n" );
         printf ( "2 - converselyMaxMin\n" );
         printf ( "3 - numberInArraysAscending\n" );
         printf ( "4 - sumOfPreviousNumbers\n" );
         printf ( "5 - positionMultiple3\n" );
         printf ( "6 - maxNumbersTimes\n" );
         printf ( "Another number is EXIT\n" );
         scanf ( "%i", &choice );
         switch ( choice )
         {
         case 1:
         {
             nullLocalMax();
             break;
         }
         case 2:
         {
             converselyMaxMin();
             break;
         }
         case 3:
         {
             numberInArraysAscending();
             break;
         }
         case 4:
         {
             sumOfPreviousNumbers();
             break;
         }
         case 5:
         {
             positionMultiple3();
             break;
         }
         case 6:
         {
             maxNumbersTimes();
             break;
         }
         default:
         {
             return 0;
         }
         }
     }*/
    getch ();
    return 0;
}
