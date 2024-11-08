// 2d_array.cpp
#include<iostream>
using namespace std;

void print(int arr[][1000],int n, int m)x
{
for(int i=0;i<n;i++)
{
	for(int j=0;j<m; j++)
		{
			cout<<arr[i][j]<<" ";
		}
	cout<<endl;
	}
}


int main(){

freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);	

int arr[1000][1000];

int n,m;
cin>>n>>m;

for(int i=0;i<n;i++)
{
	for(int j= 0;j<m; j++)
	{
		cin>>arr[i][j];
	}
}

print(arr,n,m);

	return 0;
}