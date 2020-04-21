#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int ma, secma;
struct node
{
	struct node* lptr;
	int data;
	struct node* rptr;
};

struct node* tptr = NULL;
int max(struct node * ptr);
void insert(int x);
int show1(int comp, int second);
int main()
{
	/*int n;
	printf("Enter the array size :");
	scanf("%d",&n);*/	
	insert(20);
	insert(3);
	insert(40);
	insert(10);
	insert(27);
	insert(20);
	insert(8);
	insert(1);
	max(tptr);
	printf("\nMax = %d", ma);
	//printf("\nsecondMax = %d\n", secma);
	return 0;
}
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
	int l, r, comp, second;
	if(ptr == NULL)
		return INT_MIN;
		
	second = comp;	
	comp = ptr->data;
	l = max(ptr->lptr);
	r = max(ptr->rptr);
	if(comp < l)
		comp = l;
	else if(comp < r)
		comp = r;
	/*printf("\nMax = %d", comp);
	printf("\nsecondMax = %d\n", second);
	*/
	ma = comp;
	secma = second;
	return (comp);
}
int show1(int comp, int second)
{
	printf("Max = %d\n Second max = %d", comp, second);
}
int min(struct node * ptr)
{
	int l, r, comp, second;
	if(ptr == NULL)
		return INT_MAX;
		
	second = comp;	
	comp = ptr->data;
	l = min(ptr->lptr);
	r = min(ptr->rptr);
	if(comp > l)
		comp = l;
	else if(comp > r)
		comp = r;
	printf("\nMin= %d", comp);
	printf("\nsecondMin = %d\n", second);
	return 0;
}
