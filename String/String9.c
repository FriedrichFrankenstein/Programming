#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>





int main(){
    int N = 0, i;
    printf("Enter N: ");
    scanf("%i", &N);
    printf("Enter C (char)\n ");
    char C = getch();
    char *string = calloc(N, sizeof(char));
    for (i = 0; i < N; i++){
        *(string + i) = C;
    }
    puts (string);
    getch();
    return 0;
}


