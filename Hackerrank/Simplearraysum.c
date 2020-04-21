int simpleArraySum(int n, int * ar) //same as int simpleArraySum(int n, int ar[]) because for fn. simpleArraySum sees ar[] just as ausual pointer variable. 
{
	int sum = 0;
	if(ar)
	{
		for(int i=0; i<n; i++)
			sum = sum + ar[i];
		return sum;
	}
	else
		return 0;
}



/*clarification for int * ar


#include <stdio.h> 
  
// Note that arr[] for fun is just a pointer even if square 
// brackets are used 
void fun(int arr[])  // SAME AS void fun(int *arr) 
{ 
   unsigned int n = sizeof(arr)/sizeof(arr[0]); 
   printf("\nArray size inside fun() is %d", n); //Output:  1
} 
  
// Driver program 
int main() 
{ 
   int arr[] = {1, 2, 3, 4, 5, 6, 7, 8}; 
   unsigned int n = sizeof(arr)/sizeof(arr[0]); 
   printf("Array size inside main() is %d", n); //Output:  8
   fun(arr); 
   return 0; 
} */
