#include<iostream>

using namespace std;

void Quicksort(int * arr, int l, int h);
int Partition(int * arr, int l, int h);
void Print_array(int * arr);
void Swap(int * a, int * b);


int main()
{
    int n;
    srand(time(0));
    n = rand() % 200;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    Quicksort(arr, 0, n - 1);
    Print_array(arr);
    return 0;
}

void Quicksort(int * arr, int l, int h)
{
 //   int pivot = h;
    int q = Partition(arr, l, h);   //keeping last element as a pivot for partition.
    Quicksort(arr, l, q - 1);
    Quicksort(arr, q + 1, l);
}

int Partition(int * arr, int l, int h)
{
    int i = l;  //general pointer which simply scans all elements 1 by 1.
    int j = l - 1;  //another pointer pointing to the last element of the 'small' region.
    int pivot = h; //keeping last element as the pivot
    while(l != pivot) //until you have scanned all the element except the pivot.
    {
        if(arr[i] < arr[pivot]) 
        {
            if(i > j + 1) // if i is at least 1 unit distance away the last element of 'small' region, i.e. there exists at least one confirmed member in 'large' region.
            {
                Swap(arr + i, arr + j + 1); //swap the current value with the first-most element of the 'large' region.  
                j++; //expand the horizons of 'small'
                i++; //focus on next value religiously.
            }
            else //if the 'large' region doesn't exist,
            {
                j++; //simply expand the horizons of 'small'
            }
        }
        else
        {
            i++;
        }
        Swap(arr + pivot, arr + j + 1); //at last swap the values of the pivot and the first element of the 'large'.
        return j + 1; //return the the pivot element's new location.
}

void Swap(int * a, int * b)/* code */
{
    int temp = *a;
    *a = *b;
    *b = temp;
}