#include<iostream>
using namespace std ;

int setBit(int n) {
        // Write Your Code here
        int cnt = 0;
        int temp= n;
        while(temp&1){
            cnt++;
            temp = temp>>1;
        }
        int mask = 1<<cnt;
        return n | mask;
}

int main(){

    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    
    cout << setBit(15);

    return 0;
}