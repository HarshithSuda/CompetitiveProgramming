#include<bits/stdc++.h>
using namespace std;

//PRIM'S ALGORITHM
//ADJACENCY MATRIX IMPLEMENTATIONS
bool PrimComparator(vector<int>&p1,vector<int>&p2){
    return p1[2]<p2[2];
}
void removingRemainingEdges(vector<vector<int>>&p,int vertex){
    vector<vector<int>>temp;
    for(int i=0;i<p.size();i++){
        if(p[i][1]!=vertex){
            temp.push_back({p[i]});
        }
    }
    p=temp;
}
vector<vector<int>> PrimAlgorithm(vector<vector<int>>&mat){ //wont work if disconnected graphs
    unordered_set<int>s;
    int curr=0;
    int n=mat.size();
    vector<vector<int>>MST;
    vector<vector<int>>v;
    s.insert(0);
    for(int i=0;i<n;i++){
        if(mat[curr][i]!=0 && s.find(i)==s.end()){ //if edge exists and the vertex is not present in the MST
            v.push_back({curr,i,mat[curr][i]});
        }
    }
    while(s.size()<n){
        sort(v.begin(),v.end(),PrimComparator);
        curr=v[0][1];
        MST.push_back({v[0]}); //adding MST
        s.insert(curr);
        removingRemainingEdges(v,curr);
        for(int i=0;i<n;i++){
            if(mat[curr][i]!=0 && s.find(i)==s.end()){
                v.push_back({curr,i,mat[curr][i]});
            }
        }        
    }
    return MST;
}
//https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
static bool GFGPrimComparator(vector<int>p1,vector<int>p2){
    return p1[2]<p2[2];
}
void GFGremovingRemainingEdges(vector<vector<int>>&p,int vertex){
    vector<vector<int>>temp;
    for(int i=0;i<p.size();i++){
        if(p[i][1]!=vertex){
            temp.push_back({p[i]});
        }
    }
    p=temp;
}
int GFGPrimAlgorithm(int V,vector<vector<int>>v){ //wont work if disconnected graphs
    unordered_set<int>s;
    sort(v.begin(),v.end(),GFGPrimComparator);
    int curr=0;
    vector<vector<int>>MST;
    s.insert(0);
    GFGremovingRemainingEdges(v,curr);
    while(s.size()<V){
        curr=v[0][1];
        MST.push_back({v[0]}); //adding MST
        s.insert(curr);
        GFGremovingRemainingEdges(v,curr);   
    }
    int count=0;
    for(int i=0;i<MST.size();i++){
        // cout<<MST[i][0]<<" "<<MST[i][1]<<" "<<"weight "<<MST[i][2]<<"\n";
        count+=MST[i][2];
    }
    return count;
}
// Function to find sum of weights of edges of the Minimum Spanning Tree.
int GFGspanningTree(int V, vector<vector<int>> adj[]) {
    vector<vector<int>>temp;
    for(int i=0;i<V;i++){
        for(int j=0;j<adj[i].size();j++){
                // cout<<i<<" "<<adj[i][j][0]<<" "<<"WEIGHT"<<adj[i][j][1]<<" \n";
            temp.push_back({i,adj[i][j][0],adj[i][j][1]});
        }
    }
    // vector<vector<int>>change(temp.begin(),temp.end());
    // for(int i=0;i<change.size();i++){
    //     cout<<change[i][0]<<" "<<change[i][1]<<" "<<change[i][2]<<"\n";
    // }    
    return GFGPrimAlgorithm(V,temp);
}
//GFG ADJACENCY MATRIX REPRESENTATION
int minKeyAmongParent(vector<bool>&MST,vector<int>&key){
    int minkey=INT_MAX,minIndex; //in this case minkey-->weight and minIndex-->vertex
    for(int i=0;i<MST.size();i++){
        if(MST[i]==false && key[i]<minkey){
            minIndex=i;
            minkey=key[i];
        }
    }
    return minIndex;
}
// void GFGAdjMatPrimAlgorithm(vector<vector<int>>&graph){
//     int V=graph[0].size(); //V=no of vertices
//     vector<int>parent(V),key(V,INT_MAX); //index i -->parent(i)=predecssor of i and key(i) -->weight of edge
//     vector<bool>MST(V,false); //MST[i]=true-->vertex already in MST
//     parent[0]=-1;
//     key[0]=0;
//     for(int i=0;i<V-1;i++){ //why V-1 we want only V-1 edges to form a tree 
//     //we ensure that all vertices are covered during the inner for loops(by checking MST[i]==true or not)
//         int u=minKeyAmongParent(MST,key); //the vertex with minimum key(edge weight)
//         MST[u]=true;
//         for(int v=0;v<V;v++){
//             cout<<i<<" u:"<<u<<" v"<<v<<" "<<graph[u][v]<<"\n";
//             if(graph[u][v] && MST[v]==false && graph[u][v]<key[v]){
//                 parent[v]=u;
//                 key[v]=graph[u][v];
//             }
//         }
//     }
//     for(int i=1;i<V;i++){
//         cout<<parent[i]<<" "<<i<<" "<<key[i]<<"\n"; 
//     }
//     return;
// }
//PRIM'AS ALGO (ADJACENY LIST)-->OWN METHOD
struct Comparator{
    vector<int>&Key;
    Comparator(vector<int>&Key) : Key(Key){}
    bool operator()(const pair<int,int>&p1,const pair<int,int>&p2){
    return Key[p1.first]>Key[p2.first];
}
};

vector<vector<int>> PrimAlgorithmAdjList(vector<vector<int>>&Edges,int V){ //Edges-->(0,1,5)-->   0<--5-->1
    vector<vector<pair<int,int>>>E; //creating another data strucutre to store the edges in a neat manner(adv will be shown in the while loop)
    for(int i=0;i<Edges.size();i++){
        int u=Edges[i][0];
        E[u].push_back({Edges[i][1],Edges[i][2]});
        //Edges[i][1]-->v
        //Edges[i][2]-->weight
    }
    vector<int>Key(V,INT_MAX);
    vector<bool>MST(V,false);
    Comparator comp(Key);
    priority_queue<pair<int,int>,vector<pair<int,int>>,Comparator>pq(comp);
    for(int i=0;i<V;i++){
        pq.push({i,-1});
    }
    Key[0]=0;
    while(!pq.empty()){
        pair<int,int>p=pq.top();
        pq.pop();
        int u=p.first; //this is going to be inserted in MST now
        MST[u]=true;
        for(int i=0;i<E[u].size();i++){
            if(!MST[E[u][i].first] && Key[E[u][i].first]<E[u][i].second){
                
            }
        }
    }
    


    
}
//https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
//CONNECTED UNDIRECTED GRAPH
void DFSRecursive(vector<int>*Adj,vector<bool>&Visited,int source,vector<int>&res){
    Visited[source]=true;
    res.push_back(source);
    for(auto x: Adj[source]){
        if(!Visited[x]){
            DFSRecursive(Adj,Visited,x,res);
        }
    }
}
vector<int> DFSMain(vector<vector<int>>&adj){
    int n=adj.size();
    vector<bool>Visited(n,false);
    vector<int> res;
    vector<int> AdjList[n];
    for(int i=0;i<adj.size();i++){
        for(auto x: adj[i]){
            AdjList[i].push_back(x);
            AdjList[x].push_back(i);
        }
    }
    for(int i=0;i<n;i++){
        if(!Visited[i]){
                DFSRecursive(AdjList,Visited,i,res);
        }
    }
    // cout<<endl;
    return res;
}

//994. Rotting Oranges
bool exist(int m,int n,int i,int j){
    if(i<0 || i>m-1 || j<0 || j>n-1){
        return false;
    }
    return true;
}
bool DiagonalRotten(vector<vector<int>>&grid,int i,int j){
    int m=grid.size();
    int n=grid[0].size();
    if((!exist(m,n,i-1,j) ||(exist(m,n,i-1,j) && grid[i-1][j]==0)) && (!exist(m,n,i+1,j) ||(exist(m,n,i+1,j) && grid[i+1][j]==0)) 
    && (!exist(m,n,i,j-1) ||(exist(m,n,i,j-1) && grid[i][j-1]==0)) && (!exist(m,n,i,j+1) ||(exist(m,n,i,j+1) && grid[i][j+1]==0))){
        return true;
    }
    return false;
}

void BFSRotten(vector<vector<int>>&grid,vector<int>coordinates,set<vector<int>>&fresh_set,set<vector<int>>&rotten_set){
    int i=coordinates[0];
    int j=coordinates[1];
    int m=grid.size();
    int n=grid[0].size();
    if((exist(m,n,i-1,j) &&(exist(m,n,i-1,j) && grid[i-1][j]==1))){
        fresh_set.erase({i-1,j});
        rotten_set.insert({i-1,j});
        grid[i-1][j]=2;
    }
    if((exist(m,n,i+1,j) &&(exist(m,n,i+1,j) && grid[i+1][j]==1))){
        fresh_set.erase({i+1,j});
        rotten_set.insert({i+1,j});
        grid[i+1][j]=2;
    }
    if((exist(m,n,i,j-1) && (exist(m,n,i,j-1) && grid[i][j-1]==1))){
        fresh_set.erase({i,j-1});
        rotten_set.insert({i,j-1});
        grid[i][j-1]=2;
    }
    if((exist(m,n,i,j+1) &&(exist(m,n,i,j+1) && grid[i][j+1]==1))){
        fresh_set.erase({i,j+1});
        rotten_set.insert({i,j+1});
        grid[i][j+1]=2;
    }
    return;
}
int RottenMain(vector<vector<int>>&grid){
        set<vector<int>>fresh_set;
        set<vector<int>>rotten_set;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j]==1){
                    if(DiagonalRotten(grid,i,j)){
                        return -1;
                    }
                    fresh_set.insert({i,j});
                }
                if(grid[i][j]==2){
                    rotten_set.insert({i,j});
                }
            }
        }
        
        int count=0;
        if(fresh_set.size()==0){
                return count;
        }
        int z=fresh_set.size();
        while(true){
            set<vector<int>>temp_rotten_set;
            for(auto x: rotten_set){
                // cout<<"x :"<<x[0]<<"y:"<<x[1]<<endl;
                BFSRotten(grid,x,fresh_set,temp_rotten_set);
                // cout<<"freshSet"<<endl;
                // for(auto x:fresh_set){
                //     cout<<x[0]<<" "<<x[1]<<endl;
                // }
                // cout<<"after bfs rotten"<<endl;
                
                // cout<<endl;
            }
            count++;
            rotten_set=temp_rotten_set;
            if(fresh_set.size()==0){
                return count;
            }
            
        }
        return count;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    

    vector<vector<int>> grid = {{0,2}};
    // int count=0;
    // for(int i=0;i<p.size();i++){
    //     cout<<p[i][0]<<" "<<p[i][1]<<"weight is"<<p[i][2]<<"\n";
    //     count+=p[i][2];
    // }
    cout<<RottenMain(grid)<<endl;
    

    return 0;
}