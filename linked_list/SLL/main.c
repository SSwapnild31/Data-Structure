#include "header.h"

int main()
{
	SLL *headptr=0;
	int op,c;
	while(1)
	{
		printf("1.add_begin 2.add_end 3.add_at_middle 4.print_data \n5.count_nodes 6.save_file 7.read_file 8.reverse_print \n9.print_rec 10.reverse_rec 11.delete_all \n16.exit\n");
		printf("Enter your choice..\n");
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
			/*case 7: read_file(&headptr);	break;
			case 8: reverse_print(headptr); break;
			case 9: print_rec(headptr);	break;
			case 10: reverse_rec(headptr);	break;
		
			case 11: delete_all(&headptr);	break;
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
		fprintf(fp,"%d %s %f",ptr->rollno,ptr->name,ptr->marks);
		ptr=ptr->next;
	}
	printf("Data saved in file.\n");
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
	printf("\033[34m----------------------------\n");
	if(ptr==0)
	{
		printf("Data not found..!\n");
		return;
	}
	while(ptr)
	{
		printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
		ptr=ptr->next;
	}
	printf("----------------------------\033[0m\n");
}


