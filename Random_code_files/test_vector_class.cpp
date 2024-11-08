// test_vector_class.cpp
#include<iostream>
#include "vector.h"
using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	Vector<char> ch;

	ch.push_back('a');
	ch.push_back('b');
	ch.push_back('c');

	for(int i=0;i<ch.size();i++)
	{
		cout<<ch[i]<<",";
	}
	cout<<endl;


	Vector<int> v(5);

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(40);
	v.push_back(10);
	v.push_back(6);

	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;

	v.pop_back();

	for(int i=0;i<v.size();i++)
	{
		cout<<v.at(i)<<" ";
	}
	cout<<endl;

	cout<<v.capacity()<<endl;

	cout<<v.size()<<endl;

	cout<<v.capacity()<<endl;

	cout<<v.front()<<" "<<v.back()<<endl;


	
	

	return 0;
}