#include<stdio.h>
#include<stdlib.h>

struct node * Nq(struct node * f, struct node * r, int x);
struct node * Dq(struct node * f);

struct node
{
	int data;
	struct node * nptr;
};

struct node * hash[3][2];   // hash[address of front 'f'][address of rear 'r']

for(int i = 0; i < 3; i++)
{
	for(int j = 0; j < 2; j++)
	{
		hash[i][j] = NULL;
	}
			}

{

				}
int Dequeued = 0;


int main()
{
	int size = 0;
	printf("Enter the array size:\n");
	scanf("%d", &size);
	int arr[size];
	int arr_out[size];
	printf("Now, enter all the array elements:\n");
	for(int i = 0; i < size; i++)
		scanf("%d", &arr[i]); 
	
	for(int i = 0; i < size; i++)
	{
		hash[arr[i]][1] = Nq(hash[arr[i]][0], hash[arr[i][1]], i);
	}
	
	int k = 0;
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			if(k != size-1)
			{
				arr_out[k] = hash[arr[i]][j]->data;
				k++;
			}
		}
	}
	printf("Output:\n");
	for(int i = 0; i < size; i++)
		printf("%d\t", arr[i]);
}

	
struct node * Nq(struct node * f, struct node * r, int x)
{
	struct node * temp = (struct node *)malloc(sizeof(struct node));
	temp->data = x;
	temp->nptr = NULL;
	if(r != NULL)
	{
		r->nptr = temp;
		r = temp;
	}
	else
	{
		r = temp;
		f = r;
	}
	return r;
}


struct node * Dq(struct node * f)
{
	if(f == NULL)
		return f;
	Dequeued = f->data;
	f = f->nptr;
	return f;
}
	
	
