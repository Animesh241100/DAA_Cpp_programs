#include<stdio.h>

int G(int arr[], int b);
int check( int arr[], int x);
void GCD(int x, int y, int arr[]);

int main()
{
	int x, y, a, b, i, j;
	int arr[1000];
	printf("Enter the two no. for G\n");
	scanf("%d%d", &a, &b);
	x = (a>b) ? a : b ;   //max
	y = (a>b) ? b : a ;   //min
	GCD(x, y, arr);
	return 0;
}

void GCD(int x, int y, int arr[])
{
	int i, j;
	i = 1;
	j = 0;
	while(i != x+1)
	{
		if(x%i == 0)
		{
			arr[j] = i;
			j++;
		}
		i++;
	}	
	printf("The gcd is %d\n", G(arr, y));
}


int G(int arr[], int b)        //to find the maximum element in arr[], which is also a 
{				//divisor of 'b'
	int g;
	for(int i =1 ; i <= b; i++) 
	{
		if(b%i == 0)
		{
			if(check(arr, i))
				g = i;
		}
	}
	return g;
}

int check(int arr[], int x)    //to check if 'x' is there in passed array arr[]
{
	int i = 0;
	while(arr[i] != 0)
	{
		if(arr[i] == x)
		{
			return 1;		
		}
		i++;
	}
}

	
