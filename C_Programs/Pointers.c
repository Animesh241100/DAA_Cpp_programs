#include<stdio.h>

int main()
{
	int x=56;
	int *xp;
	x * xp;
	
	
	//xp = &x;
	
	printf("Address of variable x is %d\n", xp);
	printf("*xp(%d) contains the value of x(%d) and xp(%d) contains the address of x(%d) \n", *xp, x, xp, x);
	return 0;
}
	
	
