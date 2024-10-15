// array.cpp
#include<iostream>
using namespace std;

void print(int arr[], int n)
{
	arr[0]=100;
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ,";
	}
	cout<<endl;
}

int main(){
	int n;
	int marks[100];
	cin>>n;
	for (int i = 0; i<n; ++i)
		{
			cin>>marks[i];
			marks[i]=marks[i]*2;
		}	

	print(marks,n);

	for (int i = 0; i < n; ++i)
	{
		cout<<marks[i]<<" ,";
	}

	return 0;
}