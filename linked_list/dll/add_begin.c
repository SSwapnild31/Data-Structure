#include"header.h"

void add_begin(node **head)
{
	node *new;
	new = malloc(sizeof(node));
	printf("Enter rollno,name & marks\n");
	scanf("%d %s %f",&new->rollno,new->name,&new->marks);
	new -> prev = 0;

	if(*head==0)
	{
		new -> next = (*head);
		(*head) = new;
	}
	else
	{
		node *temp = *head;
		(*head) = new;
		new -> next = temp;
		new -> next -> prev = (*head);
	}
}
