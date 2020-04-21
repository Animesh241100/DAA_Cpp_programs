#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	int data;
	struct node *nptr;
};
void push(int y);
void show();
struct node *hptr= NULL;
struct node *tptr= NULL;
int main()
{
	char str[100];
	scanf("%s", str);
	int i = 0;
	while(i!=strlen(str))
	{
		push(str[i]-48);
		i++;
	}
	show();	
	return 0;
}
void push(int y)
{
	struct node *t=(struct node*)malloc(sizeof(struct node));
	t->data = y;
	if(hptr==NULL)
	{
		hptr = t;
		t->nptr = NULL;
		tptr = hptr;
	}
	else
	{
		tptr->nptr = t;
		t->nptr = NULL;
		tptr = tptr->nptr;
	}
}

void show()
{
	struct node *t;
	t = hptr;
	while(t->nptr!= NULL)
	{
		printf("%d", t->data);
		t = t->nptr;
	}
	printf("%d", t->data);
}
		
		
	
