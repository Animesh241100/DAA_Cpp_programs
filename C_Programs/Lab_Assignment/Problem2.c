#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *nptr;
};
struct node * shead = NULL;		//head node for or superset
struct node * s1h = NULL;		//head node for subset1
struct node * s2h = NULL;		//head node for subset2
struct node * uni = NULL;		//head node for union
struct node * in = NULL;		//head node for intersection	
struct node * comp1 = NULL;		//head node for complement of Set1
struct node * comp2 = NULL;		//head node for complement of Set2

//Prototypes of utility functions
struct node * Insert( struct node * ptr, int x);
void Print(struct node * ptr);
void Union( struct node * p1, struct node * p2);
void Intersection( struct node * p1, struct node * p2);
struct node * Complement( struct node * ptr, struct node * comp);
struct node * Getdata(struct node * ptr);
void Search(int key, struct node * ptr);
void main()
{
	int key, op;
	printf("Enter the elements of the super-set\n");
	shead = Getdata(shead);
	printf("Enter the elements of the Set1\n");
	s1h = Getdata(s1h);
	printf("Enter the elements of the Set2\n");
	s2h = Getdata(s2h);
	printf("The superset is\n");
	Print(shead);
	printf("The Set1 is\n");
	Print(s1h);
	printf("The Set2 is\n");
	Print(s2h);
	Union(s1h, s2h);
	printf("The Union set is\n");
	Print(uni);
	Intersection(s1h, s2h);
	printf("The Intersection set is\n");
	Print(in);
	printf("The complement of Set1 is\n");
	comp1 = Complement(s1h, comp1);
	Print(comp1);
	printf("The complement of Set2 is\n");
	comp2 = Complement(s2h, comp2);
	Print(comp2);
	printf("Enter an element to check membership\n");
	scanf("%d", &key);
	a1: printf(" Enter the following:\n\t1: Enter 1 to search in Super-Set\n\t2: Enter 2 to search in Set1\n\t3: Enter 3 to search in Set2\n\t4: Enter 4 to search in Union Set\n\t5: Enter 5 to search in Intersection Set\n");
	scanf("%d", &op);
	switch(op)
	{
		case 1:
			Search(key, shead);
			break;
		case 2:
			Search(key, s1h);
			break;
		case 3:
			Search(key, s2h);
			break;
		case 4:
			Search(key, uni);
			break;
		case 5:
			Search(key, in);
			break;
		default:
			printf("Invalid entry! Try again\n");goto a1;
	}
}

struct node * Insert( struct node * ptr, int x)
{
	struct node * temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	if(ptr==NULL)
	{
		ptr = temp;
		temp->nptr = NULL;
	}
	else
	{
		struct node * thptr = ptr;
		while(thptr!=NULL)
		{
			if((thptr->data) == x)
				goto a1;
			thptr=thptr->nptr;
		}
		temp->nptr = ptr;
		ptr = temp;
	}
	a1: return ptr;
}
	
struct node * Getdata(struct node * ptr)
{
	char c='y';
	int a;
	while(c=='y')
	{
		scanf("%d", &a);
		ptr = Insert(ptr, a);
		printf("Do you want to enter more members? y/n \n");
		scanf(" %c", &c);
	}
	return ptr;
}	
void Print(struct node * ptr)
{
	struct node * thptr = ptr;
	
	while(thptr!=NULL)
	{
		printf("%d\t", thptr->data);
		thptr = thptr->nptr;
	}
	printf(" \n");
}

void Union( struct node * p1, struct node * p2)
{
	struct node * thptr = p1;
	while(thptr != NULL)
	{
		uni = Insert(uni, thptr->data);
		thptr = thptr->nptr;
	}
	thptr = p2;
	while(thptr != NULL)
	{
		uni = Insert(uni, thptr->data);
		thptr = thptr->nptr;
	}
}

void Intersection( struct node * p1, struct node * p2)	
{
	struct node * thptr1 = p1;
	struct node * thptr2;
	while(thptr1 != NULL)
	{
		 thptr2 = p2;
		 while(thptr2 != NULL)
		 {
		 	if(thptr1->data == thptr2->data)
		 		in = Insert(in, thptr1->data);
		 	thptr2 = thptr2->nptr;
		 }
		 thptr1 = thptr1->nptr;
	}
}
	
struct node * Complement( struct node * ptr, struct node * comp)
{
	struct node * thptr1 = shead;
	struct node * thptr2;
	int flag;
	while(thptr1!=NULL)
	{
		flag = 1;
		thptr2 = ptr;
		while(thptr2!=NULL)
		{
			if(thptr1->data==thptr2->data)
			{
				flag = 0; //don't take in this thptr1->data
				break;
			}
			thptr2 = thptr2->nptr;
		}
		if(flag == 1)
			comp = Insert(comp, thptr1->data);
		thptr1 = thptr1->nptr;
	}
	return comp;
}

void Search(int key, struct node * ptr)
{
	struct node * thptr = ptr;
	int flag = 0;
	while(thptr!=NULL)
	{
		if(thptr->data==key)
		{
			flag = 1;
			break;
		}
		thptr = thptr->nptr;
	}
	if(flag==1)
		printf("The element you entered IS a member of this set\n");
	else
		printf("The element you entered is NOT a member of this set\n");
}
