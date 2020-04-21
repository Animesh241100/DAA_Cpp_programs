//This is a program to calculate GCD of a given array of numbers using Divide & Conquer 
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int AGCD(int * arr, int l, int h);

int barr[2];

int main()
{
	int arr[] = {-25, -75};
	int size = sizeof(arr)/4;
	printf("size is %d", size);
	printf(" GCD is :\t%d\n", AGCD(arr, 0, size - 1));
	return 0;
}

int gcd(int a, int b)
{
	if(b==0)
	{
		if(a != 0)
			return a;
		else
			return -1;
	}
	
	return gcd(abs(b), abs(a%b));
}	
int AGCD(int * arr, int l, int h)
{
	int n = h - l;
	if(n == 1)
		return gcd(arr[l], arr[h]);
	else if(n == 0)
		return arr[l];
	else
		barr[0] = AGCD(arr, l, (l + h)/2);
		barr[1] = AGCD(arr, (l + h)/2 + 1, h);
		return AGCD(barr, 0, 1);
}

