// sorting_algo.cpp
#include <iostream>
#include <algorithm>
using namespace std;

void bubble_sort(int arr[], int n)
{
	for (int i = 1; i <= n - 1; i++)
	{
		for (int j = 0; j <= n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}

void insertion_sort(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int temp = arr[i];
		int j = i - 1;
		int ptr = i;
		while (j >= 0 and arr[j] > temp)
		{
			arr[ptr] = arr[j];
			ptr--;
			j--;
		}
		arr[ptr] = temp;
	}
}

void selection_sort(int arr[], int n)
{
	for (int pos = 0; pos <= n - 2; pos++)
	{
		int temp = pos;
		for (int i = pos; i < n; i++)
		{
			if (arr[i] < arr[temp])
				temp = i;
		}
		swap(arr[pos], arr[temp]);
	}
}

bool compare(int a, int b)
{
	return a > b;
}

// inbuilt Sorting function
void inbuilt_sort(int arr[], int n)
{
	// sort(arr, arr + n, compare);

	//inbuilt_comparator

	sort(arr,arr+n,greater<int>());

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{

	

	int arr[] = {7, -5, 4, 1, 2,8, 3, 6};
	int n = sizeof(arr) / sizeof(int);

	// bubble_sort(arr,n);
	// insertion_sort(arr,n);
	// selection_sort(arr,n);
	inbuilt_sort(arr, n);

	// for(int i=0;i<n;i++)
	// {
	// 	cout<<arr[i]<<",";
	// }
	// cout<<endl;

	return 0;
}
