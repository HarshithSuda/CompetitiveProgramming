#include<bits/stdc++.h>
using namespace std;


int dp(int i,int k,int d,vector<int>&jobDifficulty,vector<vector<int>>&memo,vector<int>&maxxVector){
    if(k==d-1){
        // cout<<"i"<<i<<"k"<<k<<endl;
        // memo[i][k]=*max_element(jobDifficulty.begin()+i,jobDifficulty.end());
        // cout<<maxxVector[i]<<endl;
        return memo[i][k]=maxxVector[i];
    }
    if(memo[i][k]==0){
        int hardest=INT_MIN;
        int z=INT_MAX   ;

        for(int j=i;j<(jobDifficulty.size()-((d-1)-k));j++){
            // cout<<"j: "<<j<<endl;
            hardest=max(hardest,jobDifficulty[j]);
            z=min(z,hardest+dp(j+1,k+1,d,jobDifficulty,memo,maxxVector));
            if(z==maxxVector[0]+maxxVector[jobDifficulty.size()-1]){
                // cout<<maxxVector[0]<<endl;
                memo[i][k]=z;
                return memo[i][k];
            }
            
        }
        memo[i][k]=z;
    }
    return memo[i][k];  
}
int minDifficulty(vector<int>& jobDifficulty, int d) {
    if(jobDifficulty.size()<d){
        return -1;
    }
    int n=jobDifficulty.size();
    vector<int>maxxVector(n);
    maxxVector[n-1]=jobDifficulty[n-1];
    for(int i=n-2;i>=0;i--){
        maxxVector[i]=max(maxxVector[i+1],jobDifficulty[i]);
    }
    vector<vector<int>>memo(n,vector<int>(d,0));
    return dp(0,0,d,jobDifficulty,memo,maxxVector);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int>nums={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int d=10;
    cout<<minDifficulty(nums,d)<<endl;


    return 0;
}