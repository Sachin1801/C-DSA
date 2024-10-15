// binary_search.cpp
#include<iostream>
using namespace std;

int binary_search(int arr[], int n, int key)
{
	int s=0;
	int e=n-1;
	int mid;

	while(s<=e)
	{
		mid = (s+e)/2;

		if(arr[mid]==key)
			{
				return mid;
			}
		else if(key< arr[mid])
			{
				e=mid-1;
			}
		else{
			s=mid+1;
		}
	
	}
	return -1;
	
}

int main(){
	
	int arr[]={10,20,30,40,50,60,70,80,90,100};
	int n = sizeof(arr)/sizeof(int)	;

	int key;
	cin>>key;

	int ans= binary_search(arr,n,key);

	if(ans==-1)
	{
		cout<<"Key not found"<<endl;
	}
	else{
		cout<<ans<<" : "<<arr[ans]<<endl;
	}
	return 0;
}