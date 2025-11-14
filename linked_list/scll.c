#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

typedef struct node	{
	int data;
	struct node *next;
}scll;

void add_begin(scll**);
void add_end(scll**);
void display(scll*);
int count_node(scll*);
void add_middle(scll**);
void print_rev(scll*);

int main()
{
	int ch,c;
	scll *head = 0;
	while(1)
	{
		printf("\t1.add_begin \n\t2.add_end \n\t3.add_middle \n\t4.display \n\t5.count_node \n\t6.print_rev \n\t10.exit\n");
		printf("Enter option : ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1  : add_begin(&head);	break;
			case 2  : add_end(&head);	break;
			case 3  : add_middle(&head);	break;
			case 4  : display(head);	break;
			case 5  : c = count_node(head);	
				  c > 0 ? printf("Node count : %d\n",c) : 0 ; 
				  break;
			case 6  : print_rev(head); printf("\n"); break;
			case 10 : exit(0);
			default : printf("wrong option.!\n");
		}
	}
	return 0;
}

void print_rev(scll *head)
{
	if(head==0)
	{
		printf("list is empty.!\n");
		return ;
	}

	static int i=0;
	static scll *ptr;

	if(i==0) 
	{	
		ptr = head;
		i=1;
	}

	if(head->next!=ptr)
		print_rev(head->next);

	printf("%d ",head->data);
	
	return ;
}

void add_begin(scll **ptr)
{
	scll *new = malloc(sizeof(scll));
	
	printf("Enter int data : ");
	scanf("%d",&new->data);
	
	if(*ptr==0)	
	{ 
		*ptr = new;
		new->next = *ptr;
	}
	else
	{
		new->next = *ptr;
		scll *temp =*ptr;
		while(temp->next!=*ptr)
			temp = temp->next; 
		*ptr = new;
		temp->next = *ptr;
	}
}

void display(scll *head)
{
	scll *ptr = head;
	if(ptr==0)
	{
		printf("List is empty\n");
		return ;
	}

	while(ptr)
	{
		printf("%d ",ptr->data);
		ptr = ptr->next;
		if(ptr==head)	break;
	}
	printf("\n");
}

int count_node(scll *head)
{
	scll *ptr = head;

	if(ptr==0)
	{
		printf("Empty list.!!\n");
		return 0;
	}

	int count = 0;
	while(ptr)
	{
		count++;
		if(ptr->next==head)	break;
		ptr = ptr->next;
	}
	return count;
}

void add_middle(scll **ptr)
{
	scll *temp = *ptr, *new = malloc(sizeof(scll));
	
	printf("Enter data : ");
	scanf("%d",&new->data);
	
	if(*ptr==0)
	{
		*ptr = new;
		new->next = *ptr;
		return ;
	}
	
	if(new->data < (*ptr)->data)
	{
		new->next = *ptr;
		while(temp->next!=*ptr)
			temp = temp->next;
		*ptr = new;
		temp->next = *ptr;
		return ;
	}

	temp = *ptr;
	while(temp->next!=*ptr && new->data > temp->next->data)
		temp = temp->next;

	new->next = temp->next;
	temp->next = new;
}

void add_end(scll **ptr)
{
	scll *new = malloc(sizeof(scll));
	
	printf("Enter int data : ");
	scanf("%d",&new->data);
	
	if(*ptr==0)
	{
		*ptr = new;
		new->next = *ptr;
	}
	else
	{
		scll *last = *ptr;
		while(last->next!=*ptr)	
			last = last->next;

		new->next = last->next;
		last->next = new;
	}
}
