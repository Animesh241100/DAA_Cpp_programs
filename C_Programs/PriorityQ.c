#include<stdio.h>
#include<stdlib.h>
struct Heap
{
	int exec[100];
	int id[100];
	int last; 
};
struct Heap H;
void Insert(int x, int i);
void delete();

void main()
{
	Insert(20, 1);
	Insert(30, 2);
	Insert(50, 35);
	Insert(10, 33);
	Insert(15, 7);
	printf("The process id with least execution time is\n");
	printf("Process id	  Execution time\n"); 
	delete();
	printf("\nThe remaining processes are:\nProcess id	  Execution time\n");
	while(H.last!=0)
		delete();
	
}
void Insert(int x, int i)
{
	H.last++;
	H.exec[H.last] = x;
	H.id[H.last] = i;
	int t = H.last;
	int swap;
	while(t/2 >= 1)
	{
		if(H.exec[t] < H.exec[t/2])  //if childkey < parentkey
		{
			swap = H.exec[t];
			H.exec[t] = H.exec[t/2];
			H.exec[t/2] = swap;
			swap = H.id[t];
			H.id[t] = H.id[t/2];
			H.id[t/2] = swap;
		}
		t = t/2;
	}
}

void delete()
{
	int x = 0;
	int i = 0;
	x = H.exec[1];  //Root node gets deleted since it has the least execution time and least priority.
	i = H.id[1];
	H.exec[1] = H.exec[H.last];
	H.id[1] = H.id[H.last];
	H.last--;
	int t=1;
	int swap;
	int mi;
	
	while(H.last >= 2*t)
	{
		if(H.last >= 2*t+1)  //both children exist
		{
			if(H.exec[2*t] < H.exec[2*t+1])   //mi is made pointing to the max of both children of the node number t
				mi = 2*t;         
			else 
				mi = 2*t+1;
		}
		else   //only left child exists
			mi = 2*t ;    //mi is made pointing to the left child
			
		if(H.exec[t] > H.exec[mi])   //now we're doing the remedial action.
		{				//Swap these keys 
			swap = H.exec[mi];   //swapping execution times
			H.exec[mi] = H.exec[t];
			H.exec[t] = swap;
			swap = H.id[mi];    //swapping ids
			H.id[mi] = H.id[t];
			H.id[t] = swap;
			t = mi;       //now shift the attention to the new location(new node) of our old key. 
		}
		else     //No need for remedy, structure is still perfect
			break;         
	}
	printf("%d		  %d\n", i, x);	
}
	
