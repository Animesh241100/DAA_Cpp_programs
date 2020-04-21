/* program to construct tree using inorder and preorder traversals */
#include <stdio.h> 
#include <stdlib.h> 
struct node 
{ 
	char data; 
	struct node* lptr; 
	struct node* rptr; 
}; 
int len;
/* Prototypes for utility functions */
int search(char arr[], int strt, int end, char value); 
struct node* newNode(char data); 
void Inorder(struct node* node);

/* Recursive function to construct binary tree having #nodes = len from Inorder traversal in[] and Preorder traversal pre[]. Initial values of inStrt(starting index of in[]) and inEnd(ending index of in[]) should be 0 and len-1.*/
struct node* buildTree(char in[], char post[], int inStrt, int inEnd) 
{ 
	static int postIndex = len - 1;  //preIndex is the index vlue of a data in preorder traversal

	if (inStrt > inEnd) 
		return NULL; 

	struct node* root = newNode(post[postIndex]); //making a node from data associated with current preIndex
	postIndex = postIndex - 1;

	/* If this node has no children then return */
	if (inStrt == inEnd)
		return root; 

	/* Else find the index of this node in Inorder traversal */
	int inIndex = search(in, inStrt, inEnd, root->data); 
	root->lptr = buildTree(in, pre, inStrt, inIndex - 1); //in inorder traversal the all the data present in the left of the inIndex data falls in the lefts of tree.
	root->rptr = buildTree(in, pre, inIndex + 1, inEnd);  //Same as above
	return root; 
} 

	//Function to find index of a particular node's data in arr[start...end] 
int search(char arr[], int start, int end, char data) 
{ 
	int i; 
	for (i = start; i <= end; i++)
	{ 
		if (arr[i] == data) 
			return i; 
	} 
} 

struct node* newNode(char data) 
{ 
	struct node* temp = (struct node*)malloc(sizeof(struct node)); 
	temp->data = data; 
	temp->lptr = temp->rptr = NULL; 
	return (temp); 
} 
 //to print the inorder traversal to test new binary tree
void Inorder(struct node* ptr) 
{ 
	if (ptr == NULL) 
		return; 
	Inorder(ptr->lptr); 
	printf("%c ", ptr->data); 
	Inorder(ptr->rptr); 
} 

int main() 
{ 
	char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' }; 
	char post[] = { 'D', 'E', 'B', 'F', 'C', 'A' }; 
	//int len = sizeof(in) / sizeof(in[0]); 
	int len = sizeof(in);
	struct node* root = buildTree(in, pre, 0, len - 1); 
	printf("Inorder traversal of the constructed tree is \n"); 
	Inorder(root); 
	getchar(); 
} 
