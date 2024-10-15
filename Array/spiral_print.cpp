// spiral_print.cpp
#include<iostream>
using namespace std;

void print_spiral(int arr[][10], int n ,int m )
{

	int sr=0,sc=0,er=n-1,ec=m-1;

	while(sr<=er and sc <=ec)
	{
		//start row
		for(int i=sc;i<=ec;i++)
		{
			cout<<arr[sr][i]<<", ";
		}
		
		//end col
		for(int i=sr+1;i<=er;i++)
		{
			cout<<arr[i][ec]<<", ";
		}
		
		//end row
		for(int i=ec-1;i>=sc;i--)
		{
			cout<<arr[er][i]<<", ";
		}

		//start col
		for(int i=er-1;i>=sr+1;i--)
		{
			cout<<arr[i][sc]<<", ";
		}
		sr++;
		ec--;
		er--;
		sc++;
	}
}

int main(){
	
	int arr[10][10]={{1,2,3,4},
					{5,6,7,8},
					{9,10,11,12},
					{13,14,15,16}};

	int n=4,m=4;

	print_spiral(arr,n,m);	

	return 0;
}