#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX 80



int main()

{
    char *str = calloc(sizeof(char), MAX);
    char temp;
    int i = 0;
    printf ( "Input string: " );
    while (i != MAX - 1){
        temp = getch();
        if (temp == 27 || temp == 13){
            break;
        } else {
            printf("%c", temp);
            *(str + i) = temp;
            i++;
        }

    }
    str[i] = 0;
    printf ( "\nYou`ve input: %s", str );
    return 0;
}
