#include<stdio.h>
#include<math.h>
long double lim(long double x, long double y);
void main()
{
	long double x, y;
	printf("Enter the base 'a' of the exponenet (a)^x):");
	scanf("%Lf", &x); 
	printf("Enter the 'dt'(smallest dt gives most accurate result) to get the term (a^dt - 1)/dt:");
	scanf("%Lf", &y); 
	printf("the term (a^dt - 1)/dt  is : %Lf", lim(x,y));
	printf("Enter 1 to do it again else 0\n");
}

long double lim(long double x, long double y)
{
	long double res = (pow(x,y) - 1)/(y);
	return res;
}
