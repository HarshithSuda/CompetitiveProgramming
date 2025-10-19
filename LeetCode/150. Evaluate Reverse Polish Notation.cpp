#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int>&v){
    for(auto &x:v){
        cout<<x<<" ";
    }
    cout<<"\n";
}

bool isOperand(string &s){
    if(s=="/"||s=="*"||s=="-"||s=="+"){return false;}
    return true;
}
int evaluate(int a,int b,string &s){
    if(s=="+"){
        return a+b;
    }
    else if(s=="-"){
        return a-b;
    }
    else if(s=="*"){
        return a*b;
    }
    return a/b;
}
int evalRPN(vector<string>& tokens) {
    stack<string>st;
    int i=0;
    while(i<tokens.size()){
        // cout<<i<<endl;
        if(isOperand(tokens[i])){
            st.push(tokens[i]);
        }
        else{
            int b=stoi(st.top());
            st.pop();
            int a=stoi(st.top());
            st.pop();
            int ans=evaluate(a,b,tokens[i]);
            st.push(to_string(ans));
        }
        i++;
    }
    // cout<<"here"<<endl;
    return stoi(st.top());
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<string>tokens={"2","1","+","3","*"};
    cout<<evalRPN(tokens)<<endl;

    return 0;
}