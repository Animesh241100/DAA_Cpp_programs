#include<stdio.h>
#include<stdlib.h>

struct node 
{
	struct node *lptr;
	int data;
	struct node *rptr;
};

struct node * hptr=NULL;

struct node *insert(int in[],int post[],int beg,int end,int *Pindex);

int search(int in[],int start,int fin,int x);

void inorder(struct node * ptr)
{
	if(ptr==NULL)
		return;
	inorder(ptr->lptr);
	printf("%d ",ptr->data);
	inorder(ptr->rptr);
}

int main()
{
	//int in[]={4,10,12,15,18,22,24,25,31,35,44,50,66,70,90};
	//int post[]={4,12,10,18,24,22,15,31,44,35,66,90,70,50,25};
	int a;
    	printf("enter the total nodes of tree\n");
    	scanf("%d",&a);
    	
    	int in[a];
   	printf("enter the inorder\n");
   	for(int i=0;i<a;i++)
   		scanf("%d",&in[i]);
   		
 	int post[a];
   	printf("enter the postorder\n");
   	for(int i=0;i<a;i++)
   		scanf("%d",&post[i]);
   		
   		
	int Pindex = a-1;
	//hptr = insert2(in,post, 0, a-1, Pindex);
	hptr = insert(in,post, 0, a-1, &Pindex);
	printf("Inorder Traversal of the constructed tree is\n");
	inorder(hptr);
	printf(" \n");
	return 0;
}

int search(int arr[], int strt, int end, int value) 
{ 
    int i; 
    for (i = strt; i <= end; i++)
    { 
        if (arr[i] == value) 
            break; 
    } 
    return i; 
} 

struct node *insert(int in[],int post[],int beg,int end,int *pindex)
{
	if(beg>end) 
        	return NULL; 
   	struct node *temp;
   	temp=(struct node *)malloc(sizeof(struct node));
   	temp->data=post[*pindex];
    	(*pindex)--; 
  
    	if (beg == end) 
        	return temp; 
  

    	int iIndex = search(in, beg, end, temp->data); 
  
   
   	temp->rptr = insert(in, post, iIndex + 1, end, pindex); 
    	temp->lptr = insert(in, post, beg, iIndex - 1, pindex); 
  
    	return temp;
}

