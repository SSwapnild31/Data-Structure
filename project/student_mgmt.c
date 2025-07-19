#include<stdio.h>
#include<stdlib.h>

typedef struct student
{
	int rollno;
	char name[20];
	float marks;
	struct student *next;
}std;

void add_student(std **);
void search_student(std *);
void delete_student(std **);
void display_all(std *);
void save_file(std *);
void read_file(std **);
int count_students(std *);

void main()
{
	printf("---------------------------------------\n");
	printf("       \033[36;96mStudent Management System\033[0m       \n");

	std *head=0;
	int op, c;
	while(1)
	{
		printf("---------------------------------------\n");
		printf("1.Add new Student  2.Search student\n");
		printf("3.Delete student   4.Dipslay all studs\n");
		printf("5.Save to file     6.Update student\n");
		printf("7.Read from file   8.Count students\n");
		printf("9.Exit(Log Out)\n");
		printf("---------------------------------------\n");
		printf("Enter option : ");
		scanf("%d",&op);
	
		switch(op)
		{
			case 1 : add_student(&head);		break;
			case 2 : search_student(head);		break;
			case 3 : delete_student(&head);		break;
			case 4 : display_all(head);		break;
			case 5 : save_file(head);		break;
			//case 6 : update_student();		break;
			case 7 : read_file(&head);		break;
			case 8 : (c = count_students(head)) ? printf("\033[32;92mTotal students: %d\033[0m\n",c) : printf("\033[31;91mStudents not present..!\033[0m\n");	break;
			case 9 : printf("---------------\033[36;96mThank You\033[0m---------------\n");
				 exit(0);
			default :printf("\033[31;91mwrong option..!\033[0m\n"); 
		}
	}
}

void delete_student(std **head)
{
	printf("---------------------------------------\n");
	if(*head==0)
	{
		printf("\033[31;91mStudents are not present..!\033[0m\n");
		return ;
	}

	int roll_no;
	printf("Enter rollno ro delete : ");
	scanf("%d",&roll_no);

	std *del,*last;

	if((*head)->rollno == roll_no)
	{
		del = *head;
		if((*head)->next)
			*head = (*head)->next;
		else
			*head = 0;
	}
	else
	{
		last = *head;
		while(last->next && (last->next->rollno)!=roll_no)
			last = last -> next;
		del = last -> next;
		last -> next = last -> next -> next;
	}
	free(del);
	del = 0;
	printf("\033[32;92rollno %d data deleted successfully.\033[0m\n",roll_no);
}

void read_file(std **head)
{
	printf("---------------------------------------\n");
	FILE *fp = fopen("student.txt","r");
	std *new,*last;

	if(fp==0)
	{
		printf("\033[32;92mFile not opened..!\033[0m\n");
		return ;
	}
	if((fscanf(fp,"%d %s %f",&new->rollno,new->name,&new->marks))==EOF)
	{
		printf("\033[31;91mFile is empty..!\033[0m\n");
		return ;
	}
	rewind(fp);

	while(1)
	{
		new = calloc(1,sizeof(std));
		if((fscanf(fp,"%d %s %f",&new->rollno,new->name,&new->marks))==EOF)
			break;
		if(*head==0)
		{
			*head = new;
		}
		else
		{
			last = *head;
			while(last -> next)
				last = last -> next;
			last -> next = new;
		}
	}
	printf("\033[32;92mData readed successfully.\033[0m\n");
}

void save_file(std *head)
{
	printf("---------------------------------------\n");
	if(head==0)
	{
		printf("\033[31;91mData not present to store..!\033[m\n");
		return ;
	}
	FILE *fp = fopen("student.txt","w");
	if(fp==0)
	{
		printf("\033[31;91mFile not opened..!\033[0m\n");
		return ;
	}
	while(head)
	{
		fprintf(fp,"%d %s %f\n",head->rollno,head->name,head->marks);
		head = head -> next;
	}
	printf("\033[33;93mData saved into file.\033[0m\n");
}

void search_student(std *head)
{
	printf("---------------------------------------\n");
	if(head==0)
	{
		printf("\033[31;91mStudent are not present..!\033[0m\n");
		return ;
	}

	int roll_no;
	printf("Enter rollno to search : ");
	scanf("%d",&roll_no);
	
	while(head)
	{
		if(head->rollno == roll_no)
		{
			printf("---------------------------------------\n");
			printf("\033[32;92mFound : %d %s %.2f\033[0m\n",head->rollno,head->name,head->marks);
			return ;
		}
		head = head -> next;
	}
	
	printf("---------------------------------------\n");
	printf("\033[31;91mRollno not present..!\033[0m\n");

}

void display_all(std *head)
{
	printf("---------------------------------------\n");
	if(head==0)
	{
		printf("\033[31;91mStudents are not present..!\033[0m\n");
		return ;
	}
	printf("Rollno	   Name	   Marks\n");
	while(head)
	{
		printf("  %d      %s     %.2f\n",head->rollno,head->name,head->marks);
		head = head -> next;
	}
}

int count_students(std *head)
{
	printf("---------------------------------------\n");
	
	int c = 0;
	while(head)
	{
		c++;
		head = head -> next;
	}
	return c;
}

void add_student(std **head)
{
	printf("---------------------------------------\n");
	std *new = calloc(1,sizeof(std));
	printf("Name : ");
	scanf(" %[^\n]",new->name);
	printf("Rollno : ");
	scanf("%d",&new->rollno);
	printf("Marks : ");
	scanf("%f",&new->marks);
	
	if((*head==0) || (new->rollno < (*head)->rollno))
	{
		new -> next = *head;
		*head = new;
	}
	else
	{
		std *last = *head;
		while((last -> next) && (new->rollno > (last->next->rollno)))
			last = last -> next;
		new -> next = last -> next;
		last -> next = new;
	}
	printf("---------------------------------------\n");
	printf("\033[32;92mStudent added successfully.\033[0m\n");
}
