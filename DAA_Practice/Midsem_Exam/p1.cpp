#include<iostream>
using namespace std;

int main()
{
    int size;
    printf("Enter array size:\t");
    scanf("%d", &size);
    int arr[size];
    int mul[size];
    printf("Enter the array elements:\n");
    for(int j = 0; j < size; j++)
        cin>>arr[j];

    for(int j = 0; j < size; j++)
        mul[j] = 0;

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(arr[i] == arr[j])
                mul[i] = mul[i] + 1;
        }
    }

    printf("\n");
    for(int j = 0; j < size; j++)
    {
        printf("multiplicity of %dth element is %d \n", j, mul[j]);
    }
    return 0;
}