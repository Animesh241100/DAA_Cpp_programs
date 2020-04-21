 //This is a code for a Merge_Sort varient(Divide & Conquer)

#include<iostream>

void Merge( int * arr, int l, int mid,int h); //MergeRoutine(Conquer)
void InsertionSort(int * arr, int l, int h); 
void MS( int * arr, int l, int h); //Merge_Sort varient(Divide)
void Display(int * A, int size);

int main()
{
    int arr[1000000];
    srand(time(0));
    for(int i = 0; i<1000000; i++)   
        arr[i] = rand() / (RAND_MAX / (1200) + 1);
	int size = sizeof(arr)/4;
    printf("size is %d \n", size );
	MS(arr, 0, size - 1);
	printf("The Sorted array is :\n");
	Display(arr, size);
    printf("end\n");
	return 0;
}

/* Instead of rand() use [M + rand() / (RAND_MAX / (N - M + 1) + 1)] to get your random numbers in a range of M to N(Both inclusive).*/
void MS( int * arr, int l, int h) 
{
    if(((h-l)/2 + 1) <= 10000)
    {
        InsertionSort(arr, l, (l+h)/2);
        InsertionSort(arr, (l+h)/2 + 1, h);
        Merge(arr, l, (l+h)/2, h);
    }
    else if(h > l + 1)
	{
		MS(arr, l, (l+h)/2);
		MS(arr, (l+h)/2 + 1, h);
		Merge(arr, l, (l+h)/2, h);
	}
	
}

void Merge(int * arr, int l, int mid, int h)  
{  
	int Left[mid-l+1];
	int Right[h-mid];
	int count = l;
	int i = l;
	int x = 0;
	int y = 0;
	int j = mid + 1;
	while(i<=mid)
	{
		Left[x] = arr[i];
		x++;i++;
	}
	while(j<=h)
	{
		Right[y] = arr[j];
		y++;j++;
	}
	x = 0;
	y = 0;
	while(x<mid-l+1 && (y<h-mid))
	{
		if(Left[x] > Right[y])
		{
			arr[count] = Right[y];
			count++;
			y++;
		}
		else
		{
			arr[count] = Left[x];
			count++;
			x++;
		}
	}
	if(count != h-l+1)
	{
		while(x < mid-l+1)
		{
			arr[count] = Left[x];
			count++;x++;
		}
		while(y < h-mid)
		{
			arr[count] = Right[y];
			count++;y++;
		}
	}
}

void InsertionSort(int * arr, int l, int h) 
{ 
    int i, key, j; 
    for (i = l+1; i <= h; i++)    
    { 
        key = arr[i]; 
        j = i - 1;
        while (j >= l && arr[j] > key) 
        { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
}

void Display(int * arr, int size)
{
	int i = 0;
	printf("\n");
	while(i != size)
	{
			printf(" %d ", arr[i]);
			i++;
	}
	printf("\n");
}
