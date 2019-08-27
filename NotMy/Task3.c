#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <math.h>
#include <stdlib.h>

int** memoryOnPoints(int N);
int greatestDistance (int** arr, int N);

int main ()
{
//	srand (time(NULL));
	int N;
	printf("RUE");
	scanf ("%i", &N);
	int **temp = memoryOnPoints(N);
	greatestDistance (temp, N);
    free(temp);
	getch ();
	return 0;
}
int** memoryOnPoints(int N)
{
	int i;
	int **pia = (int**)calloc(N, sizeof(int));
 	for (i = 0; i < N; i ++)
	{
		*(pia + i) =(int*)calloc(2, sizeof(int));
	}
   // pia-=N;

	return pia;
}

int greatestDistance (int** arr, int N)
{
	int i, j;

	for ( i = 0; i < N; i ++)
	{
			arr[i][0] = (rand()%20-10);
			arr[i][1] = (rand()%20-10);
			printf ("(%i;%i)\n", arr[i][0], arr[i][1]);
    }
}
