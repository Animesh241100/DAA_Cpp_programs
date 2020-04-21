#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node * nptr;
};

struct node * int1 = NULL;
struct node * int2 = NULL;



int c=0;
struct node * add = NULL;
struct node * zero = NULL;

int Length(struct node * ptr);
void Print(struct node * ptr);
void ReversePrint(struct node * ptr);
struct node * Get(struct node * ptr);
struct node * Insert(struct node * ptr, int x);
void Addition(struct node * p1, struct node * p2);

void main()
{
	printf("Enter the first integer, and enter 11(don't press enter between 1 and 1) to stop inserting the digits in the integer\n");
	int1 = Get(int1);
	printf("Enter the Second integer, and enter 11(don't press enter between 1 and 1) to stop inserting the digits in the integer\n");
	int2 = Get(int2);
	printf("The subtraction is\n");
	Addition(int1, int2);     //Subtraction result is automatically reversed so no need to use ReversePrint function
	Print(add);
	printf("First integer was\n");
	ReversePrint(int1);   /*int1 and int2 atck are by default reverse ordered so we need a ReversePrint fn. to 
					reverse them and then print them.*/
	printf("Second integer was\n");
	ReversePrint(int2); /*Remember ReversePrint fn. messes up with the top pointer of the stack, so we use it after all the operations are over.*/
}

void Addition(struct node * p1, struct node * p2)
{
	struct node * t1 = p1;
	struct node * t2 = p2;
	if(Length(p1) == Length(p2))   //Comparing Lengths of them
	{
		while(t1!=NULL)
		{
			add = Insert(add, ((t1->data)+(t2->data)+c)%10);
			c = ((t1->data)+(t2->data)+c)/10;
			t1 = t1->nptr;
			t2 = t2->nptr;
		}
		if(c==1)
			add = Insert(add, 1);
			
	}
	else if(Length(p1) > Length(p2))
	{
		for(int i=0; i <= (Length(p1)-Length(p2)-1); i++)
			zero = Insert(zero, 0);
		while(t2->nptr != NULL)
			t2 = t2->nptr;
		t2->nptr = zero;
		Addition(p1,p2);
	}
	else
		Addition(p2, p1);
}

struct node * Insert( struct node * ptr, int x)
{
	struct node * temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->nptr = ptr;
	ptr = temp;
	return ptr;
}

struct node * Get(struct node * ptr)
{
	int a=0;
	while( (a>=0) && (a<10) )
	{
		scanf("%d", &a);
		if((a>=0) && (a<10))
			ptr = Insert(ptr, a); 
	}
	return ptr;
}	

void Print(struct node * ptr)
{
	struct node * thptr = ptr;
	
	while(thptr!=NULL)
	{
		printf("%d", thptr->data);
		thptr = thptr->nptr;
	}
	printf(" \n");
}

void ReversePrint(struct node * ptr)
{
	struct node * thptr = ptr;
	struct node * key;
	struct node * tptr; 
	while((thptr->nptr)!=NULL)
		thptr = thptr->nptr;
	key = thptr;			//Now, thptr(and key) holds the address of node at the next end(MSB)
	while(thptr!=ptr)
	{
		tptr = ptr;
		while((tptr->nptr)!= thptr)
		{
			tptr = tptr->nptr;
		}
		thptr->nptr = tptr;
		thptr = thptr->nptr;
	}
	thptr->nptr = NULL;
	thptr = key;
	while(thptr!=NULL)
	{
		printf("%d", thptr->data);
		thptr = thptr->nptr;
	}
	printf(" \n");
}
int Length(struct node * ptr)
{
	int count = 0;
	struct node * thptr = ptr;
	while(thptr!=NULL)
	{
		count++;
		thptr = thptr->nptr;
	}
	return count;
}
