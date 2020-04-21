//Count the number of negative numbers in a binary array using Divide & Conquer
#include<iostream>
using namespace std;

int Neg(int * arr,int f, int l);

int main()
{
    int size = 0;
    printf("Enter the size of the array\n");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the binary array\n");
    for( int i = 0; i < size; i++ )
    {
        scanf("%d", &arr[i]);
    }
   
    cout<<"the no. of Negative numbers is "<<Neg(arr,0, size - 1)<<endl;
    return 0;

}


int Neg(int * arr,int f, int l)
{
    int h1 = 0;
    int h2 = 0;
    if(f == l)
    {
        if(arr[f] < 0)
            return 1;
        else 
            return 0;
    }
    h1 = Neg(arr, f, (f+l)/2);
    h2 = Neg(arr, (f+l)/2  + 1, l);
    return (h1 + h2);
}




