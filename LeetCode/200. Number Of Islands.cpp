#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int>&v){
    for(auto &x:v){
        cout<<x<<" ";
    }
    cout<<"\n";
}

bool isValid(int x,int y,int m,int n){
    return x>=0 && y>=0 && x<m && y<n;
}
void BFS(int i,int j,vector<vector<char>>&grid,set<pair<int,int>>&s){
    queue<pair<int,int>>q;
    q.push({i,j});
    vector<int>X={-1,1,0,0},Y={0,0,1,-1};
    while(!q.empty()){
        pair<int,int>p=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            if(isValid(p.first+X[i],p.second+Y[i],grid.size(),grid[0].size()) && s.find({p.first+X[i],p.second+Y[i]})==s.end() && grid[p.first+X[i]][p.second+Y[i]]=='1'){
                q.push({p.first+X[i],p.second+Y[i]});
                s.insert({p.first+X[i],p.second+Y[i]});
            }
        }
    }
    return;
}
int numIslands(vector<vector<char>>& grid) {
    int count=0;
    set<pair<int,int>>s;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]=='1' && s.find({i,j})==s.end()){
                count++;
                BFS(i,j,grid,s);
            }
        }
    }
    return count;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<char>>grids={{"1","1","0","0","0"},{"1","1","0","0","0"},{"0","0","1","0","0"},{"0","0","0","1","1"}};
    cout<<numIslands(grids)<<endl;
    return 0;
}