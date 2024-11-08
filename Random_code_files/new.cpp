#include<iostream>

using namespace std;


void printarray(int m[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout<<m[i]<<" ,";
	}
	cout<<endl;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	// int n;
	// cin>> n;


	int m[] ={10,20,30,40,50, 100};

	int n= sizeof(m)/sizeof(int);

	printarray(m, n);

	// for (int i = 0; i < n; ++i)
	// {
	// 	cin>> m[i];
	// }

	
	

	return 0;
}