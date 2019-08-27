#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <conio.h>

int** getMem(int n){
	int i;
  	int **p;
  	p = (int**) malloc(sizeof(int*)*n);
  	for(i = 0; i<n; i++){
  		*(p+i)=(int*)malloc(n*sizeof(int));
  	}
  	return p;
}

void giveValue(int n, int **p){
	int i, j;
	for(i = 0; i<n; i++){
		for( j = 0; j<n; j++){
			p[i][j] = -10+rand()%21;
		}
	}
} 

int norma(int n, int **p){
	int sum, max=0;
	int i, j;
	for(i = 0; i<n; i++){
		for( j = 0; j<n; j++){
			sum+=p[i][j];
		}
		if(sum>max){
			max = sum;
		}
	}
	return max;
}

void print(int n, int **p){
	int i, j;
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("%3i", p[i][j]);
        }
        printf("\n");
    }
}

void three_matr(int **p1, int **p2, int **p3){
	int N=5 ,i , min;
	int norm1, norm2, norm3;
	p1 = getMem(N);	
	p2 = getMem(N);	
	p3 = getMem(N);
	giveValue(N, p1); 
	giveValue(N, p2); 
	giveValue(N, p3);
	norm1 = norma(N, p1);
	norm2 = norma(N, p2);
	norm3 = norma(N, p3);
	printf("1 norma - %i\n2 norma - %i\n3 norma - %i\n", norm1, norm2, norm3);
	printf("*****\n");
	if(norm1 < norm2 && norm1 < norm3){
		min = norm1;
		print(N, p1);
	}
	else if(norm2 < norm1 && norm2 < norm3){
		min = norm2;
		print(N, p2);
	}
	else{
		min = norm3;
		print(N, p3);
	} 
}
int main(){
	srand(time(0));
	int **arr1, **arr2, **arr3;
	three_matr(arr1,arr2,arr3);
		
}
