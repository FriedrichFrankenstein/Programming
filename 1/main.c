#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

typedef struct{
    float *beginOfPeriod;
    float *endOfPeriod;
    float *average;
} Row;


int main ()
{
    int i, j, years = 3;
    FILE *addmyrg = fopen("addmyrg.dat", "rb");
    FILE *myrgorod = fopen("myrgorod.dat", "ab");
    Row *rows = (Row*) calloc(sizeof(Row), 160);
    fseek(addmyrg, sizeof(float)* years *101, SEEK_SET);
    fseek(myrgorod, sizeof(float)* years *101, SEEK_SET);
    for ( i = 102; i < 160; i++ )
    {
        ( rows + i ) ->average = ( float* ) calloc ( sizeof ( float ), years );
        fread( ( rows + i ) ->average , sizeof(float), years, addmyrg);
        printf("%i  ", i);
        for (j = 0 ; j < years; j++){
            printf("%15.2f ", ( rows + i ) ->average[j]);
        }
        printf("\n");
        //fwrite(( rows + i ) ->average , sizeof(float), years, myrgorod);
    }
    getch();
    getch();
    return 0;
}


