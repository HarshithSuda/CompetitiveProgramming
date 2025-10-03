#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int>&v){
    for(auto &x:v){
        cout<<x<<" ";
    }
    cout<<"\n";
}
int dp(int i,int j,vector<vector<int>>&memo,set<pair<int,int>>&s){
    if(i<0||j<0){
        return 0;
    }
    if(s.find({i,j})!=s.end())return memo[i][j]=0;
    if(memo[i][j]!=-1)return memo[i][j];

    memo[i][j]=dp(i-1,j,memo,s)+dp(i,j-1,memo,s);
    return memo[i][j];
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();
    vector<vector<int>>memo(m,vector<int>(n,-1));
    memo[0][0]=1;
    set<pair<int,int>>s; //contains all the obstacles
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(obstacleGrid[i][j]==1){
                s.insert({i,j});
            }
        }
    }
    if(m==1||n==1){
        if(s.empty()){
            return 1;
        }
        else{
            return 0;
        }
    }
    return dp(m-1,n-1,memo,s);
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>>v={{0,1,0,0}};
    cout<<uniquePathsWithObstacles(v)<<endl;
    return 0;
}