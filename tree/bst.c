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
int search(bst*,int);

int main()
{
	bst *root = 0;
	int op, num;

	while(1)
	{
		printf("1.Insert \n2.Delete \n3.Search \n4.Display \n5.Exit\n");
		printf("Enter option : ");
		scanf("%d",&op);
		switch(op)
		{
			case 1 : printf("Enter num : ");
				 scanf("%d",&num);
				 insert(&root,num);
				 break;
			/*case 2 : printf("Enter num to delete : ");
				 scanf("%d",&num);
				 delete(root,num);
				 break;*/
			case 3 : printf("Enter num to search : ");
				 scanf("%d",&num);
				 search(root,num);
				 break;
			case 4 : while(1)
				 {
					 printf("\n\t1.Inorder \t2.Preorder \n\t3.Postorder \t4.Exit to main\n");
					 printf("Enter option : ");
					 scanf("%d",&op);
					 if(op==4)	break;
					 switch(op)
					 {
						 case 1  : inorder(root);	break;
						 case 2  : preorder(root);	break;
						 case 3  : postorder(root);	break;
						 default : printf("wrong option\n");
					 }
				 }
				 break;
			case 5 : exit(0);
			default : printf("wrong option.!\n");
		}
	}

	return 0;
}

int search(bst *root,int num)
{

	return 0;
}

void insert(bst **root, int num)
{
	if(*root==0)
	{
		*root = calloc(1,sizeof(bst));
		(*root)->data = num;
	}
	else if(num < (*root)->data)
	{
		insert(&(*root)->left,num);
	}
	else if(num > (*root)->data)
	{
		insert(&(*root)->right,num);
	}
	else	
		printf("Duplicate number\n");
}

