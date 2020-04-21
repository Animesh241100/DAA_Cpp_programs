//REcursive Program to find GCD by euclidean method using Iterative Method.	

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
	int a, b, c;
	a = (x>y) ? x : y ;   //max
	b = (x>y) ? y : x ;   //min
	while(a != b)
	{	
		if(a%b != 0)
		{
			c = a%b;
			a = b;
			b = c;
		}
		else
			return b;
	}
}
