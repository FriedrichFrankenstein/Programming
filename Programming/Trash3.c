#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main()

{
    int *a = (int *) calloc(INT_MAX, INT_MAX);
    int i = 0;
    while (1){
        *a = i;
        printf("%i", *a);
        i++;
        if ( *a = 1000){
            break;
        }
    }
    free(a);
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
