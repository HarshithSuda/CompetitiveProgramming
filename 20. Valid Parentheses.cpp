#include<bits/stdc++.h>
using namespace std;
bool isOpening(char c){
    if(c=='{'|| c=='['||c=='('){
        return true;
    }
    return false;
}
bool balancedParanthesis(string s){
    stack<char>st;
    for(auto x:s){
        if(st.empty() && !isOpening(x)){
            return false;
        }
        if(isOpening(x)){
            st.push(x);
            continue;
        }
        else{
            if(st.top()=='[' && x==']'){
                st.pop();
                continue;
            }
            if(st.top()=='{' && x=='}'){
                st.pop();
                continue;
            }
            if(st.top()=='(' && x==')'){
                st.pop();
                continue;
            }
            else{
                return false;
            }
        }
    }
    if(!st.empty()){
        return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    if(balancedParanthesis(s)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
    
}