#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

typedef struct student
{
	int rollno;
	char name[20];
	float marks;
	struct student *next;
}sll;

void add_begin(sll**);
void add_end(sll**);
void add_middle(sll**);
void display(sll*);

int main()
{
	int ch;
	sll *head = 0;
	while(1)
	{
		printf("1.add_begin 2.add_end 3.add_middle 4.display 10.exit\n");
		printf("Enter option : ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1  : add_begin(&head);	break;
			case 2  : add_end(&head);	break;
			case 3  : add_middle(&head);	break;
			case 4  : display(head);	break;
			case 10 : exit(0);
			default : printf("wrong option.!!\n");
		}
	}
	return 0;
}

void add_middle(sll **ptr)
{
	sll *new = malloc(sizeof(sll));
	
	printf("Enter rollno, name & marks\n");
	scanf("%d%s%f",&new->rollno,new->name,&new->marks);
	
	if(*ptr==0 || new->rollno<(*ptr)->rollno)
	{
		new->next = *ptr;
		*ptr = new;
	}
	else
	{
		sll *temp = *ptr;
		while(temp->next && new->rollno>temp->next->rollno)
			temp = temp->next;

		new->next = temp->next;
		temp->next = new;
	}
}

void add_end(sll **ptr)
{
	sll *new = malloc(sizeof(sll));
	
	printf("Enter rollno, name & marks\n");
	scanf("%d%s%f",&new->rollno,new->name,&new->marks);
	
	new->next = 0;
	
	if(*ptr==0)
		*ptr = new;
	else
	{
		sll *last=*ptr;
		while(last->next)
			last = last->next;
		last->next = new;
	}
}

void add_begin(sll **ptr)
{
	sll *new = malloc(sizeof(sll));
	
	printf("Enter rollno, name & marks\n");
	scanf("%d%s%f",&new->rollno,new->name,&new->marks);
	
	new->next = 0;
	
	if(*ptr==0)	{ 
		*ptr = new;
	}
	else	{
		new->next = *ptr;
		*ptr = new;
	}
}

void display(sll *ptr)
{
	if(ptr==0)
	{
		printf("List is empty\n");
		return ;
	}
	printf("student data\n");
	while(ptr)
	{
		printf("%d %s %.2f\n",ptr->rollno,ptr->name,ptr->marks);
		ptr = ptr->next;
	}
}

