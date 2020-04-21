#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node* lptr;
	int data;
	struct node* rptr;
};

struct node* tptr = NULL;
int main()
{
	int n;
	printf("Enter the array size :");
	scanf("%d",&n);	
	insert(20);
	insert(30);
	insert(40);
	insert(10);
	insert(27);
	insert(200);
	insert(80;
	insert(100);
	max

void insert(int x)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->lptr = temp->rptr = NULL;
	if(tptr == NULL)
		tptr = temp;	
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

int max(struct node * ptr)
{
	if(ptr == NULL)
	{
		// no tree;
	}
	else
	{
		comp = ptr->data;
		l = max(ptr->lptr);
		r = max(ptr->rptr);
		if(comp < l)
			comp = l;
		else if(comp < r)
			comp = r;
		return comp;
	}
	return(comp);
}
void treesort(struct node* ptr, int n)
{
	
	int a[n];
	for(int i = 0;i < n;++i)
	{
		scanf("%d",&a[i]);
		insert(a[i]);
	}
	inorder(tptr,n);
}
void inorder(struct node* ptr,int)
{
	if(ptr != NULL)
	{
		inorder(ptr->lptr);
		printf("%d ",ptr->data);
		inorder(ptr->rptr);
	}
}
