#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	int data;
	struct node *link;
};
struct node *top=NULL;
void push(int x);
int pop();
int func(int,int,char);
int main()
{	char str[20];
	printf("Enter the postfix expression:");
	gets(str);
	int i,count1=0,count2=0;
	for(i=0;i<strlen(str);i++)
	{
		if(str[i]>47&&str[i]<58)
		{
			push(str[i]-48);
			count1++;	
		}
		else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
		{
			char op=str[i];
			int op1,op2,res;
			op2=pop();
			op1=pop();
			res=func(op1,op2,op);
			push(res);
			count2++;	
		}	
	}
	if((count1-count2)==1)
		printf("%d",top->data);
	else
		printf("Error");
	return 0;
}
void push(int x)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=x;
	temp->link=top;
	top=temp;
}
int pop()
{
	struct node *temp;
	temp=top;
	top=top->link;
	int d=temp->data;
	return d;
}
int func(int x,int y,char z)
{
	if(z=='+')
		return x+y;
	else if(z=='-')
		return x-y;
	else if(z=='*')
		return x*y;
	else if(z=='/')
		return x/y;
}

  
  
  
  
  
  
     
