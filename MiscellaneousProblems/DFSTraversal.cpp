#include<bits/stdc++.h>
using namespace std;

void DFSRec(vector<vector<int>>&adj,vector<bool>&visited,int s){
    visited[s]=true; 
    cout<<s<<" "; //printing that node
    for(auto i: adj[s]){ 
        if(!visited[i]){ // if not visited before
            DFSRec(adj,visited,i);
        }
    }
}
void DFSTraversal(vector<vector<int>>&adj){
    vector<bool>visited(adj.size(),false); //creating visited array and filling it with false
    for(int i=0;i<adj.size();i++){
        if(!visited[i]){
            DFSRec(adj,visited,i);
        }
    }
    
}
void addEdge(vector<vector<int>>&adj,int a,int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int V=6;
    vector<vector<int>>adj(V);
    // we have defined the edges in 'edges' but we need to convert it into adj matrix for solving the question
    vector<vector<int>> edges={{1, 2}, {2, 0}, {0, 3}, {4, 5}};  
    for(auto &e:edges){
        addEdge(adj,e[0],e[1]); 
    }
    DFSTraversal(adj);
    return 0;
}