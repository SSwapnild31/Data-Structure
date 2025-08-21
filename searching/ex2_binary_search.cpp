#include<iostream>
#include<algorithm>
using namespace std;

int search_bin(int *a, int ele, int key)
{
	sort(a,a+ele);
	
	int first = 0,last = ele-1,mid;
	
	while(first<=last)
	{
		mid = (first + last)/2;
		if(a[mid]==key)
			return mid;
		else if(a[mid] < key)
			first = mid + 1;
		else
			last = mid -1;	
	}
	
	return -1;
}

int main()
{
	int a[5],key;
	int ele = sizeof(a)/sizeof(a[0]);
	
	cout <<"Enter "<< ele <<" array ele's"<< endl;
	for(int i=0;i<ele;i++)
		cin >> a[i];
	
	cout <<"Enter key to search : ";
	cin >> key;
	
	int pos = search_bin(a,ele,key);
	if(pos>=0)
		cout <<"key found at "<< pos <<" position."<<endl;
	else
		cout <<"key not present"<< endl;
	
	return 0;
}

