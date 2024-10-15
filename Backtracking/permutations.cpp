// permutations.cpp
#include<iostream>
using namespace std ;

void permutations(string input, int i){
    //base case
    if(input[i]=='\0'){
        cout<<input<<", ";
    }

    //rec case
    
    
    for(int j=i;j<input.length();j++){
        swap(input[i],input[j]);
        permutations(input,i+1);
        swap(input[i],input[j]);
    }
    return ;
}

int main(){

    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    
    string input;
    cin>>input;


    permutations(input,0);




    return 0;
}