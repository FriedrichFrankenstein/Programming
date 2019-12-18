#ifndef FINCALCULATIONS_H_INCLUDED
#define FINCALCULATIONS_H_INCLUDED
#include "inputDate.h"
//Вся бібліотека це формули

//загальна функція, яка об'єднує всі наступні
void calculations (int years, float **result, Row *rows);

void liquidity  (int years, float **result, Row *rows);

void finStability (int years, float **result, Row *rows);

void profitability (int years, float **result, Row *rows);

void businessActivity (int years, float **result, Row *rows);

#endif // FINCALCULATIONS_H_INCLUDED
