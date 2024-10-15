// displacement.cpp
#include<iostream>
#include<string>
using namespace std;

int main(){



	char arr[1000];
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin.getline(arr,1000);
	// int len = arr.size();
	int x=0,y=0;
	for(int i=0;arr[i]!='\0';i++)
	{
		char ch = arr[i];
		switch(ch){
		case 'S': y--;
				break;
		case 'N': y++;
			break;
		case 'E': x++;
			break;
		case 'W': 	x--;
			break;
		}
	}
	cout<<x<<" "<<y<<endl;
	
	while(y!=0 or x!=0)
	{
		if(x>0)
		{
			cout<<"E";
			x--;
		}
		else if(x<0)
		{
			cout<<"W";
			x++;
		}
		else if(y>0)
		{
			cout<<"N";
			y--;
		}
		else if(y<0)
		{
			cout<<"S";
			y++;
		}
	}
		return 0;
}
