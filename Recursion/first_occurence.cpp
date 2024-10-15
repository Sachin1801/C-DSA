// first_occurence.cpp
#include<iostream>
using namespace std ;

int first_occurence(int arr[], int n, int key)
{
    if(arr[0]== key)
    {
        return 0;
    }
    if(n==0)
        return -1;
    int index = first_occurence(arr+1,n-1,key);
    if(index == -1)
        return -1;
    return 1 + index ;
}

int last_occurence(int arr[], int n, int key)
{
    //base case
    if(n==0)
    {
        return -1;
    }
    //rec case

    int idx = last_occurence(arr+1,n-1,key);

    if(idx==-1 &&arr[0]==key)
        return 0;
    if(idx==-1)
        return -1;
    return idx+1;

}

int main(){

    int arr[]={1,3,5,7,6,7,33,5,2,7,1,0,2};
    int  n = sizeof(arr)/sizeof(int);

    int key; 
    cin>>key;

    int ans = first_occurence(arr,n,key);
    cout<<ans<<endl;

    ans = last_occurence(arr,n,key);
    cout<<ans<<endl;
    cout<<ans<<endl;

    return 0;
}