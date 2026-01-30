#include<stdio.h>
#include<stdlib.h>

typedef struct dll{ 
	int data;
	struct dll *next;
	struct dll *prev;
}dll;

void addBegin(dll **ptr, int num){
	dll *newNode = malloc(sizeof(dll));
	
	newNode->data = num;
	newNode->prev = NULL;
	newNode->next = *ptr;
	
	if(*ptr != NULL){
		(*ptr)->prev = newNode;
	}
	
	*ptr = newNode;
}

void addEnd(dll **ptr, int num){
	dll *newNode = malloc(sizeof(dll));
	
	newNode->data = num;
	newNode->next = NULL;

	if(*ptr == NULL){
		newNode->prev = NULL;
		*ptr = newNode;
		return;
	}
	
	dll *temp = *ptr;
	while(temp->next){
		temp = temp->next;
	}

	temp->next = newNode;
	newNode->prev = temp;

}

void display(dll *ptr){
	if(ptr == NULL){
		printf("Empty list!\n");
		return;
	}
	while(ptr){
		printf("-> %d ",ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

int countNode(dll *ptr){
	int c = 0;
	while(ptr){
		c++;
		ptr = ptr->next;
	}
	return c;
}

void reversePrint(dll *ptr){
	if(!ptr){
		printf("Empty list!\n");
		return;
	}
	
	while(ptr->next){
		ptr = ptr->next;
	}

	while(ptr){
		printf("%d <- ",ptr->data);
		ptr = ptr->prev;
	}
	printf("\n");
}

int main()
{
	dll *head = 0;
	while(1){
		int op, num, c;
		printf("1.addBegin\t2.addEnd\n3.display\t4.countNodes\n5.reversePrint\t6.exit\n");
		printf("Enter option : ");
		scanf("%d",&op);
		switch(op){
			case 1 : printf("Enter number : "); scanf("%d",&num); addBegin(&head, num);	break;
			case 2 : printf("Enter number : "); scanf("%d",&num); addEnd(&head, num);	break;
			case 3 : display(head);		break;
			case 4 : c = countNode(head); printf("Total nodes : %d\n",c);		break;
			case 5 : reversePrint(head);	break;
			case 6 : exit(0);
			default: printf("wrong option! Try again!\n");
		}
	}

	return 0;
}
