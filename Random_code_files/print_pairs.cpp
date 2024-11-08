// print_pairs.cpp
#include<iostream>
using namespace std;

void printpairs(int *arr, int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			cout<<"("<<arr[i]<<","<<arr[j]<<")";
		}
		cout<<endl;
	}
	return;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int arr[]={1,2,3,4};
	int n= sizeof(arr)/sizeof(int);

	printpairs(arr,n);


	return 0;
}