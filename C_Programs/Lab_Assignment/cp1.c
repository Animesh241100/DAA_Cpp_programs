#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node * insert(int data)
{
	struct node *root = (struct node *)malloc(sizeof(struct node));
	if(NULL == root)
	{
		perror("MAF");
		return NULL;
	}
	root->data = data;
	root->left = NULL;
	root->right = NULL;
}

void print(struct node *root)
{
	if(root == NULL)
		return;
	print(root->left);
	print(root->right);
	printf("%d",root->data);
}

void free_tree(struct node *root)
{
	if(root == NULL)
		return;
	else
	{
		if(NULL != root->left)
			free_tree(root->left);
		if(NULL != root->right)
			free_tree(root->right);
		if(NULL != root)
			free(root);
	}
}

int main()
{
	struct node * root;
	root = insert(1);
	root->left = insert(2);
	root->left->left = insert(4);
	root->right = insert(3);
	print(root);
	free_tree(root);
	return 0;
}
