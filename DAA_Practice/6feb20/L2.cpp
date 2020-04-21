//This is a logic of making a sorted array out of k sorted arrays

#include<iostream>

using namespace std;
void Display(int * A, int size);
void Sort(int * arr1, int s1, int * arr2, int s2);

int main()
{
    int k;
    cout<<"Enter the no. of arrays to be sorted\n";
    cin>>k;
    int size[k];
    cout<<"Enter their sizes\n";
    for(int i = 0; i < k; i++)
    {
        cin>>size[i];
    }
    int arr[k][500];
    for(int i = 0; i < k; i++)
    {
        for(int j=0; j<size[i]; j++)
        {
            cin>>arr[i][j];
        }
        printf("Next\n");
    }

    for(int i = 0; i <= k-2; i++)
    {
        Sort(*(arr+i), size[i], *(arr+i+1), size[i+1]);
        size[i+1] = size[i] + size[i+1];
        Display(*(arr+i+1),size[i+1]);
    }
    Display(*(arr + k-1),size[k-1]);
    return 0;
}

void supsort(int start, int end, int * arr)
{
    if(start == end - 1)
    {
        Sort(*(arr+start),, size 
void Sort(int * arr1, int s1, int * arr2, int s2)
{
    int temp[500];
    int x = 0; 
    while(x!=s2)
    {
        temp[x] = arr2[x];
        x++;
    }
    int count = 0;
	x = 0;
	int y = 0;
	while(x<s1 && y<s2)
	{
		if(arr1[x] > temp[y])
		{
			arr2[count] = temp[y];
			count++;
			y++;
		}
		else
		{
			arr2[count] = arr1[x];
			count++;
			x++;
		}
	}

	if(count != s1+s2)
	{
		while(x < s1)
		{
			arr2[count] = arr1[x];
			count++;x++;
		}
		while(y < s2)
		{
			arr2[count] = temp[y];
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
