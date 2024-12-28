#include<iostream>
using namespace std ;

void printsubsequences(int arr[], int n, int idx, vector<int> &ds){
    if(idx == n){
        cout << "Subsequence: ";
        for(auto x: ds){
            cout<<x<<" ";
        }
        if(ds.size()==0){
            cout<<"{}";
        }
        cout<<endl;
        return;
    }
    ds.push_back(arr[idx]);
    printsubsequences(arr,n,idx+1,ds);
    ds.pop_back();
    printsubsequences(arr,n,idx+1,ds);
}

int main(){

    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    
    int arr[] = {3,1,2};
    int n = sizeof(arr)/sizeof(int);

    vector<int> ds;
    printsubsequences(arr,n,0,ds);



    return 0;
}