

template<typename T>
class Stack;

template<typename T>
class Node{
public:
    T data;
    Node<T> *next;

    Node(T d){
        data = d;
    }
};

template<typename T>
class Stack{
    Node<T> *head;

    public:
    Stack(){
        head= NULL;
    }

    void push(T d){
        Node<T>* n = new Node<T>(d);
        n->next = head;
        head = n;
    }

    void pop(){
        if(head!=NULL){
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool empty(){
        return head==NULL;
    }

    T top(){
        if(!empty())
            return head->data;
    }

};

