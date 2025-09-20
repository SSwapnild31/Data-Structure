#include<stdio.h>
#include<stdlib.h>
#define size 5

int push(int[]);
int pop(int[]);
int display(int[]);

int top=-1;

int main()
{
	int a[size], ch;

	while(1)
	{
		printf("1.push 2.pop 3.display 4.exit\n");
		scanf("Enter option : ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1  : push(a);	break;
			case 2  : pop(a);	break;
			case 3  : display(a);	break;
			case 4  : exit(0);
			default : printf("wrong option.!!\n");
		}
	}
	return 0;
}
int display(int *a)
{
	if(top==-1)
	{
		printf("Stack is underflow\n");
		return 0;
	}
	printf("stack elements\n");
	int i=0;
	while(i<=top)
	{
		printf("%d ",a[i]);
		i++;
	}
	printf("\n");
	
	return 0;
}
int push(int *a)
{
	if(top==size-1)
	{
		printf("Stack is overflow\n");
		return 0;
	}
	int num;
	printf("Enter element : ");
	scanf("%d",&num);
	top++;
	a[top]=num;
	printf("Element %d pushed.\n",a[top]);
	
	return 0;
}

int pop(int *a)
{
	if(top==-1)
	{
		printf("Stack is underflow\n");
		return 0;
	}
	
	printf("Element %d poped.\n",a[top]);
	top--;
	
	return 0;
}


