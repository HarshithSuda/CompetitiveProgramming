#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node (int d){
        data=d;
        next=NULL;
    }
};
struct DoubleNode{
    int data;
    DoubleNode *prev;
    DoubleNode *next;
    DoubleNode(int d){
        data=d;
        prev=next=NULL;
    }
};
Node *reverseListRecursion(Node *head){
    if(!head || !(head->next)){
            return head;
        }
        Node *revHead=reverseListRecursion(head->next);
        head->next->next=head;
        head->next=NULL;
        return revHead;
}
Node *reverseListIterative(Node *head){
    if(!head ||!(head->next)){
        return head;
    }
    Node *curr=head,*prev=NULL,*next=NULL;
    while(curr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
bool detectCycle(Node *head){
    if(!head){
        return false;
    }
    if(head->next==head){
        return true;
    }
    Node *slow=head;
    Node *fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            break;
        }
    }
    if(!fast ||!(fast->next)){
        return false;
    }
    return true;
}
Node *HeadOfCycle(Node *head){
    if(!head ||((head->next)==head)){
        return head;
    }
    Node *slow=head,*fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            break;
        }
    }
    if(!fast || !(fast->next)){
        return NULL;
    }
    slow=head;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}
int lengthOfCycle(Node *head){
    if(!head){
        return 0;
    }
    if(head->next==head){
        return 1;
    }
    Node *slow=head,*fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            break;
        }
    }
    if(!fast || !(fast->next)){
        return 0;
    }
    int count=1;
    fast=fast->next;
    while(fast!=slow){
        fast=fast->next;
        count++;
    }
    return count;
}
bool isPalindromeUsingStack(Node *head){
    if(!head){
        return false;
    }
    if(!head->next){
        return true;
    }
    Node *curr=head;
    stack<int>s;
    while(curr){
        s.push(curr->data);
        curr=curr->next;
    }
    curr=head;
    while(curr){
        if(s.top()!=curr->data){
            return false;
        }
        s.pop();
        curr=curr->next;
    }
    return true;
}
bool isPalindromeUsingReverse(Node *head){
    if(!head){
        return false;
    }
    if(!(head->next)){
        return true;
    }
    Node *slow=head,*fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    slow=reverseListIterative(slow);
    Node *curr=head;
    while(slow){
        if(slow->data!=curr->data){
            return false;
        }
        slow=slow->next;
        curr=curr->next;
    }
    return true;
}
Node* oddEvenList(Node* head) {
    if(!head ||!(head->next)){
        return head;
    }
    Node *oddHead=head,*evenHead=head->next,*odd=head,*even=head->next;
    while(odd->next && even->next){
        odd->next=odd->next->next;
        odd=odd->next;
        if(even){
            even->next=odd->next;
            even=even->next;
        }
        
    }
    odd->next=evenHead;
    return oddHead;
    
}
Node* deleteMiddle(Node* head) {
    if(!head ||(!head->next)){
        return NULL;
    }
    Node* slow=head,*fast=head;
    while(1){
        fast=fast->next->next;
        if(!fast || !(fast->next)){
            break;
        }
        slow=slow->next;
    }
    slow->next=slow->next->next;
    return head;
}
Node* removeNthFromEnd(Node* head, int n) {
    if(!head){
        return NULL;
    }
    if(!head->next && n==1){
        return NULL;
    }
    Node *ptr1=head,*ptr2=head;
    int count=0;
    while(ptr1 && count!=n){
        ptr1=ptr1->next;
        count++;
    }
    if(!ptr1 && count==n){
        return head->next;
    }
    while(ptr1 && ptr1->next){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    ptr2->next=ptr2->next->next;
    return head;
}
//add one to values in linked list(gfg problem)
Node* addOneWithoutReversal(Node *head){
    if(!head){
        head=new Node(1);
        return head;
    }
    if(head->data==9){
        head->data=0;
        head->next=addOneWithoutReversal(head->next);
        return head;
    }
    else{
        head->data++;
        return head;
    }
}
Node* addOne(Node* head) {
    head=reverseListIterative(head);
    head=addOneWithoutReversal(head);
    head=reverseListIterative(head);
    return head;
    
}
//Delete all occurrences of a given key in a doubly linked lis
void deleteAllOccurOfX(struct DoubleNode** head, int x) {
    if(!(*head)){
        return;
    }
    DoubleNode *curr=*head;
    if((*head)->data==x){
        while(curr->data==x){
            curr=curr->next;
            
        }
        *head=curr;
        (*head)->prev=NULL;
    }
    DoubleNode *temp=(*head)->next;
    while(temp){
        if(temp->data==x){
            DoubleNode *next=temp->next;
            temp->prev->next=temp->next;
            if(!(temp->next)){
                return;
            }
            temp->next->prev=temp->prev;
            temp=next;
        }
        else{
            temp=temp->next;
        }
    }
    return;
}
//Remove duplicates from a sorted doubly linked list
DoubleNode* removeDuplicates(DoubleNode *head){
    if(!head ||!(head->next)){
        return head;
    }
    DoubleNode *curr=head;
    DoubleNode *temp=head->next;
    while(temp){
        if(curr->data==temp->data){
            curr->next=temp->next;
            temp=temp->next;
            if(!temp){
                return head;
            }
            temp->prev=curr;
        }
        else{
            curr=temp;
            temp=temp->next;
        }
    }
    return head;
}
//Merge sort in LinkedList
Node *split(Node *head){
    Node *slow=head,*fast=head;
    while(fast && fast->next){
        fast=fast->next->next;
        if(fast){
            slow=slow->next;
        }
    }
    Node *temp=slow->next;
    slow->next=NULL;
    return temp;
}
Node *merge(Node *first,Node *second){
    if(!first){
        return second;
    }
    if(!second){
        return first;
    }
    if(first->data<second->data){
        first->next=merge(first->next,second);
        return first;
    }
    else{
        second->next=merge(first,second->next);
        return second;
    }
}
Node *MergeSort(Node *head){
    if(!head ||!(head->next)){
        return head;
    }
    Node *second=split(head);
    head=MergeSort(head);
    second=MergeSort(second);
    head=merge(head,second);
    return head;
}
//merge sort done

//Intersection of Two Nodes
Node *getIntersectionNode(Node *headA, Node *headB) {
    Node *curr1=headA,*curr2=headB;
    int len1=0,len2=0;
    while(curr1){
        curr1=curr1->next;
        len1++;
    }
    while(curr2){
        curr2=curr2->next;
        len2++;
    }
    curr1=headA;
    curr2=headB;
    int d=abs(len1-len2);
    if((len1-len2)>0){
        while(d--){
            curr1=curr1->next;
        }
    }
    else{
        while(d--){
            curr2=curr2->next;
        }
    }
    while(curr1 && curr2){
        if(curr1==curr2){
            return curr1;
        }
        curr1=curr1->next;
        curr2=curr2->next;
    }
    return NULL;
}
//Sort a linked list of 0s, 1s and 2s
Node* segregate(Node* head) {
    Node *curr=head;
    Node *zerohead=NULL,*zerotail=NULL,*onehead=NULL,*onetail=NULL,*twohead=NULL,*twotail=NULL;
    while(curr){
        if(curr->data==2){
            if(!twohead){
                twohead=twotail=curr;
            }
            else{
                twotail->next=curr;
                twotail=twotail->next;
            }
        }
        else if(curr->data==1){
                if(!onehead){
                onehead=onetail=curr;
            }
            else{
                onetail->next=curr;
                onetail=onetail->next;
            }
        }
        else{
            if(!zerohead){
                zerohead=zerotail=curr;
            }
            else{
                zerotail->next=curr;
                zerotail=zerotail->next;
            }
        }
        curr=curr->next;
    }
    if(!zerotail){
        if(!onetail){
            if(twotail){
                twotail->next=NULL;
            }
            return twohead;
        }
        else{
            onetail->next=twohead;
            if(twotail){
                twotail->next=NULL;
                
            }
            return onehead;
        }
    }
    else{
        if(!onetail){
            if(twotail){
                zerotail->next=twohead;
                twotail->next=NULL;
            }
            else{
                zerotail->next=NULL;
            }
        }
        else{
            zerotail->next=onehead;
            if(twotail){
                onetail->next=twohead;
                twotail->next=NULL;
            }
            else{
                onetail->next=NULL;
            }
        }
    }
    return zerohead;
}
//Rotate List
Node* rotateRight(Node* head, int k) {
    if(!head){
        return head;
    }
    int count=1;
    Node *tail=head;
    
    while(tail->next){
        tail=tail->next;
        count++;
    }
    k=k%count;
    if(k==0){
        return head;
    }
    Node *curr1=head,*curr2=head;
    while(k--){
        curr1=curr1->next;
    }
    while(curr1->next){
        curr1=curr1->next;
        curr2=curr2->next;
    }
    Node *newhead=curr2->next;
    curr2->next=NULL;
    tail->next=head;
    return newhead;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

