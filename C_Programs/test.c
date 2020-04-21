#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
void main()
{
	char s1[100] = "Abcd";
	s1 = strlow(s1);
	char s2[100] = "abcd";
	printf("%d", strcmp(s1,s2));
	
}
		
