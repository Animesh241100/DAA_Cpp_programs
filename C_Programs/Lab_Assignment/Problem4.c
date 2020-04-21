#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node* lptr;
	int data;
	struct node* rptr;
};

struct node* hptr = NULL;
void insert(int x);
void inorder(struct node* ptr);
void main()
{   
	int a;
    	printf("enter the total nodes of tree\n");
    	scanf("%d",&a);
 	int j[a];
   	printf("enter the post order\n");
   	for(int i=0;i<a;i++)
   		scanf("%d",&j[i]);
    	for(int k=a-1;k!=-1;k--)
  		insert(j[k]);
    	printf("Inorder Traversal of this tree\n");
	inorder(hptr);
	printf("\n");
}
void insert(int x)
{
// create node
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->lptr = temp->rptr = NULL;
//	insert the first node
	if(hptr == NULL)
		hptr = temp;
// insert non-first node
	else
	{
		struct node* ptr = hptr;
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
void inorder(struct node* ptr)
{
	if(ptr != NULL)
	{
		inorder(ptr->lptr);
		printf("%d ",ptr->data);
		inorder(ptr->rptr);
	}
}





