#include<stdio.h>
void main()
{
	int a, *p, i;
	a = 2;
	p = &a;
	i = *p +1;
	printf("%d\n", a);
	printf("%d\n", &a);
	//printf("%d\n", *a);
	printf("%d\n", p);
	printf("%d\n", &p);
	printf("%d\n", i); //3
	//printf("%d\n", *p);
}
	
