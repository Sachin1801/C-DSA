// compress_string.cpp
#include<iostream>
#include<string>
using namespace std;

string compressstring(string s)
{
	int n = s.length();
	string output;

	for(int i=0;i<n;i++)
	{
		int cnt =1 ;
		while(i<n-1 && s[i]==s[i+1])
		{
			cnt++;
			i++;
		}
		output += s[i];
		output += to_string(cnt);
	}
	if(output.length()> n)
		return s;
	else
		return output;
}

int main(){
		
	string s1 = "aaabbccddee";
	cout<<compressstring(s1)<<endl;

	string s2 = "abcd";
	cout<<compressstring(s2)<<endl;



	return 0;
}