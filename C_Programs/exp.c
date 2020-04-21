#include<stdio.h>
#include<stdlib.h>

void main()
{
	char str[10];
	gets(str);
	puts(str);
	int p = &str;
	printf("%s", p);
}
	
