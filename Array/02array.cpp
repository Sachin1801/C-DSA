#include<iostream>
using namespace std;

int search(int arr[], int n,int key){
	for(int i=0;i<n;i++)
	{
		if(arr[i]==key)
		{
			return i;
		}	
	}
	return 0;
}

int main(){
	
	int arr[]={1,3,4,2,8,4,90,35,4,9,43,2,56};
	int n = sizeof(arr)/sizeof(int);
	int key ;
	cin>>key;
	int ans = search(arr,n,key);

	cout<<"Index is: "<<ans<<" and the key is "<<arr[ans]<<endl;

	return 0;
}