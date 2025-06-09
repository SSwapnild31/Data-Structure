#include "header.h"

void add_end(node **head)
{
	node *new;
	new = malloc(sizeof(node));
	printf("Enter rollno, name & marks\n");
	scanf("%d %s %f",&new->rollno,new->name,&new->marks);

	if(*head==0)
	{
		new -> prev = 0;
		new -> next = *head;
		*head = new;
	}
	else
	{
		node *temp = *head;
		while(temp -> next)
			temp = temp -> next;
		new -> prev = temp;
		new -> next = 0;
		temp -> next = new ;
	}
}
