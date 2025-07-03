#include"header.h"

int main()
{
	dll obj;
	int c, op;
	while(1)
	{
		cout <<"1.add_begin 2.add_end 3.print_node 4.count_node 5.write_file 6.read_file 16.exit"<< endl;
		cin >> op;
		switch(op)
		{
			case 1  : obj.add_begin();	break;
			case 2  : obj.add_end();	break;
			case 3  : obj.print_node();	break;
			case 4  : c = obj.count_node();
				  cout <<"total nodes are "<< c << endl;	break;
			//case 5  : obj.write_file();	break
			//case 6  : obj.read_file();	break;
			case 16 : exit(0);
			default : cout <<"wrong oprion..!"<< endl;
		}
	}
	return 0;
}

int dll::count_node()
{
	student *temp=head;
	int c = 0;
	while(temp)
	{
		c++;
		temp = temp -> next;
	}
	return c;
}

void dll::print_node()
{
	student *rev,*last=head;
	cout <<"--------------------"<< endl;
	while(last)
	{
		cout << last->rollno <<" "<< last->name <<" "<< last->marks <<endl;
		rev = last;
		last = last->next;
	}
	last = rev;
	cout <<"++++++++++++++++++++"<< endl;
	while(last)
	{
		cout << last->rollno <<" "<< last->name <<" "<< last->marks <<endl;
		last = last->prev;
	}
	cout <<"--------------------"<< endl;
}

void dll::add_end()
{
	student *node = new student;
	
	if(head==0)
		head = node;
	else
	{
		student *last=head;
		while(last->next)
			last = last->next;
		last -> next = node;
		node->prev = last;
	}
}

void dll::add_begin()
{
	student *node = new student;
	
	if(head==0)
		head = node;
	else
	{
		node->next = head;
		node->next->prev = node;
		head = node;
	}	
}

