// binary search tree

#include<stdio.h>
#include<stdlib.h>

typedef struct Tree
{
	struct Tree *left;
	int data;
	struct Tree *right;
}bst;

void insert(bst**,int);
void inorder(bst*);
void preorder(bst*);
void postorder(bst*);

int main()
{
	bst *root = 0;
	int op,num;
	while(1)
	{
		printf("------------------------------------------\n");
		printf("1.insert 2.inorder 3.preorder 4.postorder \n5.search 6.delete  7.exit\n");
		printf("------------------------------------------\n");
		printf("Enter option : ");
		scanf("%d",&op);
		printf("-----------------\n");
		
		switch(op)
		{
			case 1 : printf("Enter num : ");
				 scanf("%d",&num);
				 insert(&root,num); 	break;
			case 2 : inorder(root);		break; 
			case 3 : preorder(root);	break;
			case 4 : postorder(root);	break;
			case 5 : search();			break;
			case 6 : delete();			break;
			case 7 : exit(0);
			default :printf("unknown option..!\n");
		}
	}
	
	return 0;

}

void postorder(bst *root)
{
	if(root!=0)
	{
		preorder(root->left);
		preorder(root->right);
		printf("%d ",root->data);
		printf("\n");
	}
}

void preorder(bst *root)
{
	if(root!=0)
	{
		printf("%d ",root->data);
		printf("\n");
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(bst *root)
{
	if(root!=0)
	{
		inorder(root->left);
		printf("%d ",root->data);
		printf("\n");
		inorder(root->right);
	}
}

void insert(bst **root,int num)
{
	if(*root==0)
	{
		*root = calloc(1,sizeof(bst));
		(*root)->data = num;
	}
	else if(num < (*root)->data)
	{	
		insert( &(*root)->left,num);
	}
	else if(num > (*root)->data)
	{
		insert( &(*root)->right,num);
	}
	else
		printf("Duplicate number..!\n");
}
