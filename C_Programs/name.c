#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *nptr;
};
void push(int y, struct node *tptr);
void print(struct node *tptr);
struct node *tptr;
int main()
{
	/*char no[1000];
	printf("Enter the no.\n");
	scanf("%s", no[1000]);
	str
	for(int i; i<=l
	printf("%s", no[i]);
	return 0;*/
	int x;
	
	char ch[4] ={'1', '3', '4', '2'};
	int arr[4];
	tptr = NULL;
	for(int i=0; i<4; i++)
	{
		arr[i] = ch[i] - 48;
	}
	for(int i=0; i<4; i++)
	{
		push(arr[i],tptr);
	}
	print(tptr);	
	return 0;
}
void push(int y, struct node *tptr)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data = y;
	if(tptr==NULL)
	{
		temp->nptr = tptr;
		tptr = temp;
	}
	else
	{
	temp->nptr = NULL;
	}
}

void print(struct node *tptr)
{
	struct node *ptr;
	ptr = tptr;
	while(ptr->nptr!= NULL)
	{
		printf("%d", ptr->data);
		ptr = ptr->nptr;
	}
}
		
		
	
