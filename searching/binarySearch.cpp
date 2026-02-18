#include<iostream>
#include<algorithm>
using namespace std;

int binarySearch(int a[], int n, int key){
	
	//sort(a,a+n);

	int low = 0;
	int high = n - 1;
	while(low <= high){
		int mid = low + (high - low)/2;
		
		if(a[mid] == key) {
			return mid;
		} 
		else if(key > a[mid]) {
			low = mid + 1;
		} 
		else {
			high = mid - 1;
		}
	}
	
	return -1;
}

int main()
{
	int a[5], key;
	int n = sizeof(a)/sizeof(a[0]);
	
	cout <<"Elements must be sorted\n";
	cout <<"Enter arr ele's\n";
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	
	cout <<"Enter ele to search : ";
	cin >> key;
	
	int res = binarySearch(a,n,key);
	
	res>=0 ? cout <<"Element is present at index : "<< res << endl : cout <<"Element is not present"<< endl;

	return 0;
}
