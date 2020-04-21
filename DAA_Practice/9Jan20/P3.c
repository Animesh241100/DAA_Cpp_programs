//Prob-2: Binary Search Variant(exponential marking)

#include<stdio.h>
#include<time.h>

int BinSearch(int * arr, int l, int h, int data);
int Marking(int * arr, int data);

void main()
{
	clock_t t;
	t = clock();
	double duration;
	//int arr[8] = {2, 5, 7, 78, 89, -1, -1, -1};
	int arr[10000] = {[0 ... 9999] = -1};    //initializes all elements to -1
	printf("hi %d\n", arr[9999]);
	int size, mark;
	printf("Enter the array size:\n");
	scanf("%d", &size);
	printf("Now, enter all the array elements in a non-decreasing manner:\n");
	for(int i = 0; i < size; i++)
		scanf("%d", &arr[i]);
	mark = Marking(arr, -1);
	printf("The position of first -1 is %d\n", BinSearch(arr, 0, mark, -1));
	t = clock() - t;
	duration = ((double)t)/CLOCKS_PER_SEC;
	printf("The total time taken by the process is %f seconds\n", duration);	
}	

	
	 
int Marking(int * arr, int data)
{
	if(arr[0] != data)
	{
		int i = 1;
		while(arr[i] != data)
			i = 2*i;
		return i;
	}
	else
		return 0;
}	 
int BinSearch(int * arr, int l, int h, int data)
{
	int mid;
	mid = (l+h) / 2;
	if(arr[mid] == data)
	{
		if(arr[mid-1] != data)
			return mid;
		else
			return BinSearch(arr, l, mid-1, data);
	}
	else
		return BinSearch(arr, mid+1, h, data);  
}
