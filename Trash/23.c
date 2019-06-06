#include <stdio.h>
#include <conio.h>
#include <math.h>


int sum (int numberOne, int numberTwo )
{
	int sum = numberOne + numberTwo;
	return sum;
}
int diff (int numberOne, int numberTwo )
{
	int diff = numberOne - numberTwo;
	return diff;
}
int mult (int numberOne, int numberTwo )
{
	int mult = numberOne * numberTwo;
	return mult;
}
float division (float numberOne, float numberTwo)
{
	float div = numberOne / numberTwo;
	return div;
}
int main(){
	int sum1, diff1, mult1, div1, firstNumber, secondNumber ;
	printf ("Enter 2 numbers: ");
	scanf ("%i%i", &firstNumber, &secondNumber );
	if (secondNumber == 0){
		printf ("Error");		
	}
	else {
	sum1 = sum(firstNumber, secondNumber);
	diff1 = diff(firstNumber, secondNumber);	
	mult1 = mult(firstNumber, secondNumber);
	printf ("sum = %i\nsub = %i\ndiff = %i\ndiv = %g", sum1, diff1, mult1, division(firstNumber, secondNumber));	
}
getch ();
return 0;
}


