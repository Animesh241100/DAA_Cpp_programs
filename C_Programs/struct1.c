#include <stdio.h>
#include <string.h>
struct  donno			
{
	char name[1000];
	float price;
};

int main()
{
	struct donno structre_Variable;
	printf("Enter the name and Price respectively\n");
	scanf("%s%f", structre_Variable.name, &structre_Variable.price);
	printf("You entered Name= %s \nPrice=%f\n",structre_Variable.name, 			structre_Variable.price );
	return 0;
}
	
