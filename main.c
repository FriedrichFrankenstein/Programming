#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>


float catchDate ();

int main ()
{
    printf("Result = %.2f", catchDate());
    getch();
    return 0;
}

float catchDate (){
    char string [20];
    scanf("%s", string);
    float num = strtof(string, NULL);
    if (num < 1){
        return 0;
    } else {
        return num;
    }


}
