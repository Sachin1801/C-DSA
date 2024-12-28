#include<iostream>
using namespace std ;

void printsubsequences(int arr[], int n, int idx, vector<int> &ds,int currsum, int target){
    if(idx >= n){
        if(currsum == target){
            cout << "Subsequence: ";
            for(auto x: ds){
                cout<<x<<" ";
            }
            cout<<endl;
        }
        return;
    }
    if(currsum > target)
        return;
    ds.push_back(arr[idx]);
    currsum += arr[idx];
    printsubsequences(arr,n,idx+1,ds,currsum,target);
    ds.pop_back();
    currsum -= arr[idx];
    printsubsequences(arr,n,idx+1,ds, currsum,target);
}

int main(){

    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    
    int arr[] = {5,2,3,10,6,8};
    int n = sizeof(arr)/sizeof(int);

    vector<int> ds;
    int sum = 10;
    printsubsequences(arr,n,0,ds,0, sum);



    return 0;
}