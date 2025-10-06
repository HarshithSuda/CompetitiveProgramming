#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int>&v){
    for(auto &x:v){
        cout<<x<<" ";
    }
    cout<<"\n";
}

int dp(int i,int j,vector<vector<int>>&memo){
    if(i<0 || j<0){
        return 0;
    }
    if(memo[i][j]!=-1)return memo[i][j];

    memo[i][j]=dp(i-1,j,memo)+dp(i,j-1,memo);
    return memo[i][j];
}
int uniquePaths(int m, int n) {
    if(m==1||n==1){return 1;}
    vector<vector<int>>memo(m,vector<int>(n,-1));
    memo[0][1]=1,memo[1][0]=1;
    return dp(m-1,n-1,memo);
}



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cout<<uniquePaths(3,2)<<endl;
    return 0;
}