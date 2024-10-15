// find_displacement.cpp
#include<iostream>
using namespace std;

int main(){

	char input[100];
	cin.getline(input,100);

	int x=0,y=0;

	for(int i=0;i< strlen(input);i++)
	{
		char temp = input[i];
		if(temp=='S')
			y--;
		else if(temp=='N')
			y++;
		else if(temp=='E')
			x++;
		else
			x--;
	}	
	while(x>0)
	{
		while(y>0)
		{
			cout<<"N";
			y--;
		}
		while(y<0)
		{
			cout<<"S";
			y++;
		}
		cout<<"E";
		x--;
	}
	while(x<0)
	{
		while(y>0)
		{
			cout<<"N";
			y--;
		}
		while(y<0)
		{
			cout<<"S";
			y++;
		}
		cout<<"W";
		x++;
	}

	return 0;
}