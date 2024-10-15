// print_pairs.cpp
#include<iostream>
using namespace std;

void printpairs(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			cout<<"("<<arr[i]<<","<<arr[j]<<") ";
		}
		cout<<endl;
	}
}

int main(){

	int arr[]={10,20,30,40,50,60,70,80,90,100};
	int n = sizeof(arr)/sizeof(int)	;

	printpairs(arr,n);

	return 0;
}