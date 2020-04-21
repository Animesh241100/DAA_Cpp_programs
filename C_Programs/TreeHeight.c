#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node* lptr;
	int data;
	struct node* rptr;
};
int z = 0;		//for height of the tree
int l = 0;  		//for no. of leaves
int count = 0;  // for total no. of nodes
struct node* tptr = NULL;
void insert(int x);
int height(struct node* ptr);	//for height of the tree
void leaf(struct node* ptr);	//for no. of leaves
void Number(struct node* ptr); // for total no. of nodes
void main()
{
	insert(70);
	insert(60);
	insert(80);
	insert(50);
	insert(90);
	insert(55);
	insert(75);
	insert(65);
	Number(tptr);
	leaf(tptr);
	printf("Number of nodes is %d\n", count);
	printf("Height is %d\n", height(tptr));
	printf("Number of leaves is %d\n", l);
	

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
			if(x<ptr->data)
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

int height(struct node* ptr)
{
	if(ptr != NULL)
	{
		if((height(ptr->lptr)) >= (height(ptr->rptr)))
			z = height(ptr->lptr)+1;
		else
			z = height(ptr->rptr)+1;
		return z;
	}
	else
		return -1;
	
}
void Number(struct node* ptr)
{

	if(ptr != NULL)
	{
		Number(ptr->lptr);
		count++;
		Number(ptr->rptr);
	}
}

void leaf(struct node* ptr)
{
	if(ptr != NULL)
	{
		leaf(ptr->lptr);
		if((ptr->lptr)==NULL && (ptr->rptr)==NULL)
			l++;
		leaf(ptr->rptr);
	}
}	

	
