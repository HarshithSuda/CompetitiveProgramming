#include<bits/stdc++.h>
using namespace std;

int dp(int n,vector<int>&cost,vector<int>&memo){
    if(n==0||n==1){
        return 0;
    }
    if(memo[n]==-1){
        memo[n]=min(dp(n-1,cost,memo)+cost[n-1],dp(n-2,cost,memo)+cost[n-2]);
    }
    return memo[n];
}
int minCostClimbingStairs(vector<int>& cost) {
    int n=cost.size();
    vector<int>memo(n+1,-1);
    return dp(n,cost,memo);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int>cost={1,100,1,1,1,100,1,1,100,1};

    cout<<minCostClimbingStairs(cost)<<endl;
    return 0;
}