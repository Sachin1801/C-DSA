#include<iostream>
#include"list.h"
using namespace std ;

void print(Node *head){
    while(head!=NULL){
        cout<<head->get_data()<<"->";
        head= head->next;
    }
    cout<<endl;
}

Node* reverse_LL(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* temp;

    while(curr!=NULL){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

int main(){

    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    
    List l;
    l.push_back(5);
    l.push_back(4);
    l.push_back(3);
    l.push_back(2);
    l.push_back(1);
    l.push_back(0);

    print(l.begin());

    Node * newhead = reverse_LL(l.begin());
    print(newhead);

    return 0;
}