#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <stdio.h>

int main()
{
    srand (time(NULL));
    int a = 0, i, counter = 0;
    for ( ; ; )
    {
        a = -7 + rand() % 14;
        if ( a == 7){
            printf ("a = 1111111");
            break;
        }
       // printf ( "a = %i\n", a);
    }
    getch ();
    return 0;
}
