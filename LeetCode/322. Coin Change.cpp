#include<bits/stdc++.h>
using namespace std;


void printVectorOfVector(vector<vector<int>>&v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return;
}
int dp(int i,int j,vector<vector<int>>&memo,vector<int>&coins){
    if(j==0){
        return memo[i][j]=0;
    }
    if(i<0){
        return INT_MAX;
    }
    if(coins[i]>j){
        return dp(i-1,j,memo,coins);
    }
    
    if(memo[i][j]==-1){
        int z1=dp(i,j-coins[i],memo,coins);
        int z2=dp(i-1,j,memo,coins);
        if(z1==INT_MAX && z2==INT_MAX){
            return memo[i][j]=INT_MAX;
        }
        if(z2==INT_MAX){
            return memo[i][j]=z1+1;
        }
        if(z1==INT_MAX){
            return memo[i][j]=z2;
        }
        return memo[i][j]=min(z1+1,z2);
    }
    return memo[i][j];
}

int coinChange(vector<int>& coins, int amount) {
    int n=coins.size();
    vector<vector<int>>memo(n,vector<int>(amount+1,-1));
    int z=dp(n-1,amount,memo,coins);
    // printVectorOfVector(memo);
    return ((z==INT_MAX)?-1:z);
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int>coins={1};

    cout<<coinChange(coins,0);


    return 0;
}