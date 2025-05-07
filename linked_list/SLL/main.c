#include "header.h"

int main()
{
	SLL *headptr=0;
	int op,c;
	while(1)
	{
		printf("-------------------------------------------------------------------\n");
		printf(" 1.add_begin    2.add_end        3.add_at_middle   4.print_data   \n 5.count_node   6.save_file      7.read_file       8.reverse_print   \n 9.print_rec    10.reverse_rec   11.delete_all     16.exit\n");
		printf("-------------------------------------------------------------------\n");
		printf("Enter your choice : ");
		scanf("%d",&op);
		switch(op)
		{
			case 1: add_begin(&headptr);	break;
			case 2: add_end(&headptr);	break;
			case 3:
			case 4: print_data(headptr);	break;
			case 5: c=count_node(headptr);	
				printf("Total nodes : %d\n",c);	break;

			case 6: save_file(headptr);	break;
			case 7: read_file(&headptr);	break;
			case 8: reverse_print(headptr); break;
			case 9: printf("----------------------------\n");
				print_rec(headptr);	break;
			case 10: printf("----------------------------\n");
				 reverse_rec(headptr);	break;
			/*case 11: delete_all(&headptr);	break;
			case 12: //add_end(&headptr);	break;
			case 13:
			case 14: //print_data(headptr);	break;
			case 15: //print_data(headptr);	break;*/
			case 16: exit(0);
			default : printf("Invalid option..\n");
	
			return 0;
		}
	}
}

void reverse_rec(SLL *ptr)
{
	if(ptr)
	{
		if(ptr->next)
			reverse_rec(ptr->next);
		printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
	}
}


void print_rec(SLL *ptr)
{
	if(!ptr)
		return;
	printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
	print_rec(ptr->next);
}

void reverse_print(SLL *ptr)
{
	if(ptr==0)
	{
		printf("--------------------------------\n");
		printf("\033[31mRecords not available..!\033[0m\n");
		return;
	}
	int i,j;
	
	SLL *t=ptr;
	int c = count_node(ptr);
	printf("--------------------------------\n");
	for(i=0;i<c;i++)
	{
		t=ptr;
		for(j=0;j<c-1-i;j++)
			t=t->next;
		printf("%d %s %f\n",t->rollno,t->name,t->marks);
	}
}

void read_file(SLL **ptr)
{
	SLL *new,*last;
	FILE *fp;

	fp=fopen("stud.txt","r");

	if(fp==0)
	{
		printf("File not opened..!\n");
		return;
	}
	
	while(1)
	{
		new=malloc(sizeof(SLL));
	
		if(fscanf(fp,"%d %s %f",&new->rollno,new->name,&new->marks)==EOF)
			break;	
		new->next=0;
		if(*ptr==0)
			*ptr=new;
		else
		{
			last=*ptr;
			while(last->next)
				last=last->next;
			last->next=new;
		}
	}
	printf("\033[32mData readed successfully..\033[0m\n");
	
}

void save_file(SLL *ptr)
{
	FILE *fp=fopen("stud.txt","w");
	
	if(fp==0)
	{
		printf("File not opened..!\n");
		return;
	}

	while(ptr)
	{
		fprintf(fp,"%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
		ptr=ptr->next;
	}
	printf("\033[32mData saved in file.\033[0m\n");
	fclose(fp);
}

void add_end(SLL **ptr)
{
	SLL *new,*last; 
	new=malloc(sizeof(SLL));
	
	printf("Enter rollno,name & marks\n");
	scanf("%d %s%f",&new->rollno,new->name,&new->marks);
	new->next=0;
	
	if(*ptr==0)
		*ptr=new;
	else
	{
		last=*ptr;
		while(last->next)
			last=last->next;
		last->next=new;
	}
}

int count_node(SLL *ptr)
{
	int c=0;
	while(ptr)
	{
		c++;
		ptr=ptr->next;
	}
	return c;
}


void add_begin(SLL **ptr)
{
	SLL *new;
	new=malloc(sizeof(SLL));
	printf("Enter rollno,name & marks\n");
	scanf("%d %s %f",&new->rollno,new->name,&new->marks);
	
	new->next=*ptr;
	*ptr=new;
}	

void print_data(SLL *ptr)
{
	printf("\033[34;94m----------------------------\n");
	if(ptr==0)
	{
		printf("Data not found..!\n");
		printf("----------------------------\033[0m\n");
		return;
	}
	while(ptr)
	{
		printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
		ptr=ptr->next;
	}
	printf("----------------------------\033[0m\n");
}


