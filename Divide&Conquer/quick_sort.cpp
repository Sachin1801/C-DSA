// quick_sort.cpp
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr,int s, int e)
{
	int piv = e;
	int i = -1, j = 0;
	while (j <= piv - 1)
	{
		if (arr[j] > arr[piv])
			j++;
		else
		{
			i++;
			swap(arr[i], arr[j++]);
		}
	}
	swap(arr[i + 1], arr[piv]);
	return i + 1;
}

void quicksort(vector<int> &arr, int s, int e)
{
	if(s>=e)
		return;
	
	//rec case

	int piv = partition(arr, s, e);

	quicksort(arr, s, piv - 1);
	quicksort(arr, piv + 1, e);

	return;
}

int main()
{
	freopen("input.txt", "r", stdin);
	?
	freopen("output.txt", "w", stdout);

	vector<int> arr;

	arr.push_back(0);
	arr.push_back(1);
	arr.push_back(0);
	// arr.push_back(1);
	// arr.push_back(4);
	// arr.push_back(7);
	// arr.push_back(8);

	int n = arr.size();
	

	quicksort(arr, 0, n - 1);

	for(int i=0;i < n; i++){
		cout<<arr[i]<<" ";
	}

	return 0;
}