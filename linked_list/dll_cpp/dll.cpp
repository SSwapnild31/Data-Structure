#include"header.h"
#include<fstream>
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
			case 5  : obj.write_file();	break;
			case 6  : obj.read_file();	break;
			case 16 : exit(0);
			default : cout <<"wrong oprion..!"<< endl;
		}
	}
	return 0;
}

void dll::read_file()
{
	ifstream fin("data");
	if(!fin)
	{
		cout <<"file not found..!"<< endl;
		return ;
	}
	
	while(1)
	{
		if(fin.tellg()==-1)
			break;
		student *node = new student;
		fin >> node->rollno >> node->name >> node->marks;
		if(head==0)
			head = node;
		else
		{
			student *temp = head;
			while(temp->next)
				temp = temp -> next;
			temp -> next = node;
			node -> prev = temp;
		}
	}
	cout <<"Data reading successful.."<< endl;
}

void dll::write_file()
{
	student *temp=head;
	ofstream fout("data");
	if(!fout)
	{
		cout <<"file not found..!"<< endl;
		return ;
	}
	while(temp)
	{
		fout << temp->rollno <<" "<< temp->name <<" "<< temp->marks << endl;
		temp = temp -> next;
	}
	cout <<"Data stored into file."<< endl;
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

