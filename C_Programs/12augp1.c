#include<stdio.h>
#include<math.h>
struct Pol
{
	int a[100];
	int size;
}p1;

// Function Prototypes
void insert(struct Pol *ptr, int v, int pos);

void Print(struct Pol *ptr);

int Calc(struct Pol *ptr, int q);

int main()
{
	struct Pol *p2;
	p2= &p1;
	
	int x;
	printf("Enter the integer x\n");
	scanf("%d", &x);
	
	char ch='y';
	while(ch=='y')
	{
		int t, v1, po1;
		printf("\n--To Insert Press 1\n--To print list Press 2\n--To exit list Press \n");
		scanf("%d", &t);
		switch(t)
		{
			case 1:
			printf("Value and Position??\n");
			scanf("%d%d", &v1, &po1);
			insert(p2, v1, po1);
			break;
		
			case 2:
			printf("List is\n");
			Print(p2);
			break;
		
		        case 3:
                        ch='n';
			break;
		
			default:
			printf("\nwrong entry!\n");
		}
	//	printf("to continue  press y\n");
		//scanf("%c", &ch);
		
	} 
	Calc(p2, x);
	return 0;    
}	

// Function definitions	
void insert(struct Pol *ptr, int v, int pos)
{
	
	if(ptr->size==0)
	{
		ptr->a[0]=v;
		ptr->size=ptr->size+1;
	}
	else
	{
		for(int i=ptr->size;i>pos; i--)
		{
			ptr->a[i]= ptr->a[i-1];
		}
		ptr->a[pos] = v;
		ptr->size=ptr->size+1;
	}
}


void Print(struct Pol *ptr)
{
	for(int i=0;i<ptr->size;i++)
	{
		printf("%d\t", ptr->a[i]);
	}
}

int Calc(struct Pol *ptr, int q)
{
	
	int z=ptr->size;
	int f=0;
	for( int j=0,z=ptr->size; j<ptr->size; j++,z--)
	{
		f=f+ptr->a[j]*pow(q, z-1);
	}
	printf("Result= %d \n",f);
	return 0;
}	
		

