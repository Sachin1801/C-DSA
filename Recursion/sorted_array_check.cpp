// sorted_array_check.cpp
#include<iostream>
using namespace std ;

bool sorted_array(int arr[],int n){
    if(n==0 || n==1){
        return true;
    }
    if(arr[0]<arr[1] && sorted_array(arr+1,n-1)){
        return true;
    }
    return false;
}
int main(){

    int arr[]={1,2,3,4,5,8,9,10};

    int n= sizeof(arr)/sizeof(int);

    int i=0;

    if(sorted_array(arr,n)){
        cout<<"Sorted array"<<endl;
    }
    else{
        cout<<"Not sorted array"<<endl;
    }

    return 0;
}