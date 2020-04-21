#include<stdio.h>
#include <string.h>
#include <math.h>


int Digit(int n, int k);
int Super(int n);
int main()
{
	char * n;
	int * p[4];
	* n = '1';
	*( n + 1) = '7';
	* (n + 2 )= '8';
	* (n + 3)= '0';
	* (n + 4)= '8';
	for(int i =0; i<5; i++)
	{
		printf("%c\t", *(n + i) );
	}
	printf("length%d\n", strlen(n));
	printf("%d\n", *(n + 0) - 48 );
	printf("Sum is %d\n", Digit(1002345, 4));
	printf("%d\n ", sizeof(int));
	return 0;
}
	

	
int Super(int n)
{
	int sum = 0;
	for(int i =1; i<11; i++)
		sum = sum + Digit(n, i);
	return sum;
}	 

int Digit(int n, int k)
{
	return (  (n-  ((n/pow(10,k))*pow(10,k)))/pow(10,k-1)  ) ;
}
