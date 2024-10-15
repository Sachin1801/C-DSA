// lower_bound.cpp
#include<iostream>
#include<vector>
using namespace std;

int lower_bound(vector<int> arr , int n, int key)
{
	for (int i = 0; i < n; ++i)
	{
		if(arr[i]==key)
			return  i;
		else if(i>0 && arr[i]>key)
		{
			return i-1;
		}
		else if(i==0 && arr[i]>key)
			return 0;
	}
	return n-1;
}

int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	vector<int> arr;
	int n =5;
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		arr.push_back(t);	
	}
	
	int key;
	cin>>key;

	cout<<lower_bound(arr,n,key)<<" - element present at this array location"<<endl;


	return 0;
	
}
