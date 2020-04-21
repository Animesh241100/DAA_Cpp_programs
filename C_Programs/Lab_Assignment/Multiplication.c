#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node * nptr;
};

int c = 0;
struct node * int1 = NULL;
struct node * int2 = NULL;
struct node * mul = NULL;   //head of final answer
struct node * zero = NULL;

struct node * ZeroRight(struct node * ptr); //adds 1 zero at right end(LSB)
struct node * ZERO(struct node * p1, struct node * p2); //adds sufficient zeros st left end(MSB)
struct node * Addition(struct node * p1, struct node * p2, struct node * a);
struct node * Product(struct node * m, struct node * ptr, int x);
struct node * Insert( struct node * ptr, int x);
struct node * Get(struct node * ptr);
void Multiplication(struct node * p1, struct node * p2);
struct node * Reverse(struct node * ptr);
void Print(struct node * ptr);
int Length(struct node * ptr);

void main()
{
	printf("Enter the first integer, and enter 11(don't press enter between 1 and 1) to stop inserting the digits in the integer\n");
	int1 = Get(int1);
	printf("Enter the Second integer, and enter 11(don't press enter between 1 and 1) to stop inserting the digits in the integer\n");
	int2 = Get(int2);
	printf("The Multiplication is\n");
	Multiplication(int1, int2);
	Print(mul);
	printf("First integer was\n");
	int1 = Reverse(int1);
	Print(int1);
	printf("Second integer was\n");
	int2 = Reverse(int2);
	Print(int2);
}
struct node * Product(struct node * m, struct node * ptr, int x)// (answer to be stored in stack, input stack, integer to multiply)
{
	m = NULL;
	int car = 0; 
	int temp;
	struct node * t1 = ptr;
	while(t1!=NULL)
	{
		temp = (t1->data)*x+car;
		m = Insert(m, temp%10);
		car = temp/10;
		t1 = t1->nptr;
	}
	if(car!=0)
		m = Insert(m, car);
	//this stack is opposite of ptr stack
	return (Reverse(m));
}


void Multiplication(struct node * p1, struct node * p2)
{
	int i = 0;
	struct node * t1 = p1;
	struct node * t2 = p2;
	struct node * l2 = NULL;
	struct node * temp = NULL;
	struct node * temp2 = NULL;
	struct node * ptr = NULL;  //Useless but useful
	while(t2!=NULL)
	{
		
		l2 = Product(l2, t1, t2->data);
		int j = 0;
		while(j!=i)
		{
			l2 = ZeroRight(l2);
			j++;
		}
		temp2 = Reverse(mul);
		temp = Addition(temp2, l2, temp);
		mul = temp;
		t2=t2->nptr;
		i++;
	}

}

struct node * Addition(struct node * p1, struct node * p2, struct node * a)
{
	a = NULL;
	struct node * t1 = p1;
	struct node * t2 = p2;
	if(p1==NULL)
		return Reverse(p2);
	else if(p2==NULL)
		return Reverse(p1);
	if(Length(p1) == Length(p2))   //Comparing Lengths of them
	{
		while(t1!=NULL)
		{
			a = Insert(a, ((t1->data)+(t2->data)+c)%10);
			c = ((t1->data)+(t2->data)+c)/10;
			t1 = t1->nptr;
			t2 = t2->nptr;
		}
		if(c==1)
			a = Insert(a, 1);
			
	}
	else if(Length(p1) > Length(p2))
	{
		p2 = ZERO(p1, p2); //Inserting zeroes at the left to make lengths equal
		a = Addition(p1, p2, a);
	}
	else
		a = Addition(p2, p1, a);
	return (a);
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
		if((a==0)||(a==1)||(a==2)||(a==3)||(a==4)||(a==5)||(a==6)||(a==7)||(a==8)||(a==9))
			ptr = Insert(ptr, a); 
	}
	return ptr;
}	

struct node * ZERO(struct node * p1, struct node * p2)//  Here, Length(p1) must be larger than Length(p2)
{
	zero = NULL;
	struct node * t2 = p2;
	for(int i=0; i <= (Length(p1)-Length(p2)-1); i++)
		zero = Insert(zero, 0);
	while(t2->nptr != NULL)
		t2 = t2->nptr;
	t2->nptr = zero;
	return p2;
}

struct node * ZeroRight(struct node * ptr)
{
	ptr = Insert(ptr, 0);
	return ptr;
}
	
struct node * Reverse(struct node * ptr)
{
	if(ptr!=NULL)
	{
		struct node * thptr = ptr;
		struct node * key;
		struct node * tptr; 
		while((thptr->nptr)!=NULL)
			thptr = thptr->nptr;
		key = thptr;			//Now, thptr(and key) holds the address of MSB
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
		return key;
	}
	else
		return NULL;
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
