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
int dp(int i,int j,vector<int>&prices,vector<vector<int>>&memo){
    //cout<<"i:"<<i<<"j:"<<j<<endl;
    if(memo[j][i]!=-1){
        return memo[j][i];
    }
    if(j==0 && i<prices[j]){
        memo[j][i] = INT_MAX;
    }
    else if(i<prices[j]){
        memo[j][i] = dp(i,j-1,prices,memo);
    }
    else if(i==prices[j]){
        int z=INT_MAX;
        if(j!=0){
            z=dp(i,j-1,prices,memo);
        }
        memo[j][i]=((z==INT_MAX)?1:z+1);
    }
    else{
        int x=dp(i-prices[j],j,prices,memo);
        int y=INT_MAX;
        if(j!=0){
            y=dp(i,j-1,prices,memo);
        }
        if(x==INT_MAX && y==INT_MAX){
            memo[j][i] = INT_MAX;
        }
        else if(x==INT_MAX){
            memo[j][i] = y;
        }
        else if(y==INT_MAX){
            memo[j][i] = x;
        }
        else{
            memo[j][i] = x+y;
        }
    }
    // printVectorOfVector(memo);
    return memo[j][i];
}

int change(int amount, vector<int>& coins) {
    vector<vector<int>>memo(coins.size(),vector<int>(amount+1,-1));
    // printVectorOfVector(memo);
    for(int i=0;i<coins.size();i++){
        memo[i][0]=0;
    }
    int z=dp(amount,coins.size()-1,coins,memo);
    return ((z==INT_MAX)?0:z);
    
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int amount=3;
    vector<int>coins={2};
    cout<<change(amount,coins)<<endl;
    return 0;
}