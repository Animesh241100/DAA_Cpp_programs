#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int qsize;
	int a[108];
};
//int front=0;
//int rear=0;
void enqueue(struct queue *p1, int x);
void dequeue(struct queue *p1);
void show(struct queue *p1);
int main()
{
	struct queue q, *p1;
	q.qsize = 0;
	p1 = &q  ;   //pl holds the address of the Queue q
	enqueue(p1, 1);
	show(p1);
	enqueue(p1, 2);
	show(p1);
	enqueue(p1, 3);
	show(p1);
	dequeue(p1);
	show(p1);
	dequeue(p1);
	show(p1);
	enqueue(p1, 4);
	show(p1);
	dequeue(p1);
	show(p1);
	enqueue(p1, 5);
	show(p1);
	enqueue(p1, 6);	
	show(p1);
	dequeue(p1);
	show(p1);
	return 0;
}

void enqueue(struct queue *p1, int x)
{
	
	p1->qsize = p1->qsize + 1; // making room for new member
	p1->a[(p1->qsize)-1] = x;  //accessing the last cell
}
void dequeue(struct queue *p1)
{
	
	printf("\n Dequeued one %d\n", p1->a[0]);
	for(int i = 0; i<(p1->qsize); i++)
	{
		p1->a[i] = p1->a[i+1];
	}
	p1->qsize = p1->qsize - 1;
}

void show(struct queue *p1)
{
	
	printf("\nqueue\n");
	for(int i=0; i < p1->qsize; i++)
	{
		printf("\t%d\t", p1->a[i]);
	}
	printf("\n");
}
		
