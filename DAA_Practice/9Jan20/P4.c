//Prob-2: Binary Search Variant(Fibonacci jumping marking)

#include<stdio.h>
#include<time.h>

int BinSearch(int * arr, int l, int h, int data);
int Marking(int * arr, int data);
int Fib(int i);


void main()
{
	clock_t t;
	t = clock();
	double duration;
	int arr[10000] = {[0 ... 9999] = -1};  
	printf("hi %d\n", arr[9999]);
	int size, mark1, mark2;
	printf("Enter the array size:\n");
	scanf("%d", &size);
	printf("Now, enter all the array elements in a non-decreasing manner:\n");
	for(int i = 0; i < size; i++)
		scanf("%d", &arr[i]);
	mark2 = Fib(Marking(arr, -1));
	mark1 = Fib(Marking(arr, -1) - 1);
	printf("The position of first -1 is %d\n", BinSearch(arr, mark1, mark2, -1));
	t = clock() - t;
	duration = ((double)t)/CLOCKS_PER_SEC;
	printf("The total time taken by the process is %f seconds\n", duration);	
}	

int Marking(int * arr, int data)
{
	int i = 0;
	while(arr[Fib(i)] != data)
		i++;
	return i;
}


int Fib(int i)
{
    if(i==0 || i==1)
    	return i;
    else
    	return Fib(i-1) + Fib(i-2);
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
