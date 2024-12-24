#include<iostream>
#include<vector>
using namespace std ;
class Node{
public:
    int data;
    Node*next;
    Node* back;

public: 
    Node(int data, Node*next, Node* back1){
        this->data = data;
        this->next = next;
        back = back1;
    }
public: 
    Node(int data){
        this->data = data;
        next = NULL;
        back= NULL;
    }

};

Node* constructDLL(vector<int> &v){
    Node* head = new Node(v[0]);
    Node* prev =head;
    for(int i=1;i<v.size();i++){
        Node* temp = new Node(v[i],NULL,prev);
        prev->next = temp;
        prev = prev->next;
    }
    return head;
}

void printDLL(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    return;
}

int main(){

    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);

    vector<int> v ;
    for(int i=1;i<=10;i+=2){
        v.push_back(i);
    }
    Node* head = constructDLL(v);
    printDLL(head);
    

    return 0;
}