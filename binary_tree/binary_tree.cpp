#include<iostream>
#include<queue>
using namespace std ;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        left = right = NULL;
        data = d;
    }
};

//pre-order build of binary tree
Node* buildTree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    Node* n = new Node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}

void print_pre_order(Node* root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    print_pre_order(root->left);
    print_pre_order(root->right);
    return;
}

void print_inorder(Node* root){
    if(root==NULL) return;
    print_inorder(root->left);
    cout<<root->data<<" ";
    print_inorder(root->right);
    return;
}

void print_postorder(Node* root){
    if(root==NULL) return;
    print_postorder(root->left);
    print_postorder(root->right);
    cout<<root->data<<" ";
    return;
}

void print_levelorder(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp!=NULL){
            cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        else{
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
        }
    }
    return;
}

Node* build_from_levelorder(){
    int d;
    cin>>d;
    queue<Node*> q;
    Node* n = new Node(d);
    q.push(n);
    while(!q.empty()){
        Node* fr = q.front();
        q.pop();
        int tempcnt = 2;
        while(tempcnt>0){
            int d1;
            cin>>d1;
            if(d1!=-1){
                fr->left = new Node(d1);
                q.push(fr->left);
            }else if(d1==-1){
                fr->left=NULL;
            }
            tempcnt--;
            int d2;
            cin>>d2;
            if(d2!=-1){
                fr->right = new Node(d2);
                q.push(fr->right);
            }else if(d2==-1){
                fr->right = NULL;
            }
            tempcnt--;
        }
    }
    return n;
}

int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftheight = height(root->left);
    int rightheight = height(root->right);
    return max(leftheight,rightheight)+1;
}

class HDPair{
    public:
        int height;
        int diameter;
};

HDPair opt_diameter(Node* root){
    HDPair p;
    if(root==NULL){
        p.height = 0;
        p.diameter = 0;
        return p;
    }
    HDPair left = opt_diameter(root->left);
    HDPair right  = opt_diameter(root->right);
    p.height = max(left.height, right.height)+1;
    int d1 = left.height + right.height;
    int d2 = left.diameter;
    int d3 = right.diameter;

    p.diameter = max(d1,max(d2,d3));
    return p;
}

int main(){

    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);

    Node* root = build_from_levelorder();
    print_pre_order(root);
    // cout<<endl;
    // print_inorder(root);
    // cout<<endl;
    // print_postorder(root);
    cout<<endl;
    cout<<endl;
    print_levelorder(root);
    cout<<endl;
    cout<<height(root)<<endl;

    cout<<opt_diameter(root).diameter<<endl;

    


    return 0;
}