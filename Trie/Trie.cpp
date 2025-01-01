#include<iostream>
#include"trie.h"
using namespace std;

int main(){

    string words[]={"apple","aple","ape","banana","coach","Sachin","news","new"};

    Trie t;

    for(string word: words){
        t.insert(word);
    }

    string key;
    cin>>key;

    if(t.search(key)){
        cout<<key<<" is present in the trie"<<endl;
    }else{
        cout<<key<<" is not present in the trie"<<endl;
    }

    return 0;

}