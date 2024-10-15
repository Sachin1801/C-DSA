// array_backtracking.cpp
#include<iostream>
using namespace std;

void fillArray(int *arr, int i, int n){
	//base case
	if(i==n){
		return;
	}

	//rec case
	cout<<arr[i]<<" ,";
	fillArray(arr,i+1,n);
	arr[i] *= -1;
	return;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int arr[100];
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	fillArray(arr,0,n);
	
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}	

	return 0;
}