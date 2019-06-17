#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <stdio.h>

int main()
{
    int num;
    char a;
    printf("Enter your number in one from number systems expect dec ( if you done press q to exit): ");
    while (1){
    a = getch();
    if ( a == 'q' || a == 'Q'){
        break;
    }
    num = a;
    if ( num > 47 && num < 58 )
    {
        num = a - 48;
        printf ( "%i", num );
    }
    else if ( num > 64 && num < 71 )
    {
        num = a - 55 ;
        printf ( "%i", num );
    }
    else if ( num > 96 && num < 103 )
    {
        num = a - 87 ;
        printf ( "%i", num );
    }
    else
    {
        printf ( "You typed wrong number!" );
    }
    }
    /*if (num > 64 ){
            num = num - 55;
      printf("%i", num  );
    } else{
        num = num - 48;
    printf("%i", num  );
    }*/
    getch ();
    return 0;
}
