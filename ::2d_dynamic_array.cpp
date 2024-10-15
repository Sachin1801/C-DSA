//2d_dynamic_array.cpp
#include<iostream>
using namespace std;

int ** create2darray(int rows, int cols)
{
	int **arr = new int*[rows];

	//cretion of 2d dynamic array
	for(int i=0;i<rows;i++)
	{
		arr[i] = new int[cols];
	}

	//init the value with inc numbers

	int val=0;

	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++)
		{
			arr[i][j]=val;
			val++;
		}
	}

	return arr;

}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int **arr = create2darray(3,3);

	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}

		

	return 0;
}