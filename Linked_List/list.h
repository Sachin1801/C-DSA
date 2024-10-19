
using namespace std;

class List;
class Node{
    int data;
    

public: 
    Node(int d): data(d), next(NULL){}
    Node* next;
    int get_data(){
        return data;
    }

    friend class List;

    ~Node(){
        if(next!=NULL) 
            delete next;
    }
};

class List{
    Node* head;
    Node* tail;

    int helper(Node* start, int key){
        if(start==NULL){
            return -1;
        }
        if(start->data==key){
            return 0;
        }
        int subidx = helper(start->next, key);

        return subidx==-1? -1 : 1+subidx;
    }

public:
    List(): head(NULL), tail(NULL){}

    Node* begin(){
        return head;
    }
    void push_front(int d){
        if(!head and !tail){
            Node *n = new Node(d);
            head = tail = n;
        }else{
            Node* n = new Node(d);
            n->next = head;
            head = n;
        }
    }

    void push_back(int d){
        if(head==NULL){
            Node *n = new Node(d);
            head = tail = n;
        }else{
            Node* n = new Node(d);
            tail->next = n;
            tail = n;
        }
    }

    void insert(int d, int pos){
        if(pos==0){
            push_front(d);
            return;
        }else{
            Node* temp = head;
            while(pos>1 and temp->next!=NULL){
                temp = temp->next;
                pos--;
            }
            Node *n = new Node(d);
            n->next = temp->next;
            temp->next= n;
        }
    }

    int search(int key){
        Node* temp = head;
        int idx=0;

        while(temp!=NULL){
            if(temp->data==key){
                return idx;
            }
            idx++;
            temp=temp->next;
        }
        return -1;
    }

    int recursive_search(int key){
        int idx = helper(head,key);
        return idx;
    }

    void pop_front(){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void pop_back(){
        Node* temp = head;
        while(temp->next->next!= NULL){
            temp= temp->next;
        }
        Node* temp2 = tail;
        tail = temp;
        tail->next = NULL;
        delete temp2;
    }

    void delete_at(int pos){
        Node* temp = head;
        while(pos>1){
            temp = temp->next;
            pos--;
        }
        Node* temp2= temp->next->next;
        temp->next->next = NULL;
        temp->next = temp2;
    }

    ~List(){
        if(head!=NULL){
            delete head;
            head = NULL;
        }
    }

};