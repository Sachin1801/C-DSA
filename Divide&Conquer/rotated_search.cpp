// rotated_search.cpp
#include<iostream>
using namespace std;

int rotated_search(vector<int> &arr, int key){
	int s =0 ;
	int n = arr.size();
	int e = n-1;

	while(s<=e){
		int mid= (s+e)/2;

		if(arr[mid]==key)
			return mid;
		if(arr[s]<= arr[mid]){ //this means we are on the left line 
			if(key>=arr[s] and key <= arr[mid])
				e = mid-1;
			else
				s = mid+1;
		}
		//this means mid lies on the right line of the curve 
		else{
			if(key<= arr[e] and key >= arr[mid])
				s = mid+1;
			else
				e=mid-1;
		}
	}
	return -1;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	vector<int> arr;

	arr.push_back(4);
	arr.push_back(5);
	arr.push_back(6);
	arr.push_back(7);
	arr.push_back(0);
	arr.push_back(1);
	arr.push_back(2);	
	arr.push_back(3);	

	int n = arr.size();

	cout<< rotated_search(arr,12) <<" " <<endl;

	return 0;
}