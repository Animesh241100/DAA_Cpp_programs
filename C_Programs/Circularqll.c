
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *front=NULL;
struct node *rear=NULL;
void Nq(int x);
void Dq();
void show();
int main()
{
	Nq(1);
	Nq(3);
	Nq(8);
	Nq(9);
	Nq(0);
	Nq(4);
	Nq(2);
	Dq();
	Dq();
	Dq();
	Dq();
	show();
	return 0;
}
void Nq(int x)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=x;
	if(front==NULL)
	{
		temp->link=temp;
		front=temp;
		rear=temp;
	}
	else
	{
		rear->link=temp;
		temp->link=front;
		rear=temp;
	}
}
void Dq()
{
	struct node *temp=front;
	if(front==NULL)
	{
		printf("empty Queue\n");
	}
	else if(front==rear)
	{
		front=NULL;
		rear=NULL;
	}
	else
	{
		front=front->link;
		rear->link=front;
	}
	free(temp);
}
void show()
{
	struct node *temp=front;
	while(temp->link!=front)
	{
		printf("%d\t",temp->data);
		temp=temp->link;
	}
	printf("%d\n",temp->data);
}
