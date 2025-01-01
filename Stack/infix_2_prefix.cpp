#include<iostream>
#include<stack>
#include<string>
using namespace std ;

int check(char c){
        if(c=='^')
            return 3;
        else if(c=='*' or c=='/')
            return 2;
        else if(c=='+' or c=='-')
            return 1;
        else
            return -1;
}

string infixToPrefix(string& s) {
        // Your code here
        reverse(s.begin(),s.end());
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
                s[i]=')';
            else if(s[i]==')')
                s[i]='(';
        }
        string ans;
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if((s[i]>='A' and s[i]<='Z') or (s[i]>='a' and s[i]<='z') or (s[i]>='0' and s[i]<='9')){
                ans+= s[i];
            }
            else if(s[i]=='('){
                st.push(s[i]);
            }else if(s[i]==')'){
                while(!st.empty() and st.top()!='(' ){
                    ans+= st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                int priority = check(s[i]);
                while (!st.empty() && 
                       ((priority < check(st.top())))){
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            ans+= st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
}

int main(){

    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);

    string input ="(A-B/C)*(A/K-L)";
    
    cout<<infixToPrefix(input)<<endl;

    return 0;
}