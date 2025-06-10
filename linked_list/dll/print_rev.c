#include"header.h"

void print_rev(node *head)
{
	while(head->next)
		head = head -> next;
	
	while(head)
	{
		printf("%d %s %f\n",head->rollno,head->name,head->marks);
		head = head -> prev;
	}
}
