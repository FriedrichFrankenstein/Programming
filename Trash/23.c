#include <stdio.h>
#include <conio.h>
#include <malloc.h>

int SizeOfNum ( int Num );
void Array ( int count );

int main ()
{
    int Num;
    int count;
    printf ( "Enter Num: " );
    scanf ( "%i", &Num );
    Array ( Num );
}

int SizeOfNum ( int Num )
{
    int count = 0;
    int n = Num, i;
    while ( n > 0 )
    {
        n /= 10;
        count++;
    }
    printf ( "count =  %i\n", count );
//  count = 0;
    return count;
}

void Array ( int Num )
{
    int Size = SizeOfNum ( Num );
    printf ( "Size = %i", Size );
    int*arr = ( int* ) malloc ( Size * sizeof ( int ) );
    printf ( "\nSize of array = %i", _msize ( arr )/4 );
}
