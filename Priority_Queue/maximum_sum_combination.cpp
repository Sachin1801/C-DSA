#include<vector>
#include<set>
#include<unordered_map>
#include<iostream>
using namespace std;

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    sort(A.begin(),A.end(),greater<int>());
    sort(B.begin(),B.end(),greater<int>());
    priority_queue<pair<int,pair<int,int>>> maxheap; // to store {sum,{i,j}} in the max heap
    maxheap.push({A[0]+B[0],{0,0}});
    set<pair<int,int> > s; //set to ensure we do not store duplicates
    s.insert({0,0});
    
    vector<int> ans;
    while(C-- && !maxheap.empty()){
        auto topsum = maxheap.top();
        maxheap.pop();
        int sum = topsum.first;
        ans.push_back(sum);
        int i = topsum.second.first;
        int j = topsum.second.second;
        
        if(i+1 < A.size() && s.find({i+1,j})==s.end()) //not present in the set and can be added to the priority priority_queue
        {
            maxheap.push({A[i+1]+ B[j],{i+1,j}});
            s.insert({i+1,j});
        }
        if(j+1<B.size() && s.find({i,j+1})==s.end()){
            maxheap.push({A[i]+B[j+1],{i,j+1}});
            s.insert({i,j+1});
        }
    }
    return ans;
}
