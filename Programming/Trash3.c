#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <conio.h>

typedef struct {

    int *array1;
    int *array2;
} Test;

int main()

{
    int i;
    Test *big;
    big = (Test*) calloc(sizeof(Test), 5);
    for (i = 0; i < 5; i++){
        big->array1 = (int*) calloc(sizeof(int), 5);
        big->array2 = (int*) calloc(sizeof(int), 5);
    }
    big->array1[0] = 5;
    printf("%i",  big->array1[0] = 5);
    getch();
    return 0;
}



































//    if ( abs(averageMinus) < averagePlus){
//        for (i = 0; i <  20 - N; i++){
//            if (abs(arrPlus[i] - averagePlus) < min){
//                min = abs(arrPlus[i] - averagePlus);
//            }
//        }
//        printf("\nplus min = %i\n", min);
//         for (i = 0; i <  20 - N; i++){
//            if (abs(arrPlus[i] - averagePlus) == min){
//                arrPlus [i] = averagePlus;
//            }
//             arr[i] = arrPlus[i];
//        }
//    } else {
//        for (i = 0; i < N; i++){
//            if (abs(arrMinus[i] - averageMinus) < min){
//                min = abs(arrMinus[i] - averageMinus);
//            }
//        }
//        printf("\nminus min = %i\n", min);
//         for (i = 0; i < N; i++){
//            if (abs(arrMinus[i] - averageMinus) == min){
//                arrMinus [i] = averageMinus;
//            }
//             arr[i] = arrMinus[i];
//        }
//    }
