#include "header.h"

int main()
{
	SLL *headptr=0;
	int op;
	while(1)
	{
		printf("1.add_begin \n4.print_data \n16.exit\n");
		printf("Enter your choice..\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1: add_begin(&headptr);	break;
			case 4: print_data(headptr);	break;
			case 16: exit(0);
			default : printf("Invalid option..\n");
		}
	}
}

void add_begin(SLL **ptr)
{
	SLL *new;
	new=malloc(sizeof(SLL));
	printf("Enter rollno,name & marks\n");
	scanf("%d %s %f",&new->rollno,new->name,&new->marks);
	
	new->next=*ptr;
	*ptr=new;
}	

void print_data(SLL *ptr)
{
	printf("\033[34m----------------------------\n");
	if(ptr==0)
	{
		printf("Data not found..!\n");
		return;
	}
	while(ptr)
	{
		printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
		ptr=ptr->next;
	}
	printf("----------------------------m]\n");
}
