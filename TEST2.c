#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void test (int *pa){
    int b =50;
    pa = &b;
    printf(" p = %p\n", pa);
}

int main()
{
    int a = 2547 / 255;
    int *pa = &a;
    printf("%i\n", *pa);
    getchar();
    return 0;
}



