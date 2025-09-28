#include<bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n=nums.size();
    int maxx=1;
    vector<int>dp(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
                dp[i]=max(1+dp[j],dp[i]);
                maxx=max(dp[i],maxx);
            }
        }
    }
    return maxx;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int>nums={0,1,0,3,2,3};
    cout<<lengthOfLIS(nums)<<endl;

    return 0;
}