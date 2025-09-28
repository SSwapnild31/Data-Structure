#include<stdio.h>
#include<stdlib.h>

typedef struct st
{
	int data;
	struct st *prev;
	struct st *next;
}node;

void add_at_end(node**);
int count_node(node*);
void rev_print_upto_middle(node*);


int main()
{
	node *head=0;
	int c,op;
	
	while(1)
	{
		printf("\t1.add_at_end \n\t2.count_node \n\t3.rev_print_upto_middle \n\t4.exit\n");
		printf("Enter option : ");
		scanf("%d",&op);
		switch(op)
		{
			case 1 : add_at_end(&head);
				 break;
			case 2 : c = count_node(head);
				 printf("Total node : %d\n",c);
				 break;
			case 3 : rev_print_upto_middle(head);
				 break;
			case 4 : exit(0);
			default : printf("wrong option\n");
		}
	}
	
	return 0;
}

void add_at_end(node **head)
{
	node *new = malloc(sizeof(node));

	printf("Enter int data : ");
	scanf("%d",&new->data);
	
	new->prev = new->next = 0;
	
	if(*head==0)
		*head = new;
	else
	{
		node *temp = *head;
		
		while(temp->next) 
			temp = temp->next;
		
		new->prev = temp;
		temp->next = new;
	}
}

void rev_print_upto_middle(node *head)
{
	if(head==0)
	{
		printf("List is empty\n");
		return ;
	}
	node *hnext=0;
	int i = 0;
	
	int n = count_node(head)/2;
	
	while(head && i<n)
	{
		i++;
		head = head->next;
	}
	
	hnext = head;
	
	while(hnext)
	{
		printf("%d ",hnext->data);
		hnext = hnext->prev;
	}
	printf("\n");
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
