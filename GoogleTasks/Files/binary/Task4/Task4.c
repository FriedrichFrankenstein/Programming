#include <math.h>			//бібліотека математичних функцій
#include <stdio.h>
#include <conio.h>


int main()
{
    FILE* f = fopen("contacts.dat", "dw");
    int i;
    char surname[20];
    char name [20];
    int years, month, telefonNumber;
    float age;
    for ( i = 1 ; i < 12;i++ ){
    printf("Enter dates (name, surname, years, month, telefonNumber): ");
    scanf("%s %s %f %i", name, surname, &age, &telefonNumber);
    fwrite(name, sizeof(name), 1, f);
    fwrite(surname, sizeof(surname), 1, f);
    fwrite(&age, sizeof(float), 1, f);
    fwrite(&telefonNumber, sizeof(int), 1, f);
    }
    freopen("contacts.dat", "wd", f);
    for ( i = 1 ; i < 12;i++ ){
    printf("Enter dates (name, surname, years, month, telefonNumber): ");
    fread(name, sizeof(name), 1, f);
    fread(surname, sizeof(surname), 1, f);
    fwrite(&age, sizeof(float), 1, f);
    fread(&telefonNumber, sizeof(int), 1, f);
    printf("%i. %s %s %f %i", name, surname, years, month, telefonNumber );
    }
    getch();
    return 0;
}
