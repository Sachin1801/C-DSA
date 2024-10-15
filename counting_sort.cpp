// counting_sort.cpp
#include<iostream>
#include<vector>
using namespace std;

void counting_sort(int arr[], int n)
{
	int largest=-1;
	for(int i=0;i<n;i++)
	{
		largest= max(largest,arr[i]);
	}

	vector<int> freq(largest+1,0);
	for(int i=0;i<n;i++)
	{
		freq[arr[i]]++;
	}

	//put elements back into the old array

	int j=0;
	for(int i=0;i<=largest;i++)
	{
		while(freq[i]>0)
		{
			arr[j++]=i;
			freq[i]--;
		}
	}
	return;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int arr[] = {78, 52, 41, 10,2,87,102,105, 33, 67,};
	int n = sizeof(arr) / sizeof(int);

	counting_sort(arr,n);

	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<", ";
	}
	cout<<endl;

	return 0;
}