//dynamic_array.cpp
#include<iostream>
using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin>>n;

	//dynamic array
	int *arr = new int[n];

	// cout<<arr<<endl;

	for(int i=0;i<n;i++)
	{
		arr[i] = i;
		cout<<arr[i]<<" ";
	}
	// cout<<endl;

	delete [] arr;

	// cout<<arr<<endl;
	// cout<<arr[2]<<endl;

	//2d Dynamic array

	


	return 0;
}
