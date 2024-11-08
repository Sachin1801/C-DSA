// search_algorithms.cpp
#include<iostream>
using namespace std;

int linear_search(int *m, int n, int key)
{
	for (int i = 0; i < n; ++i)
	{
		if(m[i]==key)
		{
			return i;
		}
	}
	return -1;
}

int binary_search(int *arr, int n , int key)
{
	int s= 0;
	int e= n-1;
	while(s<=e)
	{
		int mid = (s+e)/2;
		if(arr[mid]==key)
			return mid;
		else if(arr[mid]>key)
			e= mid-1;
		else 
			s= mid+1;
	}
	return -1;

}

int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int m[] ={10,2,3,8,15,9,12,14,9,7,6,0,10};


	int n= sizeof(m)/sizeof(int);
	sort(m,m+n);
	for (int i = 0; i < n; ++i)
	{
		cout<<m[i]<<" ";
	}
	cout<<endl;

	int key;
	cin>>key;
	cout<< binary_search(m,n,key)<<endl;
	// cout<<linear_search(m,n,key)<<endl;

	return 0;
}