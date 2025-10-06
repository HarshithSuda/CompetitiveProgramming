#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *prev;
    Node *next;
    Node(int x){
        data=x;
        prev=next=NULL;
    }
};
Node *DCLL_insertAtEnd(Node *head,int x){
    Node *newnode=new Node(x);
    if(!head){
        newnode->prev=newnode;
        newnode->next=newnode;
        return newnode;
    }
    newnode->prev=head->prev;
    newnode->prev->next=newnode;
    newnode->next=head;
    head->prev=newnode;
    return head; //for inserting at end
}
Node *DCLL_insertAtBegin(Node *head,int x){
    Node *newnode=new Node(x);
    if(!head){
        newnode->prev=newnode;
        newnode->next=newnode;
        return newnode;
    }
    newnode->prev=head->prev;
    newnode->prev->next=newnode;
    newnode->next=head;
    head->prev=newnode;
    return newnode;// sole diff b/w insert at BEGIN and END
}