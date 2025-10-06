#include<bits/stdc++.h>
using namespace std;
//Method -1 queue using stack
/* push-O(1)
   pop -O(n)-amortized and only takes O(n) when stack 2 is empty. Rest of the pop operations are O(1).
*/
struct Queue1 {
    stack<int>s1,s2;
    void enQueue(int x){
        s1.push(x);
        return;
    }
    int deQueue(){
        if(s1.empty() && s2.empty()){
            return -1;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            
        }
        int x=s2.top();
            s2.pop();
            return x;
    }
    int peekFront(){
        if(s1.empty() && s2.empty()){
            return -1;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s1.top();
    }
    bool isEmpty(){
        if(s1.empty() && s2.empty()){
            return true;
        }
        return false;
    }
};
//Method -2 queue using stack(wow)
struct Queue2{
    stack<int>s;
    void enQueue(int x){
        s.push(x);
        return;
    }
    int deQueue(){
        if(s.empty()){
            return -1;
        }
        int x=s.top();
        s.pop();
        if(s.empty()){
            return x;
        }
        int item=deQueue();
        s.push(x);
        return item;

    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Queue1 q1;
    q1.enQueue(1);
    q1.enQueue(2);
    q1.enQueue(3);
    cout<<q1.isEmpty()<<endl;
    cout<<q1.deQueue()<<endl;
    cout<<q1.deQueue()<<endl;
    cout<<q1.deQueue()<<endl;
    cout<<q1.deQueue()<<endl;
    return 0;
}