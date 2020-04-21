#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * pptr; //Previous ptr
	struct node * nptr;// next ptr
};
struct node * hptr = NULL;
void Print();
void Insert(int x, int pos);
void Del(int pos);

int main()
{
	Insert(8, 0);
	/*Insert(30, 1);
	Insert(1, 2);
	Insert(25, 3);
	Insert(2, 4);
	Insert(20, 5);
	Insert(4, 6);
	Insert(120, 7);
	Print();
	Del(4);
	Print();
	Del(7);
	Print();
	Del(0);
	Print();
	Del(4);*/
	return 0;
	
	
}

void Insert(int x, int pos)
{
	struct node * thptr = hptr;
	struct node * temp = (struct node *)malloc(sizeof(struct node));
	
	
	if(hptr==NULL) //no Previously made node exists
	{
		
		temp->nptr = NULL;
		temp->pptr = NULL;
		hptr = temp;
	}
	else if(pos==0)   // inserting at the beginning
				     //Some Previously made nodes are there
	{
		temp->nptr = hptr;
		temp->pptr = NULL;
		hptr->pptr = temp;
		hptr= temp;
	}
	
	else         
	{
		/*while( thptr->nptr!= NULL )
		{
			thptr = thptr-> nptr;
		}*/
		for( int i=0; i<=pos-2; i++)
		{
			thptr = thptr-> nptr; 	
		} // thptr points at the node just before the position(pos) you want to insert the new node
		
		
		if(thptr->nptr != NULL)  // Real Insertion between two consecutive nodes
		{
			temp->nptr = thptr->nptr;// link from new node to its next node
			(thptr->nptr)->pptr=temp;// link from next node of new node to new 							node
			thptr->nptr=temp;//link from previous node of new node to new node
			temp->pptr=(thptr->pptr)->nptr; //link from new node to its previous 							node
		}
		
		else     //inserting at the end
		{
			thptr->nptr = temp;
			temp->pptr = (thptr->pptr)->nptr ;/*pptr of temp is assigned the 					value of 'nptr' (that is the address of last node), stored 					in the node previous to the last node ( which is being 					accesed using this '(thptr->pptr)->' ) */
			temp->nptr=NULL;
		}
	}	
	temp->data = x;
}

void Del(int pos)
{
	struct node * thptr;
	thptr=hptr;
	if(pos==0)  //Head node needs to be deleted
	{
		printf("\nThe deleted number is %d\n", hptr->data);
		hptr = hptr->nptr;
		hptr->pptr = NULL;
	}
	else
	{
		for( int i=0; i<=pos-2; i++)
		{
			thptr = thptr-> nptr; 	
		} // thptr points at the node just before last node  
		printf("\nThe deleted number is %d\n", (thptr->nptr)->data);
		if((thptr->nptr)->nptr = NULL) // last node needs to be deleted
		{
			(thptr->nptr)->pptr = NULL;
			thptr->nptr = NULL;
		}
		else // Real deletion between two consecutive nodes
		{
			thptr->nptr = (thptr->nptr)->nptr; //Link from Prev node to next one 
			(thptr->nptr)->pptr = (thptr->pptr)->nptr;
		//address of node to which thptr is currently Pointing is assigned to 'ppyr of next node to the deleted node. Link from Next to Prev is formed.
		}
	}
}

void Print()
{
	struct node * thptr;
	thptr=hptr;
	printf("Updtaed List is\t");
	while( thptr->nptr!= NULL )
	{
		printf("\t%d", thptr->data);
		thptr = thptr-> nptr;
	}
	//Now thptr points to the last node
	printf("\t%d", thptr->data);
}
		
			
		
		                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
