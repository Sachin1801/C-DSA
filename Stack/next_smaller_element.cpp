vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int> ans(A.size(),-1);
    int n1 = A.size();
    stack<pair<int,int> > s;
    for(int i=n1-1;i>=0;i--){
        while(!s.empty() and s.top().first>A[i]){
            ans[s.top().second] = A[i];
            s.pop();
        }
        
        s.push({A[i],i});
    }
    return ans;
}