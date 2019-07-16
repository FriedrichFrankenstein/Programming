#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>
#include <string.h>



int main()
{
    int i;
    char temp;
    char signs [5] = ",.!?-";
    fpos_t position;
    FILE *fp = fopen ( "input.txt", "r+" );
    while ( 1 )
    {
        fgetpos ( fp, &position );
        fsetpos ( fp, &position );
        if ( fscanf ( fp, "%c", &temp ) == EOF ){
            break;
        }
        for ( i = 0; i < 5; i++ )
        {
            if ( temp == signs [i] )
            {
                fsetpos ( fp, &position );
                fprintf ( fp, "%c", ' ' );
                break;
            }
        }
    }
    printf("WIN!");
    fclose ( fp );
   // rename("newInput.txt",  "input.txt");
    getch();
    return 0;
}




