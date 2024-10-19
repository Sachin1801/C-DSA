#include<iostream>
#include"list.h"
using namespace std ;

void print(Node* head){
    while(head!=NULL){
        cout<<head->get_data()<<"->";
        head = head->next;
    }
    cout<<endl;
    return;
}
int main(){

    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);

    List l;
    l.push_back(1);
    l.push_front(0);
    l.push_back(2);
    l.insert(3,2);
    l.insert(2,2);
    l.insert(4,0);


    print(l.begin());

    // l.pop_front();
    l.pop_back();
    l.delete_at(3);

    print(l.begin());

    
    // cout<<l.recursive_search(3)<<endl;

    

    return 0;
}