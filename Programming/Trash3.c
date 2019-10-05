#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <conio.h>



int main()

{
    FILE *input = fopen ( "nameOfRows.txt", "r" );
    FILE *output = fopen ( "rowsName.dat", "wb" );
    int i, j = 0, flag;
    char* string = ( char* ) calloc ( sizeof ( char ), 100 );
    while ( 1 )
    {
        flag = fscanf ( input, "%c", * ( string + j ) ) ;

        if ( * ( string + j ) == '\n' || flag == 0 )
        {
            *(string + j) = 0;
            fwrite(string, sizeof(char), 100, output);
            j = 0;
        }
    }
    freopen( "rowsName.dat","rb", output);
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
