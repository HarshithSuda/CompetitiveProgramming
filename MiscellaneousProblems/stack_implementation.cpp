#include <bits/stdc++.h>
using namespace std;
struct Stack
{
    int top;
    int CAP;
    int *arr;
    Stack(int d)
    {
        top = -1;
        CAP = d;
        arr = new int[CAP];
    }
    bool isFull()
    {
        return (top == CAP - 1);
    }
    bool isEmpty()
    {
        return (top == -1);
    }
    void push(int data)
    {
        if (isFull())
        {
            return;
        }
        arr[++top] = data;
        return;
    }
    int pop()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[top--];
    }
    int size()
    {
        return top + 1;
    }
    int peek()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[top];
    }
};

int main()
{
    Stack s(10);
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.size()<<endl;
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;

}