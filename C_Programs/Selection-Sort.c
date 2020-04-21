#include<stdio.h>
int main()
{
	int c;
	int arr[10] = {4,6,1,2,3,8,4,9,0,5};
	for( int i=0; i<10; i++)
	{
		for( int j=i+1; j<10; j++) //Scan all the numbers next to the number you are right now. 
		{
			if(arr[j] < arr[i])
			{
				c = arr[j];
				arr[j] = arr[i];
				arr[i] = c;
			}
		}
	}
	for( int i=0; i<10; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
	return 0;
}
