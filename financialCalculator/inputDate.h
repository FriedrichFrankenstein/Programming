#ifndef INPUTDATE_H_INCLUDED
#define INPUTDATE_H_INCLUDED
#define START_X 100
#define START_Y 10

typedef struct{
    int id;
    float *beginOfPeriod;
    float *endOfPeriod;
    float *average;
} Row;

void printTable (int years, int firstYear);

void gotoxy(int x, int y);

void cursorMoving (Row *rows, int years );

void checkCordinate (int* x, int* y, int* table, int years );

void menu (Row *rows);

void crateNewFirma (Row *rows, int years, int firstYear);

void catchDate (int x, int y, Row *rows, int table);

#endif // INPUTDATE_H_INCLUDED
