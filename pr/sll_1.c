#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}sll;

void addAtBegin(sll **ptr, int key){
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


void addAtEnd(sll **ptr, int key){
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

int countNode(sll *ptr){
	int c = 0;
	while(ptr){
		c++;
		ptr = ptr->next;
	}
	return c;
}

void display(sll *ptr){
	
	if(ptr == NULL){
		printf("Empty List!!\n");
		return;
	}
	while(ptr){
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

void reversePrint(sll *ptr){
	if(ptr == NULL){
		printf("Empty List!!\n");
		return;
	}
	while(ptr){
		reversePrint(ptr->next);
		printf("%d ",ptr->data);
	}
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
	while(1)
	{
		int op, num, c;
		printf("1.addBegin \t2.addEnd\n3.display\t4.countNode\n5.reversePrint\t6.exit\n");
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
				 printf("node count : %d\n",c);
				 break;
			case 5 : reversePrint(head);
				 break;
			case 6 : exit(0);
			default: printf("wrong oprion!!\n");
		}
	}
	return 0;
}
