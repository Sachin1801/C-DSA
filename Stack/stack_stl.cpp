#include<iostream>
#include<stack>
#include<string>
using namespace std ;

void insert_at_botton(stack<string> &s, string str){
    if(s.empty()){
        s.push(str);
        return;
    }
    string temp = s.top();
    s.pop();
    insert_at_botton(s,str);
    s.push(temp);
    return;
}

void reverse_stack(stack<string> &s){
    if(s.size()==1){
        return;
    }
    string temp = s.top();
    s.pop();
    reverse_stack(s);
    insert_at_botton(s,temp);
    return;
}

int main(){

    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    
    stack<string> books;

    books.push("C++");
    books.push("Java");
    books.push("OS");
    books.push("Python");

    insert_at_botton(books, "Software Engineering");
    reverse_stack(books);

    while(!books.empty()){
        cout<<books.top()<<", ";
        books.pop();
    }


    return 0;
}