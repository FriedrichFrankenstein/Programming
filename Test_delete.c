#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX 80



//int main()
//
//{
//    getch();
//    return 0;
//}

int main () {
    int i, j;
    char **names = ( char ** ) calloc ( sizeof ( char ), N );
    for ( i = 0; i < N; i++ )
    {
        * ( names + i ) = ( char * ) calloc ( sizeof ( char ), 20 );
    }
    for ( i = 0; i < N; i++ )
    {
        for ( j = 0; j < N; j++ )
        {
            if ( places [j] == i + 1 )
            {
                strcpy ( * ( names + i ), teams [j] );
            }
        }
    }
    for ( i = 0; i < N; i++ )
    {
        free ( * ( names + i ) );
    }
    free ( names );
    return 0;
}
