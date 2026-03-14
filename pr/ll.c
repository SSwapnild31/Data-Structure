#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}sll;

void addBegin(sll**);
void addEnd(sll**);
void display(sll*);
int nodeCount(sll*);

int main()
{
	sll *head = 0;
	int c, op;
	while(1){
		printf("1.addBegin\t2.addEnd\n3.display\t4.nodeCount\n5.exit\n");
		printf("Enter option : ");
		scanf("%d",&op);

		switch(op){
			case 1 : addBegin(&head);	break;
			case 2 : addEnd(&head);		break;
			case 3 : display(head);		break;
			case 4 : c = nodeCount(head);	
				 printf("Total nodes : %d\n",c);break;
			case 5 : exit(0);
			default: printf("oops! wrong option!\n");
		}
	}
}

void addBegin(sll**){
	
}

void addEnd(sll** head){
	sll *new = malloc(sizeof(sll));
	
	printf("Enter data : ");
	scanf("%d",&new->data);
	new->next = 0;
	
	if(*head == 0){
		*head = new;
	}
	else{
		sll *last = *head;
		while(last->next)
			last = last -> next;
		last -> next = new;
	}
}

void display(sll* head){
	if(head == 0){
		printf("Empty list!\n");
		return;
	}
	while(head){
		printf("-> %d ",head->data);
		head = head -> next;
	}
	printf("\n");
}

int nodeCount(sll* head){
	int count = 0;
	while(head){
		count++;
		head = head -> next;
	}
	return count;
}
