// largest_string.cpp
#include<iostream>
#include<string>
using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin>>n;

	cin.get();

	char sentence[1200];
	int maxlen=-1;
	char ans[1200];
	while(n--)
	{
		cin.getline(sentence,1200);
		int len = strlen(sentence);
		if(len > maxlen)
		{
			maxlen=len;
			strcpy(ans,sentence);
		}
	}
	cout<<ans<<" with length "<<maxlen<<endl;

	return 0;
}