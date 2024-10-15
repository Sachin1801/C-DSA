// grid_paths.cpp
#include<iostream>
using namespace std ;

int grid_paths(int grid[][4], int n, int i, int j){
    //base case 
    if(i>=n or j>=n)
        return 0;
    if(i==n-1 and j==n-1){
        return 1;
    }

    //rec case
    if(grid[i][j]==1)
        return 0;

    return grid_paths(grid,n,i,j+1) + grid_paths(grid,n,i+1,j) ;

}

int main(){

    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    
    int grid[4][4] = {
    {0, 0, 1, 0},
    {1, 0, 0, 0},
    {0, 0, 1, 1},
    {0, 0, 0, 0}
    };

    int n=4;
    cout<<grid_paths(grid,n,0,0);


    return 0;
}