#include<bits/stdc++.h>
using namespace std;
class M1StackUsingQueue{ //M1-making push operation O(n)
    queue<int>q1,q2;
    public:
    void push(int x){
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        queue<int>q=q1;
        q1=q2;
        q2=q;
    }
    int top(){
        if(q1.empty()){
            return -1;
        }
        return q1.front();
    }
    int pop(){
        if(q1.empty()){
            return -1;
        }
        int x=q1.front();
        q1.pop();
        return x;
    }
    int size(){
        return q1.size();
    }
};
class M2StackUsingQueue{ //M2-making pop operation O(n)
    queue<int>q1,q2;
    public:
    void push(int x){
        q1.push(x);
        return;
    }
    int pop(){
        if(q1.empty()){
            return -1;
        }
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        int x=q1.front();
        q1.pop();
        queue<int>q=q1;
        q1=q2;
        q2=q;
        return x;
    }
    int top(){
        if(q1.empty()){
            return -1;
        }
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        int temp=q1.front();
        q2.push(q1.front());
        q1.pop();
        queue<int>q=q1;
        q1=q2;
        q2=q;
        return temp;

    }
    int size(){
        return q1.size();
    }
};
class M3StackUsingQueue{ //using one queue only
    queue<int>q1;
    public:
    void push(int x){
        int s=q1.size();
        q1.push(x);
        for(int i=0;i<s;i++){
            q1.push(q1.front());
            q1.pop();
        }
        return;
    }
    int pop(){
        if(q1.empty()){
            return -1;
        }
        int x=q1.front();
        q1.pop();
        return x;
    }
    int top(){
        if(q1.empty()){
            return -1;
        }
        return q1.front();
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    M3StackUsingQueue s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.top()<<endl;
    s.push(4);
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    
    return 0;
}