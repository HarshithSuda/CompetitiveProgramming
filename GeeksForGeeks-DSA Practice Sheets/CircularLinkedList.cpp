#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *next;
    Node(int x){
        data=x;
        next=NULL;
    }
};
//while loop
void printCLLM1(Node *head){
    if(!head){
        return;
    }
    Node *curr=head;
    while(curr->next!=head){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<curr->data<<endl;
    return;

}
//for loop
void printCLLM2(Node *head){
    if(!head){
        return;
    }
    cout<<head->data<<" ";
    for(Node *curr=head->next;curr!=head;curr=curr->next){
        cout<<curr->data<<" ";
    }
    cout<<endl;
    return;
}
//do- while
void printCLLM3(Node *head){
    if(!head){
        return;
    }
    Node *curr=head;
    do{
        cout<<curr->data<<" ";
        curr=curr->next;
    }while(curr!=head);
    cout<<endl;
    return;
}
Node *insertAtBeginNaive(Node *head,int x){
    Node *newnode=new Node(x);
    if(!head){
        newnode->next=newnode;
        return newnode;
    }
    Node *curr=head;
    while(curr->next!=head){
        curr=curr->next;
    }
    curr->next=newnode;
    newnode->next=head;
    return newnode;
}
Node *insertAtBeginEfficient(Node *head,int x){
    Node *newnode=new Node(x);
    if(!head){
        newnode->next=newnode;
        return newnode;
    }
    newnode->next=head->next;
    head->next=newnode;
    swap(head->data,newnode->data);
    return head;
}
Node *insertAtEndEfficient(Node *head,int x){
    Node *newnode=new Node(x);
    if(!head){
        newnode->next=newnode;
        return newnode;
    }
    newnode->next=head->next;
    head->next=newnode;
    swap(head->data,newnode->data);
    return newnode;
}
Node *deleteHead(Node *head){
    if(!head){
        return NULL;
    }
    if(head->next==head){
        return NULL;
    }
    head->data=head->next->data;
    head->next=head->next->next;
    return head;
}
Node *deleteKthNodeCLL(Node *head,int k){
    if(!head){
        return head;
    }
    
    if(k==1){
        head=deleteHead(head);
        return head;
    }
    int count=0; //head is taken as 1
    Node *curr=head;
    while(count<k-2){ //why 
        curr=curr->next;
        count++;
    }
    curr->next=curr->next->next;
    return head;
}
int main(){
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->next=new Node(40);
    head->next->next->next->next=new Node(50);
    head->next->next->next->next->next=new Node(60);
    head->next->next->next->next->next->next=head;
    printCLLM1(head);
    printCLLM2(head);
    printCLLM3(head);
    return 0;
}