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

int getData(){
	int num;
	printf("Enter int to insert : ");
	scanf("%d",&num);
	return num;
}

int main()
{
	sll *head = NULL;
	while(true)
	{
		int op, num;
		printf("1.addBegin \t2.addEnd\n3.display\n");
		printf("Enter option : ");
		scanf("%d",&op);

		switch(op)
		{
			case 1 : addAtBegin(&head, getData()); 
				 break;
			case 2 : addAtEnd(&head, getData());   
				 break;
			case 3 : display(head);		       
				 break;
			case 4 : c = countNode(head);
				 printf("node count : %d",c);
				 break;
			case 5 : exit(0);
		}
	}
	return 0;
}
