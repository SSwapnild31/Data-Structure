#include<stdio.h>
#include<stdlib.h>

typedef struct st {
	int data;
	struct st *next;
}node;

void addEnd(node **ptr, int num){
	node *newNode = malloc(sizeof(node));
	newNode->data = num;
	newNode->next = 0;

	if(*ptr == 0){
		*ptr = newNode;
		return ;
	}
	
	node *temp = *ptr;

	while(temp->next){
		temp = temp->next;
	}
	temp->next = newNode;
}

void addBegin(node **ptr, int num){
	node *newNode = malloc(sizeof(node));
	newNode->data = num;
	newNode->next = *ptr;
	*ptr = newNode;
}

void display(node *ptr){
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

int nodeCount(node *ptr){
	int c = 0;
	while(ptr){
		c++;
		ptr = ptr->next;
	}
	return c;
}

void reversePrint(node *ptr){
	if(ptr){
		reversePrint(ptr->next);
		printf("%d <- ",ptr->data);
	}
}

int main()
{
	node *head = 0;
	while(1){
		int op, num, c;
		printf("1.addBegin\t2.addEnd \n3.display\t4.nodeCount\n5.revresePrint\t6.exit\n");
		printf("Enter op : ");
		scanf("%d",&op);
		switch(op){
			case 1 : printf("Enter num : "); scanf("%d",&num); addBegin(&head, num); break;
			case 2 : printf("Enter num : "); scanf("%d",&num); addEnd(&head, num);   break;
			case 3 : display(head);							 break;
			case 4 : c = nodeCount(head); printf("Total nodes : %d\n",c);		 break;
			case 5 : reversePrint(head);  printf("\n");				 break;
			case 6 : exit(0);
			default: printf("wrong option! Enter again!\n");
		}
	}
	return 0;
}
