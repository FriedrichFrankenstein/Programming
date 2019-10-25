#include <stdio.h>
#include <stdlib.h>
#include "print_Table.h"


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
