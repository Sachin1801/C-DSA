#include<iostream>
using namespace std ;

int fact(int n){
    if(n==1)
    {
        return 1;
    }

    return n*fact(n-1);
}

/**
 * This is the main entry point of the program.
 *
 * It asks the user to enter a positive integer, and then
 * prints the factorial of that number.
 */

int main(){
    
    int n;
    cin>>n;

    cout<<fact(n)<<endl;
    

    return 0;
}