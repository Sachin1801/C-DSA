#include<iostream>
#include<unordered_map>
using namespace std ;

int main(){

    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(5);
    
    unordered_map<int,int> m;
    int n = arr.size();
    int p = 5;


    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }

    for(auto x:m){
        cout<<x.first<<" "<<x.second<<endl;
    }


    return 0;
}