#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;      
	struct node *nptr; 
};
struct node * top1=NULL; //So we need two different head pointers to make two diffrent linked lists
struct node * top2=NULL;

struct node * sTop=NULL; //and one more storing the sum
struct node *tail1, *tail2;
 
void insert1(int x);
void insert2(int x);
void print(struct node * top);
void sum();
void Rev_print(struct node *key, struct node *top);
int main()
{
	
	insert1(1);	
	insert1(0);
	/*insert1(2);
	insert1(9);
	insert1(9);
	insert1(9);
	insert1(9);
	*/print(top1);
	Rev_print(tail1, top1);
	insert2(1);
	insert2(2);
	/*insert2(2);
	insert2(2);
	insert2(1);
	insert2(6);*/
	print(top2);		
	Rev_print(tail2, top2);
	sum();
	return 0;
}


//First Linkedlist
void insert1(int x)
{
	struct node * temp =(struct node *) malloc(sizeof(struct node));

	temp->data= x; 
	if(top1 == NULL) 
	{
		top1 = temp;
		tail1 = temp; //so tail1 will always be pointing to the MSD of the no.     
		top1->nptr = NULL;	      //first digit stored and made pointing to NULL 
	}
	else
	{
		temp->nptr = top1; //new node made pointing to top1 wala node
		top1 = temp;  //top1 is shifted to new node, hence always holding the address of LSD of the integer
	}
	 /*		1<-----2<-----3<-----4<-----6<----top1
	 		1<-----2<-----3<-----4<-----6<-----8<----top1          */
}

//Second Linkedlist
void insert2(int x)
{
	struct node *temp =(struct node *) malloc(sizeof(struct node));
	temp->data= x; 
	if(top2 == NULL) 
	{
		top2 = temp;
		tail2 = temp;     //so tail2 will always be pointing to the MSD of the no.
		top2->nptr = NULL;	      //first digit stored and made pointing to NULL 
	}
	else
	{
	 	temp->nptr = top2; //new node made pointing to top2 wala node
		top2 = temp;  
	}
}
void print(struct node * top)
{
	struct node * thptr = top; 	
	printf("\nprinting\n");
	while(thptr->nptr != NULL) 
	{
		printf("%d", thptr->data);
		thptr = thptr->nptr; 
	}    //now thptr points to the first digit of the integer
	printf("%d", thptr->data); //printing first digit
} 

void sum()
{
	int car = 0;
	struct node *thptr1 = top1;
	
	struct node *thptr2 = top2;
	struct node *thptr3 = sTop;
	struct node *tptr = sTop; //pointer needed to store the value of sTop(SEQUENCE REVERSAL)
	struct node *key; //pointer needed to store the value of sTop(SEQUENCE REVERSAL)
	struct node * stemp = (struct node *)malloc(sizeof(struct node*));//last digit gets created
	sTop = stemp;
	thptr3 = sTop;
	stemp->nptr = NULL;
	stemp->data = (thptr1->data + thptr2->data)%10;
	car = ((thptr1->data + thptr2->data) - (thptr1->data + thptr2->data)%10)/10; 	//this carry propogates through next 'while' loop and gets updated in every iteration
	
	while(((thptr1->nptr)!= NULL) && ((thptr2->nptr)!= NULL))
	{
		thptr1=thptr1->nptr;
		thptr2=thptr2->nptr;
		struct node * stemp = (struct node *)malloc(sizeof(struct node*)); 
		thptr3->nptr = stemp; //link formed between new node and previous
		thptr3 = stemp;  //now,the new node becomes the previous node for the newcomer node in next iteration(so this is the step in which the thptr3 is made to traverse like thptr1 & thptr2).
		stemp->data = (thptr1->data + thptr2->data + car)%10;	 //data insertion in new node based on the current values in top1 and top2 at the same place value an the previous carry .
		stemp->nptr = NULL;
		car = ((thptr1->data + thptr2->data + car) - (thptr1->data + thptr2->data + car)%10)/10; 				// CARRY UPDATION in every iteration.
		
	}
	if(((thptr1->nptr)== NULL) && ((thptr2->nptr)== NULL))
	{
		struct node * stemp = (struct node *)malloc(sizeof(struct node*));
		stemp->data = car;
		stemp->nptr = NULL;
		thptr3->nptr = stemp; //link formed between new node and previous
		thptr3 = stemp; 
	}
		
	while((thptr1->nptr)!= NULL)
	{
		thptr1=thptr1->nptr;
		struct node * stemp = (struct node *)malloc(sizeof(struct node*));
		stemp->nptr = NULL;
		stemp->data = (thptr1->data + car)%10;
		car = ((thptr1->data + car) - (thptr1->data + car)%10)/10; 
		thptr3->nptr = stemp; //link formed between new node and previous
		thptr3 = stemp;
		
	}
	while((thptr2->nptr)!= NULL)
	{
		thptr2=thptr2->nptr;
		struct node * stemp = (struct node *)malloc(sizeof(struct node*));
		stemp->nptr = NULL;
		stemp->data = (thptr2->data + car)%10;
		car = ((thptr2->data + car) - (thptr2->data + car)%10)/10; 
		thptr3->nptr = stemp; //link formed between new node and previous
		thptr3 = stemp;
		
	}
	printf("\nSum without new reverse function\n");
	print(sTop);
	
	//SEQUENCE REVERSAL
	
//So, here,'key' will always be storing the address of the first digit of the sum and 'sTop' stores the address of the last digit.

/*	key = thptr3;  // thptr3 always pointed to the newest node, that's the MSD of the no.
	while(thptr3!=sTop)
	{
		tptr = sTop;
		while((tptr->nptr)!= thptr3)
		{
			tptr = tptr->nptr;
		}
		thptr3->nptr = tptr;
		thptr3 = thptr3->nptr;
	}
	thptr3->nptr = NULL;
	//at the end the 'key' will be pointing to the MSD(most sig.digit) and the sequence has got reversed now. So, in order to print the number we need to give 'key' as an arguement to the print function. /*
	/*printf("\nSum with new reverse function\n");
	print(key);*/
}	

void Rev_print(struct node *key,struct node *top)
{
	struct node * thptr = key; //key(tail) forever points to the MSD.
	struct node * tptr; 
	thptr = key;  // thptr always points to the MSD of the no.
	while(thptr!=top)
	{
		tptr = top;
		while((tptr->nptr)!= thptr)
		{
			tptr = tptr->nptr;
		}
		thptr->nptr = tptr;
		thptr = thptr->nptr;
	}
	thptr->nptr = NULL;
		//As the sequence has got reversed,now in order to print the number we will use 'key' to access all the nodes as before we were using 'top' to access all other nodes /**/
	printf("\nwith new reveprint function\n");
	thptr = key;
	while(thptr->nptr != NULL) 
	{
		printf("%d", thptr->data);
		thptr = thptr->nptr; 
	}    //now thptr points to the first digit of the integer
	printf("%d", thptr->data); //printing first digit
}
