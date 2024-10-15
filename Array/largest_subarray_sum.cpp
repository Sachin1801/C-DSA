// largest_subarray_sum.cpp
#include<iostream>
using namespace std;

//Brute Force
int lar_subarray(int arr[],int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			int subarr=0;
			for(int k=i;k<=j;k++)
			{
				subarr+=arr[k];
				
			}
			sum=max(subarr,sum);
		}
	}
	return sum;
}

//Prefix sum Approach
int lar_subarray_prefix(int arr[],int n)
{
	int prefix[100]={0};
	prefix[0]=arr[0];

	for(int i=1;i<n;i++)
	{
		prefix[i]= prefix[i-1]+arr[i];
	}
	int sum=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			int subarrarysum = i>0 ? prefix[j]-prefix[i-1] : prefix[j] ;
			sum=max(subarrarysum,sum);
		}
	}
	return sum;
}

//Kadane's Algorithm 

int kadane_algo(int arr[], int n)
{
	int cs=0,ms=0;
	for(int i=0;i<n;i++)
	{
		cs += arr[i];
		if(cs<0)
		{
			cs =0 ;
		}
		ms = max(ms,cs);
	}
	return ms;
}

int main(){

	int arr[]={-2,3,4,-1,5,-12,6,1,3};
	int n = sizeof(arr)/sizeof(int)	;

	int ans = lar_subarray(arr,n);
	int ans2 = lar_subarray_prefix(arr,n);	
	int ans3 = kadane_algo(arr,n);

	cout<<ans<<endl;
	cout<<ans2<<endl;
	cout<<ans3<<endl;

	return 0;
}