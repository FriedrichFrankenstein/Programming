#ifndef INPUTDATE_H_INCLUDED
#define INPUTDATE_H_INCLUDED
#define START_X 100
#define START_Y 10

//основна структура зберігання та обробки даних
typedef struct{
    float *beginOfPeriod;
    float *endOfPeriod;
    float *average;
} Row;
//друкує таблиці для вводу даних
void printTable (int years, int firstYear);
//переміщення курсору
void gotoxy(int x, int y);
//визначення напрямку руху курсору та наступних координат залежно від вибору користувача
void cursorMoving (Row *rows, int years );
//перевірка координат на адекватність (чи вийшли за рамки таблиці)
void checkCordinate (int* x, int* y, int* table, int years );
//створює нову фірми, приймаючи її назву та викликає необхідні функції
void crateNewFirma (Row *rows, int years, int firstYear, float **result;);
//функція яка зчитує значення з екрану та записує у необхідні комірки
void catchDate (int x, int y, Row *rows, int table);
//розрахунок середніх значень
void createAvarage (Row *rows, int years);
//зберігає дані до файлу
void saveData (Row *rows, int years, int firstYear, char* nameCompany);
//зчитує дангі з файлу
void catchDateFile ( Row *rows, int* pYears, int* pfirstYear );
//приймає з екрану дані типу флоат
float funScanFloat() ;
//приймає з екрану дані типу інт
int funScanInt ();

#endif // INPUTDATE_H_INCLUDED
