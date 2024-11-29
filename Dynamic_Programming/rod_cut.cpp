#include<iostream>
using namespace std ;

void print_pieces(int size_arr[],int n){
    int i = n;

    while(i>0){
        cout<<size_arr[i]<<" ";
        i -= size_arr[i];
    }    
    cout<<endl;
    return;
}
    
pair<int,int> cut_rod(int prices[], int n){
    int rank[5];
    int size_arr[5];
    rank[0]=0;
    for(int i=1;i<=n;++i){ //runs n times
        rank[i]=0;
        for(int j=1;j<=i;++j){ // for every value of i - runs n times
            if(prices[j]+rank[i-j]>rank[i]){
                rank[i]= prices[j]+rank[i-j];
                size_arr[i]=j;
            }
        }
    }
    print_pieces(size_arr,n);
    return make_pair(rank[n],size_arr[n]);
}

int main(){

    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);

    int prices[]={0,2,5,3,5};
    pair<int,int> ans= cut_rod(prices,4);
    cout<<ans.first<<endl;
    
    return 0;
}