#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next=NULL;
    Node (int d)
    {
        data=d;
        next=NULL;
    }
};
Node *insert(Node *head,int data,int pos)
{
    Node *newnode=new Node(data);
    if(head==NULL)
    {
        return newnode;
    }
    if(pos==1)
    {
       newnode->next=head;
       return newnode;
    }
    Node *curr=head;
    int count=0;
    while(curr!=NULL&& count<pos-1)
    {
        count++;
        curr=curr->next;
    }
    if(count<pos-1)
    {
        return head;
    }
    newnode->next=curr->next;
    curr->next=newnode;
    return head;
    
}
void print(Node *head)
{
    Node *curr=head;
    while(curr!=NULL)
    {
        cout<<curr->data<<"->";
        curr=curr->next;
    }
    cout<<"NULL"<<endl;
    return;
}
Node *remdup(Node *head)
{
    if(head==NULL ||head->next==NULL)
    {
        return head;
    }
    Node*curr=head;
    while(curr!=NULL && curr->next!=NULL)
    {
        if(curr->data==curr->next->data)
        {
            Node *temp=curr->next;
            curr->next=temp->next;
            delete(temp); //deleting the copy node
        }
        else
        {
            curr=curr->next;
        }
    }
    return head;
}
int main()
{
    
    Node *head= new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(20);
    head->next->next->next=new Node(30);
    head->next->next->next->next=new Node(30);
    head->next->next->next->next->next=new Node(30);
    head->next->next->next->next->next->next=new Node(30);
    print(head);
    head=remdup(head);
    print(head);
    return 0;
    
}