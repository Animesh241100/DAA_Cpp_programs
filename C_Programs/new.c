A simple eg:

 #include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int data;        //data part of linked list,may be any no.of or any type of data
    struct node *link;
};
 
struct node *header1,*header2;
         /* pointer to the Header node,
            It is the first node of linked list and usually not store any data,
            Just used for representing first node */
 
void addele1(int da)
{
    struct node *ele,*ptr;
    //create a node in linked list
 
        ele=(struct node *)malloc(sizeof(struct node));
        if(ele==NULL)
            printf("\n Memory allocation Error");
        else
        {
            // set link of new node as NULL,very important usual error in linked list
 
            ele->link=NULL;
            // let data be 100
            ele->data=da;
 
            // pointing  node to tail of linked list
 
            ptr=header1;
            while(ptr->link!=NULL)
                ptr=ptr->link;
 
            //ptr points to the last element in linked list
 
            ptr->link=ele; //attaches last element of linked list with new node
 
 
        }
 
}
 void display1()
 {
     struct node *ptr;
     printf("all elements in list");
 
     ptr=header1->link;
     while(ptr!=NULL)
     {
         printf("%d ",ptr->data);
         ptr=ptr->link;
     }
 }
 
 
void addele2(int da)
{
    struct node *ele,*ptr;
    //create a node in linked list
 
        ele=(struct node *)malloc(sizeof(struct node));
        if(ele==NULL)
            printf("\n Memory allocation Error");
        else
        {
            // set link of new node as NULL,very important usual error in linked list
 
            ele->link=NULL;
            // let data be 100
            ele->data=da;
 
            // pointing  node to tail of linked list
 
            ptr=header2;
            while(ptr->link!=NULL)
                ptr=ptr->link;
 
            //ptr points to the last element in linked list
 
            ptr->link=ele; //attaches last element of linked list with new node
 
 
        }
 
}
 void display2()
 {
     struct node *ptr;
     printf("\n all elements in list:");
 
     ptr=header2->link;
     while(ptr!=NULL)
     {
         printf("%d ",ptr->data);
         ptr=ptr->link;
     }
 }
 
int main()
{
 
    header1=(struct node *)malloc(sizeof(struct node)); // allocate space for header node.
 
    header2=(struct node *)malloc(sizeof(struct node));
 
    if(header1==NULL ||header2==NULL)
    {
        printf(" Memory allocation Error..Exiting");
 
    }
    else
    {
        // " -> " used for accessing struct variable using pointer
 
        //header initialization
 
        header1->data=NULL;
        header1->link=NULL;
 
        addele1(100);
        addele1(200);
 
        display1();
 
 
        header2->data=NULL;
        header2->link=NULL;
 
        addele2(20);
        addele2(1000);
 
        display2();
    }
    return 0;
}
