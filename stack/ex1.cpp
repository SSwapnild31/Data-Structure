#include<iostream>
#define size 50
using namespace std;

class Stack
{
	int top;
	int stk[size];
 public :
	Stack()
	{
		top = -1;
	}
	
	void push()
	{
		if(top==size)
		{
			cout<<"stack is overflow"<< endl;
			return ;
		}
		cout <<"Enter ele to insert : ";
		cin >> stk[++top];
	}
	
	void pop()
	{
		if(top==-1)
		{
			cout <<"stack is underflow"<< endl;
			return ;
		}
		cout <<"deleted : "<< stk[top--] << endl;
	}
	
	void display()
	{
		if(top==-1)
		{
			cout <<"stack is empty..!"<< endl;
			return ;
		}
		for(int i=0;i<=top;i++)
			cout << stk[i] <<" ";
		cout << endl;
	}
};

int main()
{
	Stack obj;
	int op;
	while(1)
	{
		cout <<"1.push \n2.pop \n3.display \n4.exit"<< endl;
		cout <<"Enter option : ";
		cin >> op;
		switch(op)
		{
			case 1  : obj.push();		break;
			case 2  : obj.pop();		break;
			case 3  : obj.display();	break;
			case 4  : exit(0);
			default : cout <<"unknown oprion..!"<< endl;
		}
	}
	return 0;
}
