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

void add_begin(SLL **);
void print_data(SLL *);
int count_node(SLL *);
void save_file(SLL *);

void reverse_print(SLL *);
void add_end(SLL **);
void read_file(SLL **);
void print_rec(SLL *);

void reverse_rec(SLL *);
void delete_all(SLL **);
