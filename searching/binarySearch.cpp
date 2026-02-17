#include<iostream>
using namespace std;

int binarySearch(int a[], int n, int key){
	
	return -1;
}

int main()
{
	int a[5], key;
	int n = sizeof(a)/sizeof(a[0]);
	
	cout <<"Enter arr ele's"<< endl;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	
	cout <<"Enter ele to search : ";
	cin >> key;
	
	int res = binarySearch(a,n,key);
	

	return 0;
}
