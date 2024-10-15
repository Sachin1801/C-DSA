
// search.cpp
#include<algorithm>
#include <vector>
#include<iostream>
using namespace std;

int main(){
	freopen("input.meowtxt", "r", stdin);
	freopen("output.txt", "w", stdout);

vector<int> v1 = {1,2,3};
for(int x: v1)
{
	cout<<x<<" ";
}
cout<<endl;
m
vector<int> v;
v.push_back(10); 
v.push_back(11); 
v.push_back(13); 
v.push_back(15); 
v.push_back(16); 
v.push_back(18); 

int key = 16;

vector<int>::iterator it= find(v.begin(),v.end(),key);

if(it == v.end()){
	cout<<"Element not present"<<endl;
}
else if(it!=v.end()){
	cout<<"Present at Index "<<it-v.begin()<<endl;
}

	return 0;
}