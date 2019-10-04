#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>



int main()

{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    FILE *input = fopen ( "nameOfRows.txt", "r" );
    FILE *output = fopen ( "rowsName.dat", "wb" );
    int i, j = 0, flag;
    char* string = ( char* ) calloc ( sizeof ( char ), 100 );
    while ( 1 )
    {
        if (fscanf ( input, "%c", &* ( string + j ) ) == EOF){
             *(string + j) = 0;
            fwrite(string, sizeof(char), 100, output);
            j = 0;
            break;
        }
        if ( * ( string + j ) == '\n' )
        {
            *(string + j) = 0;
            fwrite(string, sizeof(char), 100, output);
           // printf("%s\n", string);
            j = 0;
            continue;
        }
        j++;
    }
    freopen( "rowsName.dat","rb", output);
    i = 0;
    while( i < 161){
        i++;
        fread(string, sizeof(char), 100, output);
        printf("%s\n", string);
    }
    fclose(input);
    fclose(output);
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
