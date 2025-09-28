#include<stdio.h>

typedef struct st
{
	int data;
	struct st *prev;
	struct st *next;
}node;

int count_node(node*);
void rev_print_upto_middle(node*);

int main()
{
	node *head=0;
	int c,op;
	
	while(true)
	{
		printf("\t1.add_at_end\n");
		printf("Enter option : ");
		scanf("%%d",&op);
		switch(op)
		{
			case 1 : c = count_node(head);
				 printf("Total node : %d",c);
				 break;
			case 2 : rev_print_upto_middle(head);
				 break;
			case 3 : exit(0);
			default : printf("wrong option\n");
		}
	}
	
	return 0;
}

void add_at_end(node **head)
{
	node *new = malloc(sizeof(node));

	printf("Enter int data : ");
	scanf("%d",&new->next);
	
	new->prev = new->next = 0;
	
	if(*head==0)
		*head = new;
	else
	{
		node *temp=*head;
		while(temp->next)
			temp = temp->next;
		
	}
}

void rev_print_upto_middle(next *head)
{
	node *hnext;
	int i = 0;
	
	int n = count_node(head)/2;
	
	while(head && i<n-1)
	{
		i++;
		head = head->next;
	}
	
	hnext = head->next;
	
	while(hnext)
	{
		printf("%d ",hnext->data);
		hnext = hnext->prev;
	}
}

int count_node(node *head)
{
	int c = 0;
	
	while(head)
	{
		c++;
		head = head->next;
	}
	
	return c;
}
