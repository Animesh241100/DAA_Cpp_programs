//This is a code for Merge_Sort(Divide & Conquer)
// Two way merge sort

#include<stdio.h>
void Merge( int * arr, int l, int mid,int h) ;
void MS( int * arr, int l, int h) ;
void Display(int * A, int size);


//int count = 0;

int main()
{
	int arr[] = {-9,-4,-6,-4,-8,-5,-3,-1};
	int size = sizeof(arr)/4;
	printf("size is %d \n", size );
	MS(arr, 0, size - 1);
	Display(arr, size);
	return 0;
}

void MS( int * arr, int l, int h) 
{
	if(h > l + 1)
	{
		MS(arr, l, (l+h)/3);
		MS(arr, (l+h)/3 + 1, ((l+h)/3)*2);
        MS(arr, ((l+h)/3)*2, h);
		Merge(arr, l, (l+h)/3, ((l+h)/3)*2, h);
	}
}

void Merge(int * arr, int l, int mid1, int mid2, int h)  
{  
	int Left[mid1-l+1];
    int Middle[mid2-mid1];
	int Right[h-mid2];
	int count = l;
	int i = l;
	int j = mid1 + 1;
    int k = mid2 + 1;
	int x = 0;
	int y = 0;
    int z = 0;
	while(i<=mid1)
	{
		Left[x] = arr[i];
		x++;i++;
	}
	while(j<=mid2)
	{
		Middle[y] = arr[j];
		y++;j++;
	}
    while(k<=h)
	{
		Right[z] = arr[k];
		z++;k++;
	}
	x = 0;
	y = 0;
    z = 0;
	while(x<(mid1-l+1) && y<(mid2-mid1) && z<(h-mid2) )
	{
		if(Left[x] > Middle[y])
		{
            if(Middle[y] > Right[z])
            {
                arr[count] = Right[z];
			    count++;
			    z++;
		    }
            else
	    	{
		    	arr[count] = Middle[y];
		    	count++;
		    	y++;
	    	}
        }
		else
		{
			if(Left[x] > Right[z])
            {
                arr[count] = Right[z];
			    count++;
			    z++;
		    }
            else
	    	{
		    	arr[count] = Left[x];
		    	count++;
		    	x++;
	    	}
		}
	}
	if(count != h-l+1)
	{
        if(x < (mid1-l+1))
        {
            if(y< (mid2-mid1))
            {
                
		while(x < (mid1-l+1))
		{
			arr[count] = Left[x];
			count++;x++;
		}
		while(y < (mid2-mid1))
		{
			arr[count] = Right[y];
			count++;y++;
		}
        while(y < (h-mid2))
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
