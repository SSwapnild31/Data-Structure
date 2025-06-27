#include<stdio.h>
#include<stdlib.h>

typedef struct st
{
	int rollno;
	char name[20];
	struct st *next;
}sll;

void print(sll*);
void add_beg(sll**);
void add_end(sll**);
int count_node(sll*);
void save_file(sll*);
void read_file(sll**);
void rev_print(sll*);
void recu_print(sll*);

void main()
{
	sll *head=0;
	int c;
	while(1)
	{
		int ch;
		printf("1.add_beg 2.add_end 3.print 4.count_node 5.save_file 6.read_file 7.recu_print 8.rev_print 16.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : add_beg(&head);	break;
			case 2 : add_end(&head);	break;	
			case 3 : print(head); 		break;
			case 4 : c = count_node(head);	
				 printf("total nodes are %d\n",c); break;
			case 5 : save_file(head);	break;
			case 6 : read_file(&head);	break;
			case 7 : recu_print(head);	break;
			case 8 : rev_print(head);	break;
			case 16 : exit(0);
			default: printf("wrong input.!\n");
		}
	}
}

void recu_print(sll *head)
{
	if(head==0)
		return ;
	printf("%d %s\n",head->rollno,head->name);
	recu_print(head->next);
}

void rev_print(sll *head)
{
	if(head==0)
		return ;
	rev_print(head->next);
	printf("%d %s\n",head->rollno,head->name);
}

void read_file(sll **head)
{
	FILE *fp=fopen("data","r");
	if(fp==0)
	{
		printf("file not present..!\n");
		return ;
	}
	while(1)
	{
		sll *new = malloc(sizeof(sll)), *last;
		if(fscanf(fp,"%d %s",&new->rollno,new->name)==EOF)
		{
			printf("data read sucessfully\n");
			break;
		}
		new -> next = 0;
		if(*head==0)
			*head = new;
		else
		{
			last = *head;
			while(last->next)
				last = last -> next;
			last -> next = new;
		}
	}
}

void save_file(sll *head)
{
	FILE *f1;
	f1=fopen("data","w");
	if(f1==0)
	{
		printf("file not opened..!\n");
		return ;
	}
	while(head)
	{
		fprintf(f1,"%d %s\n",head->rollno,head->name);
		head = head -> next;
	}
	printf("data is saved in file\n");
}

int count_node(sll *head)
{
	int c = 0; 
	while(head)
	{
		c++;
		head = head -> next;
	}
	return c;
}

void add_beg(sll **head)
{
	sll *new;
	new = malloc(sizeof(sll));
	printf("Enter rollno & name\n");
	scanf("%d%s",&new->rollno,new->name);
	new -> next = 0;
	if(*head==0)
		*head = new;
	else
	{
		new -> next = *head;
		*head = new;
	}
	
}

void add_end(sll **head)
{
	sll *new;
	new = malloc(sizeof(sll));
	printf("Enter rollno & name\n");
	scanf("%d%s",&new->rollno,new->name);
	new -> next = 0; 
	if(*head==0)
		*head = new;
	else
	{
		sll *temp=*head;

		while(temp->next)
			temp = temp -> next;
		temp -> next = new;
	}
}

void print(sll *head)
{
	while(head)
	{
		printf("%d %s\n",head->rollno,head->name);
		head = head -> next;
	}
}

