#include<stdio.h>
#include<stdlib.h>
int vertex[1000];
int arr[1000][1000];
int l;
int cycle = 0;
int visit[1000];
void Insert();
void Print();
void DFS(int x);

void main()
{
	int n=0;
	int f=0;
	int part=1;
	int d;
	printf("enter no. of nodes\n");
	scanf("%d", &n);
	l = n;
	//int vertex[n];
	//int arr[n][n];
	printf("enter all the vertices constituting the graph\n");
	for (int i = 0; i<n; i++)
	{
		scanf("%d", &vertex[i]);
	}
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			if((arr[j][i]!=1)&&(vertex[i]!=vertex[j]))
			{
				printf("Enter 1 if link exists between %d and %d, else enter 0\n", vertex[i], vertex[j]);
				scanf("%d", &arr[i][j]);
				arr[j][i] = arr[i][j];
			}
			else if(vertex[i] == vertex[j])
				arr[i][j] = 0;
		}
	}
	
	c1:printf("Enter 1 to insert a new node, else 0\n");
	scanf("%d", &f);
	if(f==1)
	{
		Insert();
		goto c1;
	}
	Print();
	printf("Enter vertex for DFS\n");
	scanf("%d", &d);
	DFS(d);
	for (int i = 0; i < l; i++)
	{
		if(visit[i] == 0)
		{
			DFS(vertex[i]);
			part++;
		}
		
	}
	if(part!=1)
		printf("Graph is not connected and has %d parts\n", part);
	else
		printf("Graph is connected\n");
	/*if(cycle==0)
		printf("Graph is not cyclic\n");
	else
		printf("Graph is cyclic\n");*/
}

void Print()
{
	for (int i = 0; i<l; i++)
	{
		for (int j = 0; j<l; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
void Insert()
{
	int v;
	printf("Enter a new node to be inserted\n");
	scanf("%d", &v);
	vertex[l] = v;
	for (int i = 0; i<l; i++)
	{
		if(vertex[i] == vertex[l])
			arr[i][l] = 0;
		else
		{
			printf("Enter 1 if link exists between %d and %d, else enter 0\n", vertex[i], vertex[l]);
			scanf("%d", &arr[i][l]);
			arr[l][i] = arr[i][l];
		}
	}
	l++;
}

void DFS(int x)
{
	int temp;
	for (int i = 0; i < l; i++)
	{
		if(x == vertex[i])
			temp = i;  //getting the index of the 'x' in temp from the vertex array
	}
	
	visit[temp] = 1;
	printf("%d\n", x);
	//printf("hi%d\n", l);
	for(int i = 0; i < l; i++)
	{
		if(visit[i]!=1)  //Look at unvisited nodes
		{
			if(arr[temp][i] == 1)	//Link exists b/w 'x' and and the vertex at ith position.
			{
				DFS(vertex[i]);
			}
		}
		else
			cycle=1;
	}
	
}
