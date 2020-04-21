#include<stdio.h>
#include<stdlib.h>

struct node
{
	char word;
	char mean;
	int height;
	struct node *lptr;
	struct node *rptr;
};

struct node * Right(struct node * ptr)
{
	struct node * xptr = ptr;
	struct node * yptr = ptr->lptr;
	xptr->lptr = yptr->rptr;
	yptr->rptr = xptr;
	return yptr;
}
struct node * Left(struct node * ptr)
{
	struct node * xptr = ptr;
	struct node * yptr = ptr->rptr;
	xptr->rptr = yptr->lptr;
	yptr->lptr = xptr;
	return yptr;
}

struct node * RightLeft(struct node * ptr)
{
	ptr->rptr = Right(ptr->rptr);
	return Left(ptr);
}

struct node * LeftRight(struct node * ptr)
{
	ptr->lptr = Left(ptr->lptr);
	return Right(ptr);
}

int Height(struct node *ptr)
{
	int lh,rh;  //lh & rh are ehights of the right and left nodes respectively
	if(ptr == NULL)    //not even single node exists
		return -1;
	else 
	{
		if(ptr->lcptr == NULL)	//no lefts of tree
			lh = -1;
		else
			lh = ptr->lcptr->height;
				
		if(ptr->rcptr == NULL)	//no rights of tree
			rh = -1;
		else
			rh = ptr->rcptr->height;
	}

	if(lh < rh)
		return rh + 1;
	else
		return lh + 1;
}	

struct node * insert(char word[], char mean[], struct node * ptr)
{
	if(ptr == NULL)       //no tree exists
	{
		ptr = (struct node*)malloc(sizeof(struct node));
		ptr->data = x;
		ptr->height = 0;
		ptr->lcptr = ptr->rcptr = NULL;
	}
	else
	{
		if(x < ptr->data)
		{
			ptr->lcptr = insert(x,ptr->lcptr);
			
		}
		else
		{
			ptr->rcptr = insert(x,ptr->rcptr);
		}
		ptr->height = Height(ptr);
		
		//BF(Balancing Factor) Checking
		if((Height(ptr->lcptr) - Height(ptr->rcptr) == -2) || (Height(ptr->lcptr) - Height(ptr->rcptr) == 2))        //Checking whether any node gets affected due to insertion.
		{
			if(x < ptr->data)
			{
				if(x < ptr->lcptr->data)  //case 1
					ptr = RotateRight(ptr);
       				else  			  //case 2
              				ptr=RotateLeftRight(ptr); 
			}
			else
			{
            			if(x < ptr->lcptr->data) //case 3
					ptr = RotateRightLeft(ptr);
         			else  			 //case 4
             				ptr=RotateLeft(ptr);
			}
		}
	}
	return ptr;
}
