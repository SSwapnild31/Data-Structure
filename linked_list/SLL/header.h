#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct student
{
	int rollno;
	char name[20];
	float marks;
	struct student *next;
}SLL;

void add_begin(SLL**);
void print_data(SLL*);
