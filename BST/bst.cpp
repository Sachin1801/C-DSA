#include<iostream>
#include<vector>
using namespace std ;

class Node{
    public:
    int key;
    Node* left;
    Node* right;

    Node(int key){
        this->key = key;
        left = right = NULL;

    }
};

Node* insert(Node* root, int key){
    if(root == NULL){
        return new Node(key);
    }
    if(root->key > key ){
        root->left = insert(root->left,key);
    }else{
        root->right= insert(root->right, key);
    }
    return root;
}

void printInorder(Node* root){
    if(root==NULL)
        return;
    printInorder(root->left);
    cout<<root->key << " ";
    printInorder(root->right);
    return;
}

bool search(Node* root, int target){
    if(root==NULL){
        return false;
    }
    if(root->key== target)
        return true;
    else if(target < root->key)
        return search(root->left,target);
    else
        return search(root->right,target);
}

Node* FindMin(Node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

Node *remove(Node* root, int key){
    if(root==NULL)
        return NULL;
    else if(key < root->key){
        root->left = remove(root->right,key);
    }else if(key > root->key){
        root->right = remove(root->right,key);
    }else{
        //when root matches with the key 
        //case 1 - no children
        if(!root->left and !root->right){
            delete root;
            root = NULL;
        }
        //case 2 - 1 children
        
        else if(!root->right){
            Node* temp = root;
            root = root->left;
            delete temp;
        }else if(!root->left){
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        //case 3 - 2 children 
        else{
            Node* temp = FindMin(root->right);
            root->key = temp ->key;
            root->right = remove(root->right, temp->key);
        }


        return root;
    }
    return root;
}

void PrintInRange(Node* root, int k1, int k2){
    if(root==NULL)
        return;
    if(root->key >=k1 and root->key <= k2 ){
        PrintInRange(root->left,k1,k2);
        cout<<root->key<<", ";
        PrintInRange(root->right,k1,k2);
    }else if(root->key < k1){
        PrintInRange(root->right,k1, k2);
    }else if(root->key > k2){
        PrintInRange(root->left,k1,k2);
    }
    return;
}

void PrintAllPaths(Node* root, vector<int> &out){
    if(root == NULL){
        return;
    }
    if(root->left==NULL and root->right==NULL){
        for(auto x : out){
            cout<<x<<",  ";
        }
        cout<<root->key;
        cout<<endl;
        return;
    }
    out.push_back(root->key);
    PrintAllPaths(root->left,out);
    PrintAllPaths(root->right,out);
    out.pop_back();
    return;
}

int main(){

    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    
    Node* root = NULL;
    //random number array 
    int arr[] = {8,3,2,10, 1 ,9 ,5,4, 7 ,12 } ;
    for(auto x : arr){
        root = insert(root, x);
    }

    printInorder(root);

    int key;
    cin>>key;

    if(search(root,key))
        cout<<"Present"<<endl;
    else
        cout<<"Not present"<<endl;

    root = remove(root,key);

    if(search(root,key))
        cout<<"Present"<<endl;
    else
        cout<<"Not present"<<endl;
    
    PrintInRange(root, 5,12);
    cout<<endl;

    vector<int> out;
    PrintAllPaths(root,out);


    return 0;
}