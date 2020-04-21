#include<string.h>
#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *lcptr;
	char word[100];
	char mean[100];
	int height;
	struct node *rcptr;
};
//create empty  AVL tree 
int flag = 0;
struct node *root = NULL;
struct node *insert(char w[100], char m[100], struct node * ptr);
void inorder(struct node *ptr);
int Height(struct node *ptr);
int search(char key[100], struct node *ptr); 
struct node *RotateRight(struct node *ptr);
struct node *RotateLeft(struct node *ptr);
struct node *RotateRightLeft(struct node *ptr);
struct node *RotateLeftRight(struct node *ptr);
void main()
{
	char key[100];
	root = insert("first", "one", root);
    	printf("1:\n");
     	inorder(root);
	root = insert("all", "every", root);
     	printf("2:\n");
   	inorder(root);
	root = insert("eye", "piece", root);
    	printf("3:\n");
    	inorder(root);
	root = insert("black", "marble", root);
    	printf("4:\n");
    	inorder(root);
	root = insert("set", "fire", root);
    	printf("5:\n");
	inorder(root);
 	printf("Enter the word to search\n");
 	gets(key);
	search(key, root);
	if( flag!=1)
		printf("Element not found\n");
}
void inorder(struct node * ptr)
{
	if(ptr)
	{
		inorder(ptr->lcptr);
		printf("%s-%s-%d\n",ptr->word, ptr->mean, ptr->height);
		inorder(ptr->rcptr);
	}
}
int Height(struct node *ptr)
{
	int lh,rh;
	if(ptr == NULL)
		return -1;
	else 
	{
		if(ptr->lcptr == NULL)
			lh = -1;
		else
			lh = ptr->lcptr->height;
	
		if(ptr->rcptr == NULL)
			rh = -1;
		else
			rh = ptr->rcptr->height;
	}

	if(lh < rh)
		return rh + 1;
	else
		return lh + 1;
}
struct node *insert(char w[100], char m[100], struct node * ptr)
{
	if(ptr == NULL)
	{
		ptr = (struct node*)malloc(sizeof(struct node));
		strcpy(ptr->word, w);
		strcpy(ptr->mean, m);
		ptr->height = 0;
		ptr->lcptr = ptr->rcptr = NULL;
	}
	else
	{
		if(strcmp(w, ptr->word) < 0)
		{
			ptr->lcptr = insert(w, m, ptr->lcptr);
			
		}
		else
		{
			ptr->rcptr = insert(w, m, ptr->rcptr);
		}
		ptr->height = Height(ptr);
		
		//BF(Balancing Factor) Checking
		if((Height(ptr->lcptr) - Height(ptr->rcptr) == -2) || (Height(ptr->lcptr) - Height(ptr->rcptr) == 2))        //Checking whether any node gets affected due to insertion.
		{
			if(strcmp(w, ptr->word) < 0)
			{
				if(strcmp(w, ptr->lcptr->word) < 0) 
					ptr = RotateRight(ptr);
       				else  			 
              					ptr=RotateLeftRight(ptr); 
			}
			else
			{
            			if(strcmp(w, ptr->rcptr->word) < 0)	
					ptr = RotateRightLeft(ptr);
         			else  			 
             				ptr=RotateLeft(ptr);
			}
		}
	}
	return ptr;
}
struct node *RotateRight(struct node *ptr)
{
	struct node *xptr = ptr;
	struct node *yptr = ptr->lcptr;
	xptr->lcptr = yptr->rcptr;
	yptr->rcptr = xptr;
   
    	xptr->height=Height(xptr);
    	yptr->height=Height(yptr);
   
	return yptr;
}
struct node *RotateLeft(struct node *ptr)
{
	struct node *xptr = ptr;
	struct node *yptr = ptr->rcptr;
	xptr->rcptr = yptr->lcptr;
	yptr->lcptr = xptr;

    	xptr->height=Height(xptr);
    	yptr->height=Height(yptr);

	return yptr;
}
struct node *RotateRightLeft(struct node *ptr)
{
	ptr->rcptr = RotateRight(ptr->rcptr);
	return RotateLeft(ptr);
}
struct node *RotateLeftRight(struct node *ptr)
{
	ptr->lcptr = RotateLeft(ptr->lcptr);
	return RotateRight(ptr);
}

int search(char key[100], struct node *ptr)
{
	if(ptr)
	{
		search(key,ptr->lcptr);
		if(strcmp(key, ptr->word) == 0)
		{
			flag = 1;
			printf("the meaning of %s is %s", ptr->word, ptr->mean);
		}
		search(key,ptr->rcptr);
	}
}
