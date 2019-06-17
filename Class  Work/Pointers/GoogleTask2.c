#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>




int main(){
    int num [5] = {0, 1, 2 ,3 ,4 };
    int *pnum = num;
    printf("%i\n", *pnum);
    *pnum += 1;
    printf("%i\n", *pnum);
    printf("%i\n", num[0]);
    free(pnum);
    if (pnum == NULL){
        printf("TRUE");
    }
    getch();
    return 0;
}


