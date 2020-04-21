//REcursive Program to find GCD by euclidean method

#include<stdio.h>

int GCD(int x, int y);

int main()
{
	int x, y;
	printf("Enter the two no. for GCD\n");
	scanf("%d%d", &x, &y); 
	printf("The GCD is %d\n",GCD(x,y));
	return 0;
}
	
int GCD(int x, int y)
{
	int a, b;
	a = (x>y) ? x : y ;   //max
	b = (x>y) ? y : x ;   //min
	if(a%b == 0)
		return (b);
	GCD(b,a%b);
}
		 
	
