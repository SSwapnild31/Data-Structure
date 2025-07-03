#include<iostream>
using namespace std;

class student
{
 public :
	student *prev;
	int rollno;
	char name[20];
	float marks;
	student *next;
	student()
	{
		cout <<"Enter student data"<< endl;
		cout <<"rollno : ";
		cin >> rollno;
		cout <<"name   : ";
		cin >> name;
		cout <<"marks  : ";
		cin >> marks;
		prev = next = 0;
	}
};

class dll
{
	student *head;
public :
	dll(){
		head = 0;
	}
	void add_begin();
	void add_end();
	void print_node();
	int count_node();
};
