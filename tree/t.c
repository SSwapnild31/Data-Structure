#include<stdio.h>
#include<stdlib.h>

typedef struct Tree
{
    struct Tree *left;
    struct Tree *right;
    int data; 
}tree;

int main()
{
    tree *root = 0;
    int op,num;

    while(1)
    {
        printf("1.insert\n2.display\n3.exit\n");
        printf("Enter option : ");
        scanf("%d",&op);
        switch(op)
        {
            case 1 : printf("Enter ele to insert : ");
                     scanf("%d",&num); 
                     insert(&root,num);     break;
            case 2 : preorder(root);        break;
            case 3 : inorder(root);         break;
            case 4 : postorder(root);       break;
            case 5 : exit(0);
            default : printf("wrong option!\n");
        }
    }

    return 0;
}

void preorder(tree *root)
{
    if(root!=0)
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