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
int  nodeCount(sll*);
void reversePrint(sll*);
void reverseList(sll**);
void swapNearby(sll**);

int main()
{
	sll *head = 0;
	int c, op;
	while(1){
		printf("1.addBegin\t2.addEnd\n3.display\t4.nodeCount\n5.revPrint\t6.revList\n7.swapNearby\t8.exit\n");
		printf("Enter option : ");
		scanf("%d",&op);

		switch(op){
			case 1 : addBegin(&head);					break;
			case 2 : addEnd(&head);						break;
			case 3 : display(head);						break;
			case 4 : c = nodeCount(head);	
				 	 printf("Total nodes : %d\n",c);	break;
			case 5 : reversePrint(head);	
				 	 printf("\n");						break;
			case 6 : reverseList(&head);				break;
			case 7 : swapNearby(&head);					break;
			case 8 : exit(0);
			default: printf("oops! wrong option!\n");
		}
	}
}

void swapNearby(sll** head){
	
    if(!(*head) || !(*head)->next) return;

    sll* newHead = (*head) -> next;

    sll* prev = NULL;
    sll* curr = *head;

    while(curr && curr->next){
        sll* first = curr;
        sll* second = curr -> next;

        //swap
        first -> next = second -> next;
        second -> next = first;

        if(prev)
            prev -> next = second;

        //move ptr's
        prev = first;
        curr = first -> next;
    }
    
	*head = newHead;
	printf("Nearby swapped.\n");
}

void reverseList(sll** head){
	
	if(*head == 0) {
		printf("Empty list!\n");
		return;
	}
	
	sll *curr = *head, *prev = NULL, *nxt = NULL;
	while(curr){
		nxt = curr -> next;
		curr -> next = prev;

		prev = curr;
		curr = nxt;
	}
	*head = prev;

	printf("List reversed!\n");
}

void reversePrint(sll* head){
	if(head == 0)	return;
	
	reversePrint(head->next);
	printf("%d <- ",head->data);
}

void addBegin(sll** head){
	sll *new = malloc(sizeof(sll));
	
	printf("Enter data : ");
	scanf("%d",&new->data);
	new->next = 0;
	
	if(*head == 0){
		*head = new;
		return;
	}
	
	new -> next = *head;
	*head = new;
}

void addEnd(sll** head){
	sll *new = malloc(sizeof(sll));
	
	printf("Enter data : ");
	scanf("%d",&new->data);
	new->next = 0;
	
	if(*head == 0){
		*head = new;
		return;
	}

	sll *last = *head;
	while(last->next)
		last = last -> next;
	last -> next = new;
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
