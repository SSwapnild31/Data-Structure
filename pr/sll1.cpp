#include<iostream>
#include<memory>
using namespace std;

class sll
{
	int roll;
	string name;
	float marks;
	shared_ptr<sll> next = nullptr;
public :
	void add_begin(shared_ptr<sll>&);
	void add_end(shared_ptr<sll>&);
	int count_node(shared_ptr<sll>);
	void display(shared_ptr<sll>);
};

void sll::add_begin(shared_ptr<sll> &ptr)
{
	shared_ptr<sll> newnode = make_shared<sll>();
	cout <<"Enter rollno, name and marks" << endl;
	cin >> newnode->roll >> newnode->name >> newnode->marks;
	
	newnode->next = ptr;
	ptr = newnode;
}

void sll::add_end(shared_ptr<sll> &ptr)
{
	
	
}

void sll::display(shared_ptr<sll> ptr)
{
	if(ptr==0)
	{
		cout <<"Records not present."<< endl;
		return ;
	}
	while(ptr)
	{
		cout << ptr->roll <<" "<< ptr->name <<" "<< ptr->marks << endl;
		ptr = ptr -> next;
	}
}

int sll::count_node(shared_ptr<sll> ptr)
{
	if(ptr == nullptr)
	{
		cout <<"Records not present."<< endl;
		return 0;
	}
	int c = 0;
	while(ptr)
	{
		c++;
		ptr = ptr -> next;
	}
	return c;
}

int main()
{
	shared_ptr<sll> head = nullptr;

	while(1)
	{
		int op, c;
		cout <<"1.add_begin \t2.add_end \n3.count_node \t4.display \n5.exit"<< endl;
		cout <<"Enter option : ";
		cin >> op;
		switch(op)
		{
			case 1 : head->add_begin(head);		break;
			case 2 : head->add_end(head);		break;
			case 3 : c = head->count_node(head);	
				 cout <<"node count : "<< c << endl;	break;
			case 4 : head->display(head);		break;
			case 5 : exit(0);
			default : cout <<"wrong option!"<< endl;
		}
	}
	
	return 0;
}
