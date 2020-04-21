#include<stdio.h>
#include<stdlib.h>
int arr[100];
struct node
{
	int data;
	struct node* lptr;
	struct node* rptr;
};
struct node* thptr;
int count=0;
void insert(int x)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->lptr=NULL;
	temp->lptr=NULL;
	if(thptr==NULL)
		thptr=temp;
	else
	{
		struct node* ptr=thptr;
		struct node* pptr=NULL;
		while(ptr!=NULL)
		{
			pptr=ptr;
			if(x<ptr->data)
				ptr=ptr->lptr;
			else
				ptr=ptr->rptr;
		}
		if(x<pptr->data)
			pptr->lptr=temp;
		else
			pptr->rptr=temp;
	}
}
void Inorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		Inorder(ptr->lptr);
		printf("%d ",ptr->data);
		arr[count]=ptr->data; //global array arr stores the key values in the inorder traversal
		count++;
		Inorder(ptr->rptr);
	}
}
int main()
{
	int n,i;
	printf("Enter the number of elements to be entered:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int data;
		scanf("%d",&data);
		insert(data);
	}
	Inorder(thptr);	
	printf("\nMin:%d\n\nsecmim:%d \nMax:%d\nsecond maximum %d",arr[0],arr[1],arr[n-1],arr[n-2]);
	return 0;
}
