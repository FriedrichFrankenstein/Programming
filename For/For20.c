#include <stdio.h>
#include <conio.h>
#include <math.h>


int main ()
{ 
	int i, number, summ ;
	printf ("Enter number: ");
	scanf  ("%i", &number);
	for (i = 1; i < number; i++){
		factorial (i -1);
	//	summ += factorial (i);
	}
	printf ("Summ = %i", summ);
	getchar();
	return 0;
}
