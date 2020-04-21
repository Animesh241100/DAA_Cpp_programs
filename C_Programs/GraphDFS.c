#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * nptr;
};

struct node * top = NULL;
int visit[1000];
int arr[1000][1000];

void Push(int x);
int Pop();
void PrintS();
void Print();
void Insert(int x);
void DFS(int v, int l);

void main()
{
	int n,d,f=0;
	int cycle = 0;
	int connect = 1;
	printf("Enter the no. of nodes\n");
	scanf("%d", &n);
	Insert(n);
	Print(n);
	p: printf("Enter the node to start DFS from\n");
	scanf("%d", &d);
	DFS(d, n);
	printf("\nThe visit array:\n");
	for (int j = 0; j < n	; j++)
	{
		if(visit[j]>1)
			cycle = 1;
		else if(visit[j]==0)
			connect = 0;
		printf("%d ", visit[j]);
	}
	if(cycle == 1)
		printf("\nGraph is containing cycle(s)\n");
	else
		printf("\nGraph is not containing cycle(s)\n");	
	if(connect == 0)
		printf("\nGraph is Disconnected\n");
	else
		printf("\nGraph is connected\n");	
	printf("\nEnter 1 to DFS again\n");
	scanf("%d", &f);
	if(f==1)
	{
		for (int j = 0; j < n; j++)
		{
			visit[j] = 0; //resetting the visit array
		}
		goto p;  //label to 30th line.
	}
}
	
void Insert(int x)
{	
	int a;
	for(int i=0; i<x; i++)
	{
		for(int j=0; j<x; j++)
		{
			if(arr[j][i]!=1)
			{
				if((i>=j))
					arr[i][j] = 0;	
				else
				{
					printf("Enter 1 if link exists between %d and %d, else enter 0\n", i, 							j);
					scanf("%d", &a);
					if(a==0)
						arr[i][j]=0;
					else
						arr[i][j]=1;
				}		
			}
			else
				arr[i][j] = 1;
		}
	}
}

void Push(int x)
{
	struct node * temp = (struct node *)malloc(sizeof(struct node));
	temp->data = x;
	temp->nptr = top;
	top = temp;
}

int Pop()		//returns (-1) when nothing to pop(Stack is empty)
{
	if(top!=NULL)
	{
		int x = top->data;
		top = top->nptr;
		return x;
	}
	else
		return (-1);
}



void Print(int l)
{
	printf("The nodes are:\n");
	for (int j = 0; j<l; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	printf("The matrix is:\n");
	for (int i = 0; i<l; i++)
	{
		for (int j = 0; j<l; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void PrintS()
{
	struct node * thptr = top;
	while(thptr!=NULL)
	{
		printf("%d ", thptr->data);
		thptr = thptr->nptr;
	}
	printf("\n");
}


void DFS(int v, int l)
{
	int p;
	int count = 0;
	int flag = 0;
	visit[v] = visit[v] + 1;
	printf("%d\t", v);
	for (int i = 0; i<l; i++)
	{
		if((arr[v][i]==1) && (visit[i]<1)) //PUSHED IN all the unvisited adjacent vertices
			Push(i);		
	}
	
	while(top!=NULL)
	{
		p = Pop();
		visit[p] = visit[p] + 1;
		printf("%d\t", p);
 		for (int j = 0; j<l; j++)
		{
			if((arr[p][j]==1) && (visit[j]<1))
				Push(j);
		}
	}

}	

