#include<stdio.h>
#include<stdlib.h>

#define size 5

int front = -1, rear = -1; 

void enqueue(int *a)
{
	if(rear==size-1)
	{
		printf("queue is full(overflow)\n");
		return ;
	}
	int num;
	printf("Enter int data : ");
	scanf("%d",&num);

	if(front==-1)
		front = 0;
	rear++;
	a[rear] = num;
	printf("%d inserted into queue\n",num);
}

void dequeue(int *a)
{
          if(front==-1 || front > rear)
          {
                  printf("queue is empty(underflow)\n");
                  return ;
          }
 
          printf("%d deleted from queue\n",a[front]);
          front++;
}

void display(int *a)
{
	if(front==-1)
	{
		printf("queue is empty (underflow)\n");
		return ;
	}
	for(int i=front; i<=rear ; i++)
		printf("%d ",a[i]);
	printf("\n");
}


int main()
{
	int a[size], op;
	
	while(1)
	{
		printf("\t1.enqueue \n\t2.dequeue \n\t3.display \n\t4.exit\n");
		printf("Enter option : ");
		scanf("%d",&op);
		switch(op)
		{
			case 1  : enqueue(a);		break;
			case 2  : dequeue(a);		break;
			case 3  : display(a);		break;
			case 4  : exit(0);		
			default : printf("wrong option.!\n"); 
		}
	}
	return 0;
}
