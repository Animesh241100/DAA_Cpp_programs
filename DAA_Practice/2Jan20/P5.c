
#include<stdio.h>

int GCD(int x, int y);
int GCDA(int * arr , int l);

int i = 0;


int main()
{
	int l;
	printf("Enter the total no.\n");
	scanf("%d", &l);
	int arr[l];
	printf("Enter %d integers for GCD\n", l);
	for(int i = 0; i < l; i++)
		scanf("%d", &arr[i]);
		
	printf("The GCD is %d\n",GCDA(arr, l));
	return 0;
}
	

int GCDA(int * arr , int l)
{
	if(i==(l-1))
		return arr[l-1];
	arr[i+1] = GCD(arr[i], arr[i+1]);
	i++;
	GCDA(arr, l);
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

