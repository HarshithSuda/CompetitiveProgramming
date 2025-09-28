#include<bits/stdc++.h>
using namespace std;

int dp(int n,vector<int>&nums,vector<int>&points,unordered_map<int,int>&memo){
    if(n==0){
        return 0;
    }
    if(n==1){
        return points[1];
    }
    if(memo.find(n)==memo.end()){
        memo[n]=max(dp(n-1,nums,points,memo),dp(n-2,nums,points,memo)+points[n]);
    }
    return memo[n];
    
}
int deleteAndEarn(vector<int>& nums) {
    int maxx=*max_element(nums.begin(),nums.end());
    vector<int>points;
    for(auto &x:nums){
        points[x]+=x;
    }
    unordered_map<int,int>memo;
    return dp(maxx,nums,points,memo);
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);



    return 0;
}