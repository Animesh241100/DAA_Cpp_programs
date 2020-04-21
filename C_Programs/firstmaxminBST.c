//Erronious code, please check firstmin and firstmax definitions
#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node* lptr;
	int data;
	struct node* rptr;
};
// create an empty tree
struct node* tptr = NULL;
void firstmin(struct node *ptr);
void firstmax(struct node *ptr);
void insert(int x);
void main()
{
	insert(70);
	insert(60);
	insert(80);
	insert(50);
	insert(65);
	insert(75);
	insert(55);
	printf("tHE FIRST AND sECOND min are\n");
	firstmin(tptr);
	printf("\n");
	printf("tHE FIRST AND sECOND max are\n");
	firstmax(tptr);
	printf("\n");
}
void insert(int x)
{
// create node
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->lptr = temp->rptr = NULL;
//	insert the first node
	if(tptr == NULL)
		tptr = temp;
// insert non-first node	
	else
	{
		struct node* ptr = tptr;
		struct node* pptr = NULL;		
		while(ptr != NULL)
		{
			pptr = ptr;
			if(x<(ptr->data))
				ptr = ptr->lptr;
			else 
				ptr = ptr->rptr;
		}
		if(x<pptr->data)
			pptr->lptr = temp;
		else 
			pptr->rptr = temp;
	}
}
void firstmin(struct node *ptr)
{
	struct node *pptr = ptr;
	while((pptr->lptr)!=NULL)
  	{
  		pptr=pptr->lptr;
  	}
  	printf("%d, ", pptr->data);
  	firstmin(pptr->rptr);
}
void firstmax(struct node *ptr)
{ 	
	struct node *pptr = ptr;
	while((pptr->rptr)!=NULL)
  	{
  		pptr=pptr->rptr;
  	}
  	printf("%d, ", pptr->data);
  	firstmax(pptr->lptr);
}
