#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <math.h>

int main ()
{
    float number;
    char signOff;
    int i = 0, resultArray [2] = {}, flag = 0, counterFract = -2, counterInt = -1;
    char *string = calloc ( 1, sizeof ( char ) );
    printf ( "Enter number: " );
    while ( 1 )
    {
        string [i] = getch();
        if ( string [i] == 13 )
        {
            break;
        }
          if ( string[i] == 46 )
        {
            flag = 1;
        }
        printf ( "%c", string[i] );
        signOff =  string [i];
        string = realloc ( string, _msize ( string ) + 1 );
        if ( flag == 0 )
        {
            counterInt++;
        }
        else
        {
            counterFract++;
        }
        i++;
    }
    flag = 0;
    if ( counterFract > 2){
        resultArray [1] += 1;
    }
    for ( i = 0; i < _msize ( string ) - 1; i++ )
    {
        if ( string[i] == 46 )
        {
            flag = 1;
            continue;
        }
        if ( flag == 0 )
        {
            resultArray[flag] += ( string[i] - 48 ) * pow ( 10, counterInt );
            counterInt--;
        }
        else
        {
             if ( counterFract >= 2){
                resultArray [1] += 1;
            }
            //printf("\n%i\n", counterFract);
            resultArray[flag] += ( string[i] - 48 ) * pow ( 10, counterFract );
            int test = pow ( 10, counterFract);
           // printf("\nstring = %i, counter = %i \n", test, counterFract );
            counterFract--;
        }
    }
    //resultArray [1] += 1;
    free(string);
    printf ( "\nResult:\n%i\n%i", resultArray[0], resultArray[1] );
    getchar();
    return 0;
}
