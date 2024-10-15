// minimum_difference.cpp
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;


pair<int,int> minDifference(vector<int> a,vector<int> b){
    //Complete this method
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    pair<int,int> ans;
    int i=0,j=0;
    int al = a.size(),bl=b.size();
    int mind=INT_MAX;
    while(i<al and j<bl)
    {
        int currd=0;
        if(a[i]<b[j])
        {
            currd = b[j]-a[i];
            if(currd<mind)
            {
                ans.first = a[i];
                ans.second=b[j];
                mind = currd;
            }
            i++;
        }
        else if(a[i]>b[j])
        {
            currd = a[i]-b[j];
            if(currd<mind)
            {
                ans.first = a[i];
                ans.second=b[j];
                mind = currd;
            }
            j++;
        }
    }
    cout<<ans.first<<" , "<< ans.second<<endl;
    return ans;
    
}

int main(){

	vector<int> v1{ 23, 5, 10, 17, 30};
	vector<int> v2{ 26, 134, 135, 14, 19};

	pair<int,int> p = minDifference(v1,v2);


	return 0;
}