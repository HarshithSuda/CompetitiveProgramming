#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int>&v){
    for(auto &x:v){
        cout<<x<<" ";
    }
    cout<<"\n";
}
void printVectorOfVector(vector<vector<int>>&v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }
    return;
}
int dp(int i,int j,vector<vector<int>>&memo,vector<vector<int>>&grid){
    if(i<0||j<0){
        return 10000000;
    }
    if(memo[i][j]!=-1)return memo[i][j];
    memo[i][j]=grid[i][j]+min(dp(i-1,j,memo,grid),dp(i,j-1,memo,grid));
    return memo[i][j];
}

int minPathSum(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>>memo(m,vector<int>(n,-1));
    memo[0][0]=grid[0][0];
    int z=dp(m-1,n-1,memo,grid);
    printVectorOfVector(memo);
    return z;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<int>>grid={{1,3,1},{1,5,1},{4,2,1}};
    cout<<minPathSum(grid)<<endl;
    return 0;
}