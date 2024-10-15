// largest_string.cpp
#include<iostream>
using namespace std;

int main(){

	int n;
	cin>>n;

	cin.get();

	char sentence[1000];
	char largest[1000];
	int maxlen=0,currlen=0;
	while(n--)
	{
		cin.getline(sentence,1000);
		currlen = strlen(sentence);
		if(currlen > maxlen)
		{
			maxlen= currlen;
			strcpy(largest,sentence);
		}	
	}	
	cout<<"largest senbtence is"<<largest<<endl;


	return 0;
}