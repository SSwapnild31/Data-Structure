#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node	
{
	int data;
	struct node *next;
	struct node *prev;
}dcll;

void add_begin(dcll**);
void display(dcll*);
int count_node(dcll*);
void add_end(dcll**);

int main()
{
	int ch,c;
	dcll *head = 0;
	while(1)
	{
		printf("\t1.add_begin \n\t2.add_end \n\t3.display \n\t4.count_node \n\t10.exit\n");
		printf("Enter option : ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1  : add_begin(&head);	break;
			case 2  : add_end(&head);	break;
			case 3  : display(head);	break;
			case 4  : c = count_node(head);	
				  c > 0 ? printf("Node count : %d\n",c) : 0 ; 
				  break;
			case 10 : exit(0);
			default : printf("wrong option.!\n");
		}
	}
	return 0;
}


void add_begin(dcll **ptr)
{
	dcll *new = malloc(sizeof(dcll));
	
	printf("Enter int data : ");
	scanf("%d",&new->data);
	
	if(*ptr==0)	
	{ 
		*ptr = new;
		new->next = new->prev = *ptr;
	}
	else
	{
		new->next = *ptr;
		new->prev = (*ptr)->prev;
		(*ptr)->prev->next = new;
		(*ptr)->prev = new;
		*ptr = new;
	}
}

void display(dcll *head)
{
	dcll *ptr = head;
	if(ptr==0)
	{
		printf("List is empty\n");
		return ;
	}
	
	printf("Forward printing\n");
	while(ptr)
	{
		printf("%d ",ptr->data);
		ptr = ptr->next;
		if(ptr==head)	break;
	}
	
	printf("\nBackward printing\n");
	while(ptr)
	{
		ptr = ptr->prev;
		printf("%d ",ptr->data);
		if(ptr==head)	break;
	}

	printf("\n");
}

int count_node(dcll *head)
{
	dcll *ptr = head;

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

void add_end(dcll **ptr)
{
        dcll *new = malloc(sizeof(dcll));

        printf("Enter int data : ");
        scanf("%d",&new->data);

        if(*ptr==0)
        {
                *ptr = new;
                new->next = new->prev = *ptr;
        }
        else
        {
                dcll *last = (*ptr)->prev;

                new->prev = last;
                new->next = *ptr;
                last->next = new;
                (*ptr)->prev = new;
        }
}
