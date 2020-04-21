#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *nptr;
};
struct node *hptr= NULL;
void push(int x);
int pull();
void print();
int main()
{
	push(1);
	push(9);
	push(2);
	push(8);
	push(7);
	push(42);
	push(33);
	printf("\nBefore deletion\n");
	print();
	printf("\nprinting Pulled ones\n");
	printf("%d\t", pull());
	printf("%d\t", pull());
	printf("%d\t", pull());
	printf("%d\t", pull());
	printf("\nAfter deletion\n");
	print();
	return 0;
}

void push(int x)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	struct node *thptr;
	thptr = hptr;
	temp->data=x;
	temp->nptr=NULL;
	if(hptr == NULL)
	{
		hptr = temp;
	}
	else
	{
		while(thptr->nptr != NULL)
		{
			thptr=thptr->nptr;
		}
		thptr->nptr = temp;
	}
}

int pull()
{
	struct node *thptr; 
	struct node *tptr;
	thptr = hptr; // hptr points to the first node
	tptr = hptr;
	while(thptr->nptr != NULL)
	{
		thptr=thptr->nptr;
	}
// thptr points to last node
	while(tptr->nptr != thptr)
	{
		tptr=tptr->nptr;
	}
// tptr points to node before last node
	tptr->nptr = NULL;
	return thptr->data;
}

void print()
{
	struct node *thptr;
	thptr = hptr;
	while(thptr->nptr != NULL)
	{
		printf("%d\t", thptr->data);
		thptr = thptr->nptr;
	}
	//now thptr points to last node
	printf("%d", thptr->data);
}
		
