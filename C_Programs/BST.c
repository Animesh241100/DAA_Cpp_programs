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
void insert(int x);
void inorder(struct node* ptr);
void postorder(struct node* ptr);
void preorder(struct node* ptr);
void treesort();
void main()
{
/*	insert(70);
	insert(60);
	insert(80);
	insert(50);
	insert(65);
	insert(75);
	insert(55);

	inorder(tptr);
	printf("\nPost order ");
	postorder(tptr);
	printf("\nPre order ");
	preorder(tptr);
*/
	treesort();
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
void inorder(struct node* ptr)
{
	if(ptr != NULL)
	{
		inorder(ptr->lptr);
		printf("%d ",ptr->data);
		inorder(ptr->rptr);
	}
}
void postorder(struct node* ptr)
{
	if(ptr != NULL)
	{
		postorder(ptr->lptr);
		postorder(ptr->rptr);
		printf("%d ",ptr->data);
	}
}
void preorder(struct node* ptr)     
{
	if(ptr != NULL)
	{
		printf("%d ",ptr->data);
		preorder(ptr->lptr);
		
		preorder(ptr->rptr);
	}
}
void treesort()
{
	int n;
	printf("Enter the array size :");
	scanf("%d",&n);	
	int a[n];
	for(int i = 0;i < n;++i)
		scanf("%d",&a[i]);
	for(int i = 0; i<n ; ++i)
		insert(a[i]);
	inorder(tptr);
}
