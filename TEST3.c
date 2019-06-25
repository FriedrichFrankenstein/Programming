#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
    char words [40] = "WORLD";
    char newWord[40] = "WORD";
    char temp [40];
    scanf ( "%s",  words  );
    printf ("%s\n", words);
    strcpy(temp, newWord);
    printf("%s\n", temp);
    getch();
    return 0;
}
