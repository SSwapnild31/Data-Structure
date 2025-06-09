#include<stdio.h>
#include<stdlib.h>

typedef struct st
{
	struct st *prev;
	int rollno;
	char name[20];
	float marks;
	struct st *next;

}node;

void add_begin(node**);
void add_end(node**);
void add_middle(node**);
void print_data(node*);
