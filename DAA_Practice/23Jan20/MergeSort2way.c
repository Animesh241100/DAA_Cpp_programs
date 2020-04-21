//This is a code for Merge_Sort(Divide & Conquer)
// Two way merge sort

#include<stdio.h>
void Merge( int * arr, int l, int mid,int h) ;
void MS( int * arr, int l, int h) ;
void Display(int * A, int size);


//int count = 0;

int main()
{
	//int arr[] = {-9,4,-6,-4,-8,-5,-3,-21};
	//int arr[] = {-9,-4,4,-5};
	int arr[] = {-9,-4,6,-4,8,-5,-3,-1};
	int size = sizeof(arr)/4;
	printf("size is %d \n", size );
	//Merge(arr, 0, (size-1)/2, size - 1);
	MS(arr, 0, size - 1);
	//printf("Count is %d \n", count);
	Display(arr, size);
	printf("Count is \n");
	return 0;
}

void MS( int * arr, int l, int h) 
{
	if(h > l + 1)
	{
		MS(arr, l, (l+h)/2);
		MS(arr, (l+h)/2 + 1, h);
		Merge(arr, l, (l+h)/2, h);
	}
	else if(arr[h] < arr[l])
	{
		int c;
		c = arr[l];
		arr[l] = arr[h];
		arr[h] = c;
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
