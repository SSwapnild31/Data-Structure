#include<stdio.h>
#include<stdlib.h>

typedef struct Tree
{
    int data; 
    struct Tree *left, *right;
}tree;

void inorder(tree*);
void preorder(tree*);
void postorder(tree*);
void insert(tree**,int);
tree* search(tree*,int);

int main()
{
    tree *root = 0, *res = 0;
    int op,num;

    while(1)
    {
        printf("\n1.insert\t2.search\n3.preorder\t4.inorder\n5.postorder\t9.exit\n");
        printf("Enter option : ");
        scanf("%d",&op);
        switch(op)
        {
            case 1 : printf("Enter ele to insert : ");
                     scanf("%d",&num); 
                     insert(&root,num);     break;
            case 2 : printf("Enter ele to search : ");
                     scanf("%d",&num);
                     res = search(root,num);
                     if(res) 
                        printf("ele is present at %d\n",res);
                     else
                        printf("ele not present.!\n");
                     break;
            case 3 : preorder(root);        break;
            case 4 : inorder(root);         break;
            case 5 : postorder(root);       break;
            case 9 : exit(0);
            default : printf("wrong option!\n");
        }
    }

    return 0;
}

tree* search(tree *root, int key)
{
	while(root!=NULL)
	{
		if(key==root->data)
			return(root);
		if(key > root->data)
			root = root->right;
		else
			root = root->left;
	}
	return NULL;
}

/*tree* search(tree *root, int key)
{
    if(root==NULL)
        return NULL;
    if(root->data==key)
        return root;
    if(key > root->data)
        return(search(root->right,key));
    return(search(root->left,key));
}*/

void postorder(tree *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void inorder(tree *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(tree *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void insert(tree **root,int num)
{
    if(*root==NULL)
    {
        *root = calloc(1,sizeof(tree));
        (*root)->data = num;
    }
    else if((*root)->data < num)
    {
        insert(&(*root)->left,num);
    }
    else if((*root)->data > num)
    {
        insert(&(*root)->right,num);
    }
    else
        printf("Duplicate element\n");
}
