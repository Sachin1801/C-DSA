// pointers.cpp
#include<iostream>
using namespace std;

void watchvideo(int *viewsPtr)
{
	*viewsPtr = *viewsPtr + 1;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

int views= 100;

watchvideo(&views);

cout<<views<<endl;



	return 0;
}