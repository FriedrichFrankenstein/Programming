#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>



int main()
{
    char *str;
    str = (char *) malloc (13);

    if (str == NULL){
        puts("WRONG!!");
    }else {
    strcpy (str, "Learning Lab");
    puts (str);

    str = (char *) realloc(str, 19);
    int length = sizeof (str);
    printf("%i\n", length);
    strcat (str, " rocks");
    puts (str);
    free(str);
     printf("_______\n");
     puts (str);
    }
    getch();
    return 0;
}
