#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int>&v){
    for(auto &x:v){
        cout<<x<<" ";
    }
    cout<<"\n";
}

bool completeParanthesis(string s){
    stack<char>st;
    int i=0;
    while(i<s.size()){
        if(s[i]=='{'||s[i]=='['||s[i]=='('){
            st.push(s[i]);
        }
        else if((s[i]=='}' && (st.empty() || st.top()!='{'))||(s[i]==']' && (st.empty() || st.top()!='['))
        ||(s[i]==')' && (st.empty() || st.top()!='('))){
            return false;
        }
        else{
            st.pop();
        }
        i++;
    }
    return st.empty();
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s="{}(";
    cout<<completeParanthesis(s)<<endl;

    return 0;
}