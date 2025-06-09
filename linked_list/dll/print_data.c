#include"header.h"

void print_data(node *head)
{
	if(head==0)
	{
		printf("node not available..!\n");
		return ;
	}
	while(head)
	{
		printf("%d %s %f\n",head->rollno,head->name,head->marks);
		head = head -> next;
	}
}
