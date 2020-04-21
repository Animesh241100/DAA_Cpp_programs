


#include<stdio.h>
#include<stdlib.h>

#define hsize 10

struct node
{
	int data;
	struct node * nptr;
};

struct node * HashTable[hsize];
int hash(int key);
void Insert(int x);
void Delete(int x);
void Search(int x);
void Print();


void main()
{
	int m, n, d, s;
	for(int i = 0; i<hsize; i++)
		HashTable[i] = NULL;
	printf("\nEnter  no. of nodes to be inserted\n");
	scanf("%d", &m);
	printf("\nEnter nodes to be inserted\n");
	for(int i = 0; i<m; i++)
	{
		scanf("%d", &n);
		Insert(n);
	}
	printf("The HashTable is\n");
	Print();
	printf("\nEnter a node to be DELETED\n");
	scanf("%d", &d);
	Delete(d);
	printf("\nEnter a node to be SEARCHED\n");
	scanf("%d", &s);
	Search(s);
	printf("The HashTable is\n");
	Print();
	
}
	
	
	
int hash(int key)
{
	return key % hsize;
}

void Insert(int x)
{
	struct node * temp = (struct node *)malloc(sizeof(struct node));
	temp->data = x;
	temp->nptr = HashTable[hash(x)];
	HashTable[hash(x)] = temp;
}

void Delete(int x)
{
	int f = 0;
	struct node * thptr = HashTable[hash(x)];
	if((thptr->nptr)!= NULL)
	{
		while( (((thptr->nptr)->data) != x) && (thptr!=NULL)) 
			thptr = thptr->nptr;
			
		if(thptr == NULL)
			f = 0;
		else
		{
			thptr->nptr = (thptr->nptr)->nptr;
			f =1;
		}
	}
	else
	{
		if(thptr->data == x)
		{
			HashTable[hash(x)] = NULL;
			f = 1;
		}
		
	}
	if(f == 1)
		printf("\n%d is deleted\n", x);
	else
		printf("\n%d doesn't exist in the table\n", x);
}

void Search(int x)
{
	int flag = 0;
	struct node * thptr = HashTable[hash(x)];
	while(thptr != NULL)
	{
		if(thptr->data == x)
		{
			flag = 1;
			break;
		}
		thptr = thptr->nptr;
	}
	if(flag == 1)
		printf("\n%d is found\n", x);			
	else
		printf("\n%d is not found\n", x); 
}

void Print()
{
	for(int i = 0; i<hsize; i++)
	{
		struct node * thptr = HashTable[i];
		while(thptr != NULL)
		{
			printf("\t%d", thptr->data);
			thptr = thptr->nptr;
		}
		printf("\n");
	}
}
