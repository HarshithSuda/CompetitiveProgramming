#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int>&v){
    for(auto &x:v){
        cout<<x<<" ";
    }
    cout<<"\n";
}

// void printVectorOfVector(vector,im)
int minColorExcluding(vector<vector<int>>&costs,int i,int color){
    if(color==0){
        return min(costs[i][1],costs[i][2]);
    }
    else if(color==1){
        return min(costs[i][0],costs[i][2]);
    }
    return min(costs[i][1],costs[i][0]);
}
int dp(int i,int color,vector<vector<int>>&costs,vector<vector<int>>&memo){
    if(i==0){
        return memo[i][color]=costs[i][color];
    }
    if(memo[i][color]!=INT_MAX){
        return memo[i][color];
    }
    if(color==1){
        memo[i][color]=costs[i][color]+min(dp(i-1,0,costs,memo),dp(i-1,2,costs,memo));
    }
    else if(color==2){
        memo[i][color]=costs[i][color]+min(dp(i-1,1,costs,memo),dp(i-1,0,costs,memo));
    }
    else{
        memo[i][color]=costs[i][color]+min(dp(i-1,1,costs,memo),dp(i-1,2,costs,memo));
    }
    return memo[i][color];
    
}
int minCost(vector<vector<int>>& costs) {
    int n=costs.size();
    vector<vector<int>>memo(n,vector<int>(3,INT_MAX));
    
    int z=min(dp(n-1,0,costs,memo),min(dp(n-1,1,costs,memo),dp(n-1,2,costs,memo)));
    // for(int i=0;i<memo.size();i++){
    //     for(int j=0;j<memo[0].size();j++){
    //         cout<<memo[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return z;
}

int minCostMethod2(vector<vector<int>>&costs){
    int n=costs.size();
    int k=costs[0].size();
    vector<int>curr=costs[costs.size()-1];
    for(int i=costs.size()-2;i>=0;i--){
        vector<int>prev=costs[i];
        // cout<<"prev"<<endl;
        // printVector(prev);
        prev[0]+=min(curr[1],curr[2]);
        prev[1]+=min(curr[0],curr[2]);
        prev[2]+=min(curr[0],curr[1]);
        curr=prev;
        // cout<<"curr"<<endl;
        // printVector(curr);
        // printVector(prev);
    }
    
    // printVector(curr);
    return min(curr[0],min(curr[1],curr[2]));
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>>costs={{17,2,17},{16,16,5},{14,3,19}};
    cout<<minCostMethod2(costs)<<endl;

    return 0;
}