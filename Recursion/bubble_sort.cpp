// bubble_sort.cpp
#include<iostream>
using namespace std ;


void bubble_sort(int arr[], int  n, int j){
    
    //base case 
    if(n==1)
    {
        return ;
    }
    if(j==n-1){
        bubble_sort(arr,n-1,0);
    }

    if(arr[j]>arr[j+1]){
        swap(arr[j],arr[j+1]);
    }
    // helper_swap(arr,n,0);
    bubble_sort(arr,n,j+1);
}

int main(){

    int arr[] = {-3, 10, -1, 4, 7, -2, 0, 5, -8, 3};
    int n = sizeof(arr)/sizeof(int);

    bubble_sort(arr,n,0);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<",";
    }

    return 0;
}