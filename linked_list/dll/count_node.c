#include"header.h"

int count_node(node *head)
{
	int c=0;
	while(head)
	{
		c++;
		head = head -> next;
	}
	
	return c;
}
