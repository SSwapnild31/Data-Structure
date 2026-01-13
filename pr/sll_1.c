#include<stdio.h>

typedef struct node
{
	int data;
	struct node *next;
}sll;

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

int main()
{
	sll *head = NULL;
	addAtEnd(&head, 10);
	
	return 0;
}
