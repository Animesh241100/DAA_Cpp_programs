#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *nptr;
};
struct node * shead = NULL;		//head node for or superset
struct node * s1h = NULL;		//head node for subset1
struct node * s2h = NULL;		//head node for subset2


//Prototypes of utility functions
struct node * insert(int x);
void Print(struct node * ptr);

void main()
{
	/*char a,c;
	printf("Enter the members of the superset\n");
	while(c!="n")
	{
		
		scanf("%d", &a);
		shead = Insert(shead, a);
		printf("Do you want to enter more members? y/n \n");
		scanf("%c ", &c);
	}*/
	insert(4);
	insert(9);
	insert(8);
	insert(18);
	insert(6);
	printf("The superset is\n");
	Print(shead);
	
}


struct node * insert(int x)
{
	struct node * temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	if(shead==NULL)
	{
		shead = temp;
		temp->nptr = NULL;
	}
	else
	{
		temp->nptr = shead;
		shead = temp;
	}
	return shead;
}
		
void Print(struct node * ptr)
{
	struct node * thptr = ptr;
	while(thptr!=NULL)
	{
		printf("%d\t", thptr->data);
		thptr = thptr->nptr;
	}
	printf("%d\n", thptr->data);
}

