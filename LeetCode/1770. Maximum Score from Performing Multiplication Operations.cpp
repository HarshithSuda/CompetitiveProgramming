#include<bits/stdc++.h>
using namespace std;

int dp(int i,int left,vector<vector<int>>&memo,vector<int>&nums,vector<int>&multipliers){
    int m=memo.size();
    int n=memo[0].size();
    if(i==m){
        return 0;
    }
    int mult=multipliers[i];
    int right=n-1-(i-left);
    
    if(memo[i][left]==0){
        memo[i][left]=max(mult*nums[left]+dp(i+1,left+1,memo,nums,multipliers),mult*nums[right]+dp(i+1,left,memo,nums,multipliers));
    }
    return memo[i][left];

}
int maximumScore(vector<int>& nums, vector<int>& multipliers) {
    int m=multipliers.size();
    int n=nums.size();
    vector<vector<int>>memo(m,vector<int>(n,0));
    return dp(0,0,memo,nums,multipliers);


}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int>nums={0,0,0,0,0,0};
    vector<int>multipliers={0,0,0,0};
    cout<<maximumScore(nums,multipliers);
    return 0;
}