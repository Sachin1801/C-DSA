#include<string>
#include<iostream>
using namespace std;


template <typename T>
class Node{
public:
    Node* next;
    string key;
    T value;

    Node(string key, T value){
        this->key = key;
        this->value= value;
        next = NULL;
    }

    ~Node(){
        if(next!=NULL)
            delete next;
    }

};


template <typename T>
class HashTable{
private:
    int Hashfunc(string key){
        int idx = 0;
        int power = 1;

        for (auto x: key){
            idx = (idx + x*power)%ts;
            power = (power * 29) % ts ;
        }
        return idx;
    }

    void rehash(){
        cout<<"Rehashing the table"<<endl;

        //save the ptr to the old table
        Node<T> **oldTable = table;
        int oldTablesize = ts;

        cs =0;
        ts = (2*ts)+1;
        table = new Node<T>*[2*ts+1]; //ideally you should make it prime

        //each head ptr in new table is NULL
        for(int i=0;i<ts;i++){
            table[i]=NULL;
        }
        for(int i=0;i<oldTablesize;i++){
            Node<T>* temp = oldTable[i];
            while(temp!=NULL){
                string key = temp->key;
                T value = temp->value;

                //happen in the new table
                insert(key,value);
                temp = temp->next;
            }
            if(!oldTable[i])
                delete oldTable[i];
        }
        delete [] oldTable;
    }

public: 
    Node<T> **table;
    int cs; //total enteries in the table currently
    int ts; //total size of table

    HashTable(int default_size=7){
        ts = default_size;
        cs =0;
        table = new Node<T>*[ts];

        for(int i=0;i<ts;i++){
            table[i]=NULL;
        }
    }

    void insert(string key, T val){
        int idx = Hashfunc(key);
        Node<T> *n = new Node<T>(key,val);

        //insertion at the head of the linked list at table[idx]
        //this operation always remains O(1)
        n->next = table[idx];
        table[idx] = n;
        cs++;

        float load_factor = cs/(float)ts;

        if(load_factor > 0.7){
            rehash();
        }
    }

    T& operator[](string key){
        T* valueFound = search(key);
        if(!valueFound){
            T object;
            insert(key,object);
            valueFound = search(key); //again check where it is created
        }
        return *valueFound;
    }

    void print(){
        for(int i=0;i<ts;i++){
            cout<<"Bucket: "<<i<<"-> ";
            Node<T> *temp = table[i];
            while(temp){
                cout<<"["<<temp->key<<" , Value: "<<temp->value<<"] -> ";
                temp = temp->next;
            }
            cout<<endl<<endl;
        }
    }

    T* search(string key){
        int idx = Hashfunc(key);

        Node<T> *temp = table[idx];
        while(temp){
            if(temp->key==key)
                return &temp->value;

            temp= temp->next;
        }
        return NULL;
    }

    void erase(string key) {
        // Get the bucket index for the key
        int idx = Hashfunc(key);
        
        // Get the head of the linked list
        Node<T>* temp = table[idx];
        Node<T>* prev = NULL;
        
        // If bucket is empty
        if (temp == NULL) {
            return;
        }
        
        // If key is at head
        if (temp->key == key) {
            table[idx] = temp->next;
            temp->next = NULL;  // Prevent cascade deletion
            delete temp;
            cs--;
            return;
        }
        
        // Search for the key in the linked list
        while (temp != NULL && temp->key != key) {
            prev = temp;
            temp = temp->next;
        }
        
        // If key was not found
        if (temp == NULL) {
            return;
        }
        
        // Remove the node
        prev->next = temp->next;
        temp->next = NULL;  // Prevent cascade deletion
        delete temp;
        cs--;
    }

    
};