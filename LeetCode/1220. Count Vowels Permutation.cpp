#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007;
void printVector(vector<int>&v){
    for(auto &x:v){
        cout<<x<<" ";
    }
    cout<<"\n";
}

int dp(int length,int i,vector<vector<int>>&memo){
    if(length==1){return memo[i][length]=1;}
    if(memo[i][length]!=0){return memo[i][length];}
    if(i==0){
        memo[i][length]=(dp(length-1,1,memo)+dp(length-1,1,memo)+dp(length-1,1,memo))%MOD;
    }
    if(i==1){
        memo[i][length]=(dp(length-1,0,memo)+dp(length-1,2,memo))%MOD;
    }
    if(i==2){
        memo[i][length]=(dp(length-1,1,memo)+dp(length-1,3,memo))%MOD;
    }
    if(i==3){
        memo[i][length]=dp(length-1,2,memo)%MOD;
    }
    if(i==4){
        memo[i][length]=(dp(length-1,2,memo)+dp(length-1,3,memo))%MOD;
    }
    return memo[i][length];
}
int countVowelPermutation(int n) {
    vector<vector<int>>memo(5,vector<int>(n+1,0));
    int z=0;
    for(int i=0;i<5;i++){
        z+=dp(n-1,i,memo)%MOD;
    }
    return z;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cout<<countVowelPermutation(2)<<endl;
    return 0;
}