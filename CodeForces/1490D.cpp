#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left,*right;
    Node(int k){
        key=k;
        left=right=NULL;
    }
};
// void inorderTraversal(Node *root){
//     if(!root){
//         return;
//     }
//     inorderTraversal(root->left);
//     cout<<root->key<<" ";
//     inorderTraversal(root->right);
// }
// void preorderTraversal(Node *root){
//     if(!root){
//         return;
//     }
//     cout<<root->key<<" ";
//     preorderTraversal(root->left);
//     preorderTraversal(root->right);
// }
Node *constructionOfTree(vector<int>arr,int low,int high){
    if(low<0 ||high>arr.size()-1){
        return NULL;
    }
    if(low>high){
        return NULL;
    }
    Node *root=new Node(arr[low]);
    if(low==high){
        return root;
    }
    int maxx=max_element(arr.begin()+low,arr.begin()+high+1)-arr.begin();
    // cout<<"index refered here is"<<maxx<<endl;
    root=new Node(arr[maxx]);
    root->left=constructionOfTree(arr,low,maxx-1);
    root->right=constructionOfTree(arr,maxx+1,high);
    return root;
}
void returnDistanceFromRoot(Node *root,vector<int>arr,unordered_map<int,int>&m){ //use iterative traversal per level
    //here the vector returns the level of each node which is obtained from hashmap
    queue<Node*>q;
    if(!root){
        return;
    }
    Node *curr=root;
    q.push(curr);
    int level=-1;
    while(!q.empty()){
        int level_each_node=q.size();
        level++;
        for(int i=0;i<level_each_node;i++){
            curr=q.front();
            m[curr->key]=level;
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
            q.pop();
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Node *root=constructionOfTree(arr,0,n-1);
        unordered_map<int,int>m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
         returnDistanceFromRoot(root,arr,m);
        for(int i=0;i<n;i++){
            cout<<m[arr[i]]<<" ";
        }
        cout<<"\n";
    }
    // vector<int>arr={3,5,2,1,4};
    // int n=arr.size();
    // Node *root=constructionOfTree(arr,0,n-1);
    // unordered_map<int,int>m;
    // for(int i=0;i<arr.size();i++){
    //     m[arr[i]]++;
    // }
    // returnDistanceFromRoot(root,arr,m);
    // for(int i=0;i<n;i++){
    //     cout<<m[arr[i]]<<" ";
    // }
    // cout<<"\n";
    // inorderTraversal(root);
    // cout<<endl;
    // preorderTraversal(root);
    return 0;
}