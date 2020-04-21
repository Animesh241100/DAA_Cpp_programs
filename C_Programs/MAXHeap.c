//This is an example program of Priority Queue ADT using Max heap Data structure, where only Del_MAX is allowed.
#include<stdio.h>
#include<stdlib.h>
struct Heap
{
	int arr[50];
	int last; 
};
struct Heap H;
void insert(int p);
int delete();
void main()
{
// create empty heap
	H.last = 0;
	insert(15);
	insert(500);
	insert(50);
	insert(70);
	insert(1);
	insert(5);
		
	for(int i = 1;i <= H.last;++i)
		printf("%d ", H.arr[i]);
	printf("\n%d\n", delete());
	for(int i = 1;i <= H.last;++i)
		printf("%d ", H.arr[i]);
}
void insert(int p)
{
	H.last++;
	H.arr[H.last] = p;  //insert the node x at the last most empty slot of the key
	int t = H.last;
	while((t/2 >= 1) && (H.arr[t] >= H.arr[t / 2])) //Remedial action, if flaw occured
	{					//if child has become larger than parent
		H.arr[t] = H.arr[t] ^ H.arr[t/2];   //swap H.arr[t](child) and H.arr[t/2](parent)
		H.arr[t/2] = H.arr[t] ^ H.arr[t/2];
		H.arr[t] = H.arr[t] ^ H.arr[t/2];
		t /= 2;  //to go from bottom to top and scan each time
	}
}
int delete()
{
	int x = H.arr[1];
	H.arr[1] = H.arr[H.last];  //H.last is the index in the array
	H.last--;		   
	int t = 1;
	int mi;
	while(2*t  <= H.last)  
	{
		if(H.last >= 2*t+1)    //if current node(index t) has second child
		{
			if(H.arr[2*t] > H.arr[2*t+1])  
				mi = 2*t;
			else 
				mi = 2*t+1;
		}
		else     //if current node(index t) has only one child
			mi = 2*t;
			
//Assignment the 'INDEX' of max of both the children of node which we're currently at(index t)to 'mi'

		if(H.arr[t] < H.arr[mi]) //Remedial action, if flaw occured
		{
			H.arr[t] = H.arr[t] ^ H.arr[mi];
			H.arr[mi] = H.arr[t] ^ H.arr[mi];
			H.arr[t] = H.arr[t] ^ H.arr[mi];
			t = mi;  //now t becomes child of it
		}
		else break;
	}
	return x;
}
