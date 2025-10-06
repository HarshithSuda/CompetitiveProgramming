#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int>&v){
    for(auto &x:v){
        cout<<x<<" ";
    }
    cout<<"\n";
}

int dp(int i,int j,vector<int>&nums1,vector<int>&nums2,vector<vector<int>>&memo){
        if(i==nums1.size()|| j==nums2.size()){
            return 0;
        }
        if(memo[i][j]!=-1){
            return memo[i][j];
        }
        if(nums1[i]==nums2[j]){
            return memo[i][j]=1+dp(i+1,j+1,nums1,nums2,memo);
        }
        else if(nums1[i]!=nums2[j] && i-1>=0 && j-1>=0 && memo[i-1][j-1]!=0 && memo[i][j]!=-1){
            return memo[i][j]=0;
        }
        memo[i][j]=max(dp(i+1,j,nums1,nums2,memo),dp(i,j+1,nums1,nums2,memo));
        cout<<"here"<<endl;
        return memo[i][j];
}
int findLength(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>>memo(nums1.size(),vector<int>(nums2.size(),-1));
    int z=dp(0,0,nums1,nums2,memo);
    for(int i=0;i<memo.size();i++){
        for(int j=0;j<memo[0].size();j++){
            cout<<memo[i][j]<<" "; 
        }
        cout<<"\n";
    }
    return z;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int>nums1={0,0,0,0,0,0,1,0,0,0},nums2={0,0,0,0,0,0,0,1,0,0};
    cout<<findLength(nums1,nums2)<<"\n";
    return 0;
}