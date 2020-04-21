#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;       // data will hold the value of current node
	struct node *nptr; // nptr will hold the address of the next node
};
struct node *hptr=NULL;   //hptr is intialised to NULL, because the list is empty, no head 					node exists.
void insert(int x,int pos);
int search(int x);
int delete(int pos);
void print();
void reverse();
int main()
{
	insert(2,0);	
	insert(20,1);
	insert(10,1);
	insert(12,3);
	insert(23,1);
	insert(25,0); 
	insert(5,4);
	insert(9,4);
	insert(15,4);	
	reverse();
	/*print();
	
	printf("\n%d\n",search(-40));
	printf("\n%d\n",delete(0));*/	
	return 2110;
}
void insert(int x, int pos)
{
	struct node *temp =(struct node *) malloc(sizeof(struct node));//Creating new node and the address iof this new memoory chink will be stored in temp.
	int i=0;
	struct node *thptr=hptr;// thptr is a copy of hptr which traverses through all the nodes of the list in order to access a particular node
	temp->data= x; //input data x has been stored in 'data' part of the new node created using malloc.
	if(pos==0) // i.e. list is empty, no previous node was there, the above created node was an isolated node, whose nptr will be holding NULL in it.
	{	
		temp->nptr= hptr; /*using temp we'll be acessing the new node, because it gholds the latest node's address. So, here we're storing the value of hptr('which is cureently NULL')to the 'nptr' part of temp(temp points to new node.)*/
		hptr=temp;	//now hptr is assigned the value of temp, i.e. now its holding the address of newly created node. The job of 'hptr'(HEAD POINTER) is is to hold the address of the first node and here the newly creatd node itself is the first node. 
	}	
	else
	{
		while(i<pos-1)	//unless thptr reaches the node,after the which the new node has to be inserted, keep moving ahead(Animesh says to thptr(which is a copy of hptr nothing else
		{		
			thptr=thptr->nptr; //Each time the loop runs the thptr is assigned the value of the nptr(value of nptr is nothing but the address of the next node{not new node, next node is that between whom and current node the new node has to be inserted}) part of the node whose address it is holding right now!, that is each time the 'thptr' is made pointing to the next node to which it is pointing to right now.
			i++; // traversing through the linked list
		}
		temp->nptr=thptr->nptr;// temp ke nptr me NULL hona chahiye and thptr->nptr me pehle se hi NULL stored hai.
		thptr->nptr=temp; //Now thptr->nptr(matlab pos-1 wala node{that is node which is our current node, after which new node has to be inserted} ka nptr) is holding the address of the new node.
	}
	
}
void print()
{
	struct node *thptr = hptr; // thptr is a copy of hptr(head pointer)
		
	while(thptr != NULL) // keep traversing unless you holde nothing(NULL)
	{
		printf("%d\t",thptr->data); //accessing the data part of the current node(to which the thptr is pointing right now) using pointer variable thptr
		thptr = thptr -> nptr; // thptr is  made pointing to the next node to the current node until it reaches the last node(i.e. it holds the address NULL or points to the last node
	}
}


int search(int x)

{
	struct node *thptr = hptr;// thptr is a copy of hptr(head pointer)
	int flag=0;	
	while(thptr != NULL) // until you reach at last node
	{
	
	   if(x==thptr->data)	// if x equals the data part of the current node	
	  {  
		  flag=1;	
	     break;
	  }		
	thptr = thptr -> nptr;// this is our increment statement, each time thptr is made pointing to the next node to which it is pointing right now
	} 
	return flag;
}


int delete(int pos)
{
	int x; // we want to return the value which is going to be deleted
	struct node *thptr=hptr;// thptr is a copy of hptr(head pointer)
	if(pos==0)
	{	x=hptr->data;  /* 	x holds the going to be deleted value.
	Note that here we're accessing the node using 'hptr', here there is no need of 'thptr', as there is nothing to be traversed. */
		hptr=hptr->nptr;/*	THE MOST IMPORTANT STEP, this is the only place whrer the value of hptr is being changed, this time hptr is made pointing to next node( as the next node is the head node now, so HEAD POINTER hptr must point to head node*/ 
	}
	else	
	{
		int i=0;	
		while(i<pos-1) // unless you reach the node just before the node which needs to be deleted 
			{
				thptr=thptr->nptr; //to traverse the thptr
				i++;
			}
		x=(thptr->nptr)->data; /*thptr->nptr means a new pointer which has the address of the next node(the node to be deleted), 
		thptr ===> says we're pointing at the pos-1 th node
		thptr->nptr ===> says we're pointing to next node that is pos node
		(thptr->nptr)->data ===> says we're accessing the data part of the pos node(to be deleted node),that is next node of the node to which we're right now pointing at.*/
		thptr->nptr=(thptr->nptr)->nptr;  /* 
		even now the definition of thptr,thptr->nptr are exactly the same as above
		
		the thptr->nptr stores the value stored in the 'nptr' part of the 'to be deleted pos node('THAT IS THE ADDRESS OF THE NEXT NODE OF THE TO BE DELETED NODE, i.e. ADDRESS OF THE pos+1 th NODE') */
	
	}
return x; // returns deleted value
}


int isempty()
{
	if(hptr==NULL)   // for list to exist hptr has to point to head pointer's address
		return 1;
	else
		return 0;
}

int isfull()
{
	struct node*temp=(struct node*)malloc(sizeof(struct node));// we create a brand new node to check if the malloc returns any address value or not
	if(temp==NULL)
		return 1;
	else
		return 0;
}

void reverse()      //for reversing the whole linked lidt
{
	printf("\nbefore reverse\n",☦️);
	print();
	struct node *current = hptr;   
	struct node *next = NULL;
	struct node *prev = NULL;
	while(current != NULL)
	{
		next = current->nptr;
		current->nptr = prev;
		prev = current;
		current = next;
	}
	hptr = prev;          //updating hptr 
	printf("\nafter reverse\n");
	print();
}
	 
	
