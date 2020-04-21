#include<stdio.h>
#include<math.h>

void BubbleSort(int * arr, int n);

int main()
{
    int n, size;
    printf("Enter the total no. of elements you want to enter(perfect square no. is expected as per the question):\t");
    scanf("%d", &n);
    size = sqrt(n);
    int arr[size][size];
    printf("Enter the array elements:\n");
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i = 0; i < size; i++)
    {
        BubbleSort(*(arr + i), size);
    }
    printf("\nSorted arrays:\n");
    for(int i = 0; i < size; i++)
    {
        printf("\narray%d", i);
        for(int j = 0; j < size; j++)
        {
            printf(" %d", arr[i][j]);
        }
    }
    printf("\n");
}

void BubbleSort(int * arr, int n)  
{  
    int i, j, v;  
    for (i = 0; i < n-1; i++)
    {   
        for (j = 0; j < n-i-1; j++)
        {  
            if (arr[j] > arr[j+1])
            {  
                v = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = v;
            }
        }

    }
}