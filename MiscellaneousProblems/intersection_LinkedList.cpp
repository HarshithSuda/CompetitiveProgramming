#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next; 
    Node(int d){
        data=d;
        next=NULL;
    }
};
Node *insertNode(Node *head,int data){
    Node *newnode=new Node(data);
    if(head==NULL){
        return newnode;
    }
    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    return head;
}
int intersectionLL(Node *h1,Node *h2){
    if(!h1 || !h2){//if head is NULL, no common point
        return -1;
    }
    for(Node *temp=h1;temp;temp=temp->next){
        Node *curr=h2;
        while(!curr){
            if(curr->data==temp->data){
                return curr->data;
            }
            curr=curr->next;
            temp=temp->next;
        }
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node *head=NULL;
    head=insertNode(head,5);
    head=insertNode(head,8);
    head=insertNode(head,7);
    head=insertNode(head,10);
    head=insertNode(head,12);
    head=insertNode(head,15);
    Node *headTwo=NULL;
    headTwo=insertNode(headTwo,9);
    headTwo->next=head->next->next->next;
    cout<<intersectionLL(head,headTwo)<<endl;
    return 0;
}