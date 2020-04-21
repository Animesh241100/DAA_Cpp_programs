#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node * nptr;
};

struct node * Prime = NULL;
struct node * Stack1 = NULL;
struct node * Stack2 = NULL;
int POP = 0;

struct node * push(struct node * top, int data);
struct node * pop(struct node * top);
void display(struct node * top);

int main()
{
    int size;
    Prime = push(Prime, 10);
    display(Prime); 
    Prime = pop(Prime);
    cout<<POP<<endl;
    display(Prime);
    int i = 0;
    while (i != n)
    {
        Prime = pop(Prime);
        k = POP;
        if(s1 <= s2)
        {
            while ((s1 + k) > s2)
            {
                Stack1 = pop(Stack1);
                l = POP;
                s1 = s1 - l;
                
                if(l != -1000000)
                {
                    Prime = push(Prime, l);
                    i--;
                }    
            }
            
    }
    
    /*cout<<"Enter the size of the array\n";
    scanf("%d", &size);
    int Prime[size];
    int stack1[size/2];
    int stack2[size/2];
    for(int i = 0; i < size; i++)\
    {
        cin>>l;
        push(Prime, l);
    }*/

}

struct node * push(struct node * top, int data)
{
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->nptr = top;
    top = temp;
    return top;
}

struct node * pop(struct node * top)
{
    if(top!=NULL)
    {
        int a = top->data;
        top = top->nptr;
        POP = a;
    }
    else
        POP = -1000000; //the stack is empty
    return top;
}

void display(struct node * top)
{
    struct node * thptr = top;
    printf("\n");
    while(thptr != NULL)
    {
        printf(" %d", thptr->data);
        thptr = thptr->nptr;
    }
    printf("\n");
}
