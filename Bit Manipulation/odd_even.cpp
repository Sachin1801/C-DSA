// odd_even.cpp
#include<iostream>
using namespace std;

int main(){

	int n=5;
	cin>>n;

	if((n & 1) == 1)
		cout<<"Number is odd"<<endl;
	else
		cout<<"Number is even"<<endl;
	

	return 0;
}