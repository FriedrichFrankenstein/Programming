#include <stdio.h>
#include <math.h>
main(){
	float a, b, c, z;
	printf ("Enter side a and b:");
	scanf ("%f%f", a, b);
	z=pow(a,2)*pow(b,2);
	c=sqrt(z);
	printf ("c=g", c);
	getchar();
}
