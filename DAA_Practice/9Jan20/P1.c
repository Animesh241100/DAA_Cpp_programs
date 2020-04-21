//Prob-1    Logic-1(both end pointers' sum comparison)
#include<stdio.h>
void Find_Sum(int * arr, int n, int p);


void main()
{
	int n, p;
	int arr[1000];
	printf("Enter the size of array.\n");
	scanf("%d", &n);
	printf("Enter the no. to find sum\n");  // p is the sum of the required pairs
	scanf("%d", &p);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	Find_Sum(arr, n, p);
}

void Find_Sum(int * arr, int n, int p)
{
	int f, r, flag;
	flag = 0;
	f = 0;
	r = n-1;
	while(f != r)
	{
		if((arr[f] + arr[r]) == p)
		{
			flag = 1;
			break;
		}
		else if((arr[f] + arr[r]) > p)
			r--;
		else
			f++;
	}
	if(flag==1)
		printf("Such a pair (%d, %d) exists in the passed array\n", arr[f], 
		arr[r]);
	else
		printf("Such a pair doesn't exist in the passed array\n");
}
	

