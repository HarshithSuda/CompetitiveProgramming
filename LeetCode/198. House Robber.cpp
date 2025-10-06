#include<bits/stdc++.h>
using namespace std;

int dp(int n,vector<int>&nums,vector<int>&memo){
    if(n==0){
        return nums[0];
    }
    if(n==1){
        return max(nums[1],nums[0]);
    }
    if(memo[n]==-1){
        memo[n]=max(dp(n-1,nums,memo),dp(n-2,nums,memo)+nums[n]);
    }
    return memo[n];
}
// int robMethod1(vector<int>& nums) {
//     int n=nums.size();
//     return dp(n-1,nums); /
// }


int robMethod2(vector<int>&nums){
    vector<int>memo(nums.size(),-1);
    return dp(nums.size()-1,nums,memo);
}

int robMethod3(vector<int>&nums){
    vector<int>memo(nums.size());
        int n=nums.size();
    if(n==1){
        return nums[0];
    }
    if(n==2){
        return max(nums[0],nums[1]);
    }

    memo[0]=nums[0];
    memo[1]=max(nums[0],nums[1]);
    for(int i=2;i<nums.size();i++){
        // cout<<"here"<<endl;
        memo[i]=max(memo[i-1],memo[i-2]+nums[i]);
    }
    return memo[nums.size()-1];
    
    
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int>nums={2,7,9,3,1};
    cout<<robMethod3(nums)<<endl;

    return 0;
}