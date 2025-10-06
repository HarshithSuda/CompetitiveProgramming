#include<bits/stdc++.h>
using namespace std;
struct TwoStack{
    int *arr;
    int size;
    int top1,top2;
    TwoStack (int x){
        arr=new int[x];
        size=x;
        top1=-1;
        top2=x;
    }
    void push1(int x){
        if(top1<top2-1){
            top1++;
            arr[top1]=x;
        }
        return;
    }
    void push2(int x){
        if(top1<top2-1){
            top2--;
            arr[top2]=x;
        }
        return;
    }
    int pop1(){
        if(top1>=0){
            int x=arr[top1];
            top1--;
            return x;
        }
        return -1;
    }
    int pop2(){
        if(top2<size){
            int x=arr[top2];
            top2++;
            return x;
        }
        return -1;
    }
    int peek1(){
        if(top1>=0){
            return arr[top1];
        }
        return -1;
    }
    int peek2(){
        if(top2<size){
            return arr[top2];
        }
        return -1;
    }
    bool isEmpty(){
        if(top1>=0 || top2<size){
            return false;
        }
        return true;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    TwoStack *s= new TwoStack(6);
    s->push1(1);
    s->push1(2);
    s->push1(3);
    s->push2(-1);
    s->push2(-2);
    s->push2(-3);
    cout<<s->pop1()<<endl;
    cout<<s->pop1()<<endl;
    cout<<s->pop2()<<endl;
    cout<<s->pop2()<<endl;
    cout<<s->pop1()<<endl;
    cout<<s->isEmpty()<<endl;
    return 0;

}