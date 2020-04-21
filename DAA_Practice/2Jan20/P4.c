// try to do it, its still incomplete, brute force method by recursion

#include<stdio.h>

void Print(int arr[]);
int Factor(int x, int arr[]);

int i = 1;
int j = 0;

int main()
{
	int a;
	int arr1[1000];
	printf("Enter theno.\n");
	scanf("%d", &a);
	Factor(a, arr1);
	Print(arr1);
}
	
void Print(int arr[])
{
	int i = 0;
	while(arr[i] != 0)
	{
		printf("%d\t", arr[i]);
		i++;
	}
	printf("\n");
}


int Factor(int x, int arr[])
{
	int p;
	if((x % i) == 0)
	{
		arr[j] = x / i;
		j++;
	}
	else
	{
		i++;
		Factor(x, arr);
	}
	return 0;
} 
