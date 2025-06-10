#include"header.h"

void rev_print_upto_half(node *head)
{
	node *hnext=0;
	int i=0,n=0;
	n = count_node(head)/2;

	while(head && i<n-1)
	{
		head = head -> next;
		i++;
	}

	hnext = head ;
	
	while(hnext)
	{
		printf("%d %s %f\n",hnext->rollno,hnext->name,hnext->marks);
		hnext = hnext -> prev;
	}
	head = head -> next ;
	while(head)
	{
		printf("%d %s %f\n",head->rollno,head->name,head->marks);
		head = head -> next;
	}
}
