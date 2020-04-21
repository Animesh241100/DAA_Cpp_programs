//This is a logic of making a sorted array out of k sorted arrays(incomplete).

#include<iostream>

using namespace std;
void Display(int * A, int size);

int main()
{
    int k;
    cout<<"Enter the no. of arrays to be sorted\n";
    cin>>k;
    int ptr[k];
    int size[k];
    for(int i = 0; i < k; i++)
        ptr[i] = 0;

    cout<<"Enter their sizes\n";
    for(int i = 0; i < k; i++)
        cin>>size[i];

    int arr[k][500];
    for(int i = 0; i < k; i++)
    {
        printf("Next\n");
        for(int j=0; j<size[i]; j++)
            cin>>arr[i][j];
    }

    printf("The Array entered is :\n");
    for(int i = 0; i < k; i++)
    {
        for(int j=0; j<size[i]; j++)
            printf(" %d", arr[i][j]);
        printf("\n");
    }

    // *(arr + i) points to the ith 1-D array.  i = [0...k-1] & j = [0...size[i]-1]
    // *(arr + i) + j points to the jth element of ith 1-D array.
    // *(*(arr + i) + j) represents the value of jth element of ith 1-D array.
    
    int min ;
   
    min = arr[0][ptr[0]];
    for(int i = 0; i < k - 1; i++)
    {   
        
        if(arr[i][ptr[i]] < min)
        {
            min = arr[i][ptr[i]];
            if(ptr[i] < size[i]) 
                ptr[i] = ptr[i] + 1;
            printf("  ifmin = %d \n", min);
        }

    }
    Display(ptr, k);
    printf(" endmin = %d ", min);
    
    
    return 0;
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

 /*
    for(int i = 0; i < k - 1; i++)
    {
        if(*(*(arr + i) + ptr[i]) <= *(*(arr + i + 1) + ptr[i+1]))
        {
            min = *(*(arr + i) + ptr[i]);
            ptr[i] = ptr[i] + 1;
        }
        else
        {
            min = *(*(arr + i + 1) + ptr[i+1]);
            ptr[i+1] = ptr[i+1] + 1;
        }
    }
    */

   /*if(arr[i][ptr[i]] <= arr[i + 1][ptr[i + 1]])
            {
                if(arr[i][ptr[i]] < min)
                {
                    printf("\narr[i][ptr[i]] = %d arr[i + 1][ptr[i + 1]]= %d\n",  arr[i][ptr[i]], arr[i + 1][ptr[i + 1]]);
                    min = arr[i][ptr[i]];
                    if(ptr[i] < size[i]) 
                        ptr[i] = ptr[i] + 1;
                    
                    printf("  ifmin = %d \n", min);
                }
            }
            else
            {
                if(arr[i + 1][ptr[i + 1]] < min)
                {
                    printf("\narr[i][ptr[i]] = %d arr[i + 1][ptr[i + 1]]= %d\n",  arr[i][ptr[i]], arr[i + 1][ptr[i + 1]]);
                    min = arr[i + 1][ptr[i + 1]];
                    if(ptr[i + 1] < size[i + 1]) 
                        ptr[i + 1] = ptr[i + 1] + 1;
                    printf("  elsemin = %d \n", min);
                }
            }*/