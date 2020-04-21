#include<iostream>
using namespace std;

void BS(int * arr, int l, int h, int data, int * mul, int size);
void Merge( int * arr, int l, int mid, int h) ;
void MS( int * arr, int l, int h) ;
void Display(int * A, int size);

int main()
{
	int size;
    printf("Enter array size\t");
    scanf("%d", &size);
    int arr[size];
    int mul[size];
    for(int j = 0; j < size; j++)
        cin>>arr[j];
    for(int j = 0; j < size; j++)
        mul[j] = 0;
	MS(arr, 0, size - 1);
    printf("hi");
    for(int i = 0; i < size; i++)
    {
       BS(arr, 0, size - 1, arr[i], mul, size);
    }
	Display(arr, size);
    Display(mul, size);
	return 0;
}

void BS(int * arr, int l, int h, int data, int * mul, int size)
{
    int mid = 0;
    mid = (l + h)/2;
	if(l > h)
		return;
    if(arr[mid] > data)
        BS(arr, l, mid - 1, data, mul, size);
    else if(arr[mid] < data)
        BS(arr, mid + 1, h, data, mul, size);
    else if(arr[mid] == data)
    {
        mul[mid] = mul[mid] + 1;
        BS(arr, mid + 1, h, data, mul, size);
		BS(arr, l, mid - 1, data, mul, size);
    }
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
