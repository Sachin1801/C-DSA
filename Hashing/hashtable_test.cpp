#include"hashtable.h"
#include<iostream>
using namespace std ;

int main(){

    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    
    HashTable<int> h;

    h.insert("Mango",100);
    h.insert("Apple",200);
    h.insert("Banana",400);
    h.insert("Watermelon",100);
    h.insert("Lichi",800);
    h.insert("Guava",100);
    h.insert("Orange",100);
    h.insert("Peach",567);
    h.insert("Wild Berry",122);
    h.insert("Pomogranite",100);
    h.insert("Kiwi",1234);

    h.print();

    string fruit;
    cin>>fruit;

    int *price = h.search(fruit);
    if(price!=NULL)
        cout<<"Found at price of fruit is: "<<*price<<endl;
    else
        cout<<"Fruit not found"<<endl;

    h["newFruit"]=212;
    cout<<"New fruit cost: "<<h["newFruit"]<<endl;
    h["newFruit"]=312;
    cout<<"New fruit cost updated: "<<h["newFruit"]<<endl;
    

    return 0;
}