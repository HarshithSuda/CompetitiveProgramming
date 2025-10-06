#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> DirConvertAdjMatrix(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>graph(n+1,vector<int>(n+1,0));
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u][v]=1;
    }
    return graph;
}
vector<vector<int>> UnDirConvertAdjMatrix(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>graph(n+1,vector<int>(n+1,0));
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u][v]=1;
        graph[v][u]=1;
    }
    return graph;
}
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

void BFS(Node *root){
    if(!root){
        return;
    }
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    int level=0;
    cout<<"Level: "<<level<<endl;
    while(true){
        if(q.front()==NULL){
            q.pop();
            if(q.empty()){
                return;
            }
            level++;
            cout<<endl; 
            cout<<"Level: "<<level<<endl;
            q.push(NULL);
        }
        else{
            Node *curr=q.front();
            cout<<curr->data<<" ";
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
    cin.tie(0);
    Node *root=new Node(5);
    root->left=new Node(10);
    root->right=new Node(20);
    root->left->left=new Node(30);
    root->left->right=new Node (40);
    root->right->left=new Node(50);
    root->right->right=new Node (60);
    root->right->right->right=new Node(70);
    BFS(root);
    // cout<<root->data<<endl;
    // Node *curr=new Node(10);
    // cout<<curr->right->data<<endl;
    cout<<5<<endl;
    cout<<"learning how to debug"<<endl;


    return 0;
}