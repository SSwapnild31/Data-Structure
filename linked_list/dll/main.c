#include<stdio.h>
#include<stdlib.h>

typedef struct st
{
	struct st *prev;
	int rollno;
	char name[20];
	float marks;
	struct st *next;

}node;

int main()
{
	node *head = 0,*new = 0;
	int i=0;
	while(i<2)
	{
		new = malloc(sizeof(node));
		printf("Enter rollno, name & marks\n");
		scanf("%d %s %f",&new->rollno,new->name,&new->marks);
		
		if(head==0)
		{
			new -> prev = 0;
			new -> next = head;
			head = new;
		}
		else
		{
			node *temp = head;
			while(temp -> next)
				temp = temp -> next;
			new -> prev = temp;
			new -> next = 0;
			temp -> next = new ;
		}
		i++;
	}
	
	while(head)
	{
		printf("%d %s %f\n",head->rollno,head->name, head->marks);
		head = head -> next;
	}

	free(new);

}
