#include<iostream>
using namespace std;

int Product(int * arr1, int * arr2, int * arr, int size);

int main()
{
    int size1, size2;
    int arr1[] = {1, 0, 1, 0, 1};
    int arr2[] = {1, 1, 0, 1, 0, 1};
    size1 = sizeof(arr1);
    size2 = sizeof(arr2);
    int arr[size];
    mul(arr1,  arr2, arr, size);
}

int Product(int * arr1, int * arr2, int * arr, int size)
{
    
    for(int i = size - 1; i > 1; i--)  //loop for bits of smaller number
    {
        for(int j = size - 1; j > 1; j--)  //loop for bits of bigger number
        {
            arr[j] = (arr[j - 1]) ^ (arr1[i] * arr2[j]);


