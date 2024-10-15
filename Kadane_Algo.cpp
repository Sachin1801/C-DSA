// Kadane_Algo.cpp
#include<iostream>
using namespace std;

int kadane_algo(int *arr, int n)
{
	int cs=0;
	int ms=0;

	for (int i = 0; i < n; ++i)
	{
	cs += arr[i];
		if(cs>ms)
			ms = max(ms,cs);
		if(cs<0)
			cs=0;
	}
	return ms;
}

int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int arr[]={-2,3,4,-1,5,-12,6,1,3};	
	int n = sizeof(arr)/sizeof(int);

	cout<<kadane_algo(arr,n)<<endl;


	return 0;
}