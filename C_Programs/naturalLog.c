#include<stdio.h>
void log1(float x);
int main()
{
	float x;
	printf("Enter\n");
	scanf("%f", &x);
	log1(x);
	return 0;
}
void log1(float x)
{
	float p,log;
	
	p = (x-1)/x;
	log = p;
	for(int i=0; i++<6;)
	{
		p = p*p;
		log = log + 0.5*p;
	}
	printf("\nNatural Log is\n %f\n", log);
}
		
