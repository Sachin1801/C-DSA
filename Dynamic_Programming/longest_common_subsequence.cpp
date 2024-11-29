#include<iostream>
#include<string>
using namespace std ;


int lcs(string a, string b,int i, int j, vector<vector<int> > &dp ){
    if(i==a.length() or j ==b.length()){
        return dp[i][j] = 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(a[i]==b[j]){
        return dp[i][j] =  1 + lcs(a,b,i+1,j+1,dp);
    }
    int opt1 = lcs(a,b,i+1,j,dp);
    int opt2 = lcs(a,b,i,j+1,dp);
    return dp[i][j] =  max(opt1,opt2);

}
int main(){

    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    
    string a = "abcd";
    int n = a.length();
    
    string b = "abedg";
    int m = b.length();

    vector<vector<int> > dp(n+1,vector<int>(m+1,-1));

    cout<<lcs(a,b,0,0, dp)<<endl;

    for(int i=0;i<=n;++i){
        for(int j=0;j<=m;++j){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}