#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
void printVector(vector<int>&v){
    for(auto &x:v){
        cout<<x<<" ";
    }
    cout<<"\n";
}


int dp(int i,int k,int target,vector<vector<int>>&memo){
    if(memo[i][target]!=-1){
        return memo[i][target];
    }
    // if(target<0){
    //     return memo[i][target]=0;
    // }
    if(i==0){
        if(target<=k){
            return memo[i][target]=1;
        }
        else{
            return memo[i][target]=0;
        }
    }
    long long z=0;
    for(int j=1;j<=k;j++){
        if(target-j<=0){
            continue;
        }
        z=(z+dp(i-1,k,target-j,memo))%MOD;
    }
    return memo[i][target]=(int)(z);
}
int numRollsToTarget(int n, int k, int target) {
    vector<vector<int>>memo(n,vector<int>(target+1,-1));
    int z=dp(n-1,k,target,memo)%MOD;
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
    // cout<<numRollsToTarget(1,4,3)<<endl;
    // cout<<numRollsToTarget(1,6,6)<<endl;
    cout<<numRollsToTarget(30,30,500)<<endl;
    return 0;
}