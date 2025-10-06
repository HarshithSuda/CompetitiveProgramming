#include<bits/stdc++.h>
using namespace std;


int dp(string s1,string s2,int i,int j,vector<vector<int>>&memo){//TLE BUT ITS RIGHT
    if(i==s1.size()||j==s2.size()){
        return 0;
    }
    if(s1[i]==s2[j]){
        return memo[i][j]=1+dp(s1,s2,i+1,j+1,memo);
    }
    if(memo[i][j]==0){
        memo[i][j]=max(dp(s1,s2,i+1,j,memo),dp(s1,s2,i,j+1,memo));
    }
    
    return memo[i][j];
}
int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>>memo(text1.size(),vector<int>(text2.size(),0));
    return dp(text1,text2,0,0,memo);
}

int longestCommonSubsequenceTabulation(string text1, string text2) {
    vector<vector<int>>memo(text1.size()+1,vector<int>(text2.size()+1,0));
    for(int i=0;i<text1.size();i++){
        for(int j=0;j<text2.size();j++){
            if(text1[i]==text2[j]){
                if(i-1<0 || j-1<0){
                    memo[i][j]=1;
                    continue;
                }
                memo[i][j]=memo[i-1][j-1]+1;
            }
            else{
                if(i-1<0 && j-1<0){
                    memo[i][j]=0;
                    continue;
                }
                if(j-1<0){
                    memo[i][j]=memo[i-1][j];
                    continue;
                }
                if(i-1<0){
                    memo[i][j]=memo[i][j-1];
                    continue;
                }
                memo[i][j]=max(memo[i-1][j],memo[i][j-1]);
            }
        }
    }
    return memo[text1.size()-1][text2.size()-1];
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s1="ABCDGH";
    string s2="AEDFHR";
    cout<<longestCommonSubsequence(s1,s2)<<endl;

    return 0;
}