//This is an example program of Priority Queue ADT using Min heap Data structure, where only Del_MIN is allowed.
#include<stdio.h>
#include<stdlib.h>
struct heap
{
	int last;
	int arr[1000];
};

struct heap H;

int delete();
void insert(int x);

void main()
{
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

void insert(int k)
{
	
	H.last++;
	H.arr[H.last] = k;
	int t = H.last;
	while(((t/2)>=1)&&(H.arr[t] < H.arr[t/2]))
	{
		int c = H.arr[t/2];
		H.arr[t/2] = H.arr[t];
		H.arr[t] = c;
		t = t/2;
	}
}

int delete()
{
	int x = H.arr[1];
	H.arr[1] = H.arr[H.last];
	H.last--;
	int mi;
	int t = 1;
	while(2*t <= H.last)
	{
		if(H.last >= 2*t + 1)
		{
			if(H.arr[2*t] >= H.arr[2*t+1])
				mi = 2*t + 1;
			else
				mi = 2*t;
		}
		else
			mi = 2*t;
		if(H.arr[t] > H.arr[mi])
		{
			int c = H.arr[mi];
			H.arr[mi] = H.arr[t];
			H.arr[t] = c;
			t = mi;
		}
		else break;
	}
	return x;
}
				 
		


