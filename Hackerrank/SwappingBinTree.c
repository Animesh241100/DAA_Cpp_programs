#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * rptr;
	struct node * lptr;
};

struct node * root = NULL;
int flag = 0;
struct node * Insert(struct node * ptr, int x);
struct node * Search (struct node * ptr, int key);
void Inorder(struct node * ptr);

void main()
{
	root = Insert(root, 1);
	root = Insert(root, 2);
	root = Insert(root, 3);
	root = Insert(root, 4);
	root = Insert(root, 5);
	root = Insert(root, 6);
	root = Insert(root, 7);
	root = Insert(root, 8);
	root = Insert(root, 9);
	printf("%p\n", root);
	printf("%p\n", Search(root,1));
	printf("%p\n", Search(root,2));
	printf("%p\n", Search(root,3));
	printf("%p\n", Search(root,4));
	printf("%p\n", Search(root,5));
	printf("%p\n", Search(root,6));
	printf("%p\n", Search(root,7));
	printf("%p\n", Search(root,8));
	printf("%p\n", Search(root,9));
	printf("%p\n", Search(root,10));
	printf("%p\n", Search(root,11));
	printf("%p\n", root);
	//Inorder(root);

}
struct node * Insert(struct node * ptr, int x)
{
	
	if(ptr==NULL)
	{
		struct node * temp = (struct node *)malloc(sizeof(struct node));
		temp->data = x;
		ptr = temp;
		ptr->lptr = ptr->rptr = NULL;
	}
	else
	{
		if(x < ptr->data)
			ptr->lptr = Insert(ptr->lptr, x);
		else
			ptr->rptr = Insert(ptr->rptr, x);
	}
	return ptr;
}


void Inorder(struct node * ptr)
{
	Inorder(ptr->lptr);
	printf("%d\t", ptr->data);
	Inorder(ptr->rptr);
}

struct node * Search (struct node * ptr, int key)
{
	auto struct node * Search2 (struct node * ptr, int key);
	ptr = Search2(ptr, key);
	struct node * Search2 (struct node * ptr, int key)
	{
		if(ptr == NULL)
			return NULL;
		if(ptr->data == key)
		{
			flag = 1;
			return ptr;
		}
		if(Search2(ptr->lptr, key) != NULL)
			ptr = Search2(ptr->lptr, key);
		if(Search2(ptr->rptr, key) != NULL)
			ptr = Search2(ptr->rptr, key);
		if(flag == 1)
			return ptr;
		else 
			return NULL;
	}
	flag = 0;
	return ptr;
}

		
/*
struct node * Search (struct node * ptr, int key)
{
	if(ptr == NULL)
		return NULL;
	if(ptr->data == key)
	{
		flag = 1;
		return ptr;
	}
	if(Search(ptr->lptr, key) != NULL)
		ptr = Search(ptr->lptr, key);
	if(Search(ptr->rptr, key) != NULL)
		ptr = Search(ptr->rptr, key);
	if(flag == 1)
		return ptr;
	else 
		return NULL;
}

void Search (struct node * ptr, int key)
{
	Search(ptr->lptr, key);
	if((ptr->data) == key)
	{
		flag = ptr;
		return flag;
	}
	Search(ptr->rptr, key);
}
*/	
	

struct node * lca( struct node * ptr, int v1, int v2 ) 
{
	if(((ptr->lptr) != NULL)&& ((ptr->rptr) != NULL))
	{
		



}*/

