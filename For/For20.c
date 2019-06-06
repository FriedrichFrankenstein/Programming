#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
    int N, i, factorial = 1, sum = 0, a;
    printf ( "Enter number: " );
    scanf ( "%i", &N );
    for ( i = 1; i <= N; i++ )
    {
        factorial *= i;
        sum += factorial;
    }
    printf ( "Sum of factorials %i", sum );
    getch ();
    return 0;
}
