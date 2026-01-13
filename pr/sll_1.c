#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}sll;

void addAtBegin(sll **ptr, int key)
{
	sll *new = malloc(sizeof(sll));
	new->data = key;
	new->next = NULL;

	if(*ptr == NULL){
		*ptr = new;
		return ;
	}

	new->next = *ptr;
	*ptr = new;
}


void addAtEnd(sll **ptr, int key)
{
	sll *new = malloc(sizeof(sll));
	new->data = key;
	new->next = NULL;
	
	if(*ptr == NULL){
		*ptr = new;
	}else{
		sll *temp = *ptr;
		while(temp->next){
			temp = temp->next;
		}
		temp->next = new;
	}
}

void display(sll *ptr){
	while(ptr){
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}


int main()
{
	sll *head = NULL;
	addAtEnd(&head, 10);
	addAtEnd(&head, 20);
	display(head);
	addAtBegin(&head, 5);
	display(head);
	return 0;
}
