//Prob-2: Brute force(linear Search)

#include<stdio.h>
#include<time.h>

int LinSearch(int * arr, int data);
int Marking(int * arr, int data);

void main()
{
	clock_t t;
	t = clock();
	double duration;
	//int arr[8] = {2, 5, 7, 78, 89, -1, -1, -1};
	int arr[10000];
	int size, mark;
	printf("Enter the array size:\n");
	scanf("%d", &size);
	printf("Now, enter all the array elements in a non-decreasing manner:\n");
	for(int i = 0; i < size; i++)
		scanf("%d", &arr[i]);

	printf("The position of first -1 is %d\n", LinSearch(arr, -1));
	t = clock() - t;
	duration = ((double)t)/CLOCKS_PER_SEC;
	printf("The total time taken by the process is %f seconds\n", duration);	
}


int LinSearch(int * arr, int data)
{
	int i = 0;
	while(arr[i] != -1)
		i++;
	return i;
}
