#include<stdio.h>

typedef struct st {
	int data;
	struct st *next;
}node;

void addAtEnd(node **ptr, int num){
	node *new = malloc(sizeof(node));
	new->data = num;
	new->next = 0;

	if(*ptr == 0){
		*ptr = new;
		return ;
	}
	
	node *temp = *ptr;

	while(temp->next){
		temp = temp->next;
	}
	temp->next = new;
}

void addAtBegin(node **ptr, int num){
	node *new = malloc(sizeof(node));
	new->data = num;
	new->next = *ptr;
	*ptr = new;
}


int main()
{
		
	return 0;
}
