// merge_sort.cpp
#include<iostream>
using namespace std;

void merge(int arr[], int s, int e){
	int i = s;
	int mid = (s + e) /2 ;
	int j = mid +1;
	int k =0 ;
	int *temp = new int[e];


		while(i<=mid && j <=e){
			if(arr[i]<arr[j])
				temp[k++]=arr[i++];
			else 
				temp[k++]=arr[j++];
		}
		while(i<=mid){
			temp[k++]= arr[i++];
		}
		while(j<=e){
			temp[k++] = arr[j++];
		}
		
		copy(temp, temp + (e-s+1), arr+s);

		return ;


}

void mergesort(int arr[],int s,int e){

	//BASE CASE
	if(s>=e)
		return;

	int mid = (s +e)/ 2;

	mergesort(arr,s,mid);
	mergesort(arr,mid+1,e);

	merge(arr,s,e);

	return ;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int arr[] = { 3, 5, 2, 1, 4 ,7, 8, 10};

	int n  = sizeof(arr)/sizeof(int);

	mergesort(arr,0,n-1);


	for(int i=0;i < n; i++){
		cout<<arr[i]<<" ";
	}

		

	return 0;
}