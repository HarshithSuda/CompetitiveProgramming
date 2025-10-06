#include<bits/stdc++.h>
using namespace std;

void convertELtoAL(vector<vector<int>>& edges,vector<vector<int>>&AL){
        for(auto &x:edges){
            AL[x[0]].push_back(x[1]);
            AL[x[1]].push_back(x[0]);
        }
        return;
    }
void DFS(vector<vector<int>>&AL,int source,vector<bool>&visited,bool &loop,int parent){
    visited[source]=true;
    for(auto x: AL[source]){
        if(visited[x]){
            if(x!=parent){
                loop=true;
            return;
            }
        }
        else{
            DFS(AL,x,visited,loop,source);
        }
    }
    return;
}
bool detectCycleAndDisconneted(int n, vector<vector<int>>& edges){
    vector<vector<int>>AL(n);
    convertELtoAL(edges,AL);
    // for(int i=0;i<AL.size();i++){
    //     for(auto x: AL[i]){
    //         cout<<i<<"->"<<x<<"\n";
    //     }
    // }
    cout<<endl;
    vector<bool>visited(n,false);
    bool loop=false;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            DFS(AL,i,visited,loop,-1);
        }
    }
    int i=0;
    // for(auto x:visited){
    //     cout<<"i: "<<i<<" visited: "<<x<<"\n";
    //     i++;
    // }
    // cout<<endl;
    if(loop){
        // cout<<"loop";
        return true;
    }
    for(auto x:visited){
        if(!x){
            // cout<<"all not visited";
            return true;
        }
    }
    return false;
    
}
bool validTree(int n, vector<vector<int>>& edges) {
    if(edges.size()!=(n-1)){
        return false;
    }
    if(detectCycleAndDisconneted(n,edges)){
        return false;
    }
    return true;
}

bool CycleInTreeM2Iterative(int n, vector<vector<int>>& edges){
    //checking for loop directly
    vector<vector<int>>AL(n);
    convertELtoAL(edges,AL);
    stack<int>s;
    map<int,int>m; //node:parent
    s.push(0);
    m.insert({0,-1});
    vector<bool>visited(n,false);
    while(!s.empty()){
        int node=s.top();
        s.pop();
        visited[node]=true;
        for(auto x : AL[node]){
            if(x==m[node]) continue;
            if(visited[x]){
                return false;
            }
            s.push(x);
            m.insert({x,node});
        }
    }
    return true;
}

bool CycleInTreeM3Iterative(int n, vector<vector<int>>& edges){
    //No cycle--> E=V-1 and graph is connected(do dfs once and then all must be visited)
    vector<vector<int>>AL(n);
    convertELtoAL(edges,AL);
    if(edges.size()!=n-1){
        return false;
    }
    stack<int>s;
    int cnt=0;
    vector<bool>visited(n,false);
    s.push(0);
    while(!s.empty()){
        int node=s.top();
        s.pop();
        visited[node]=true;
        for(auto x:AL[node]){
            if(!visited[x]){
                s.push(x);
            }
        }
    }
    for(auto x:visited){
        if(!x){
            return false;
        }
    }
    return true;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    // int t;
    // cin>>t;
    // while(t--){
    //     solve();
    // }
    vector<vector<int>>edges={{1,2},{0,1},{0,2}};
    int n=5;
    cout<<CycleInTreeM3Iterative(4,edges)<<endl;

    return 0;
}