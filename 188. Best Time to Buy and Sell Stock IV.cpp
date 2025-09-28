#include<bits/stdc++.h>
using namespace std;

int dp(int i,int k,vector<int>&prices,int buy,vector<vector<vector<int>>>&memo){
    if(i==prices.size() ||k==0){
        return 0;
    }
    if(memo[i][k][buy]!=-1){
        return memo[i][k][buy];
    }
    if(buy==1){ //holding onto a stock
        memo[i][k][buy]=max(prices[i]+dp(i+1,k-1,prices,0,memo),dp(i+1,k,prices,buy,memo));
    }
    else{
        memo[i][k][buy]=max(-prices[i]+dp(i+1,k,prices,1,memo),dp(i+1,k,prices,buy,memo));
    }
    return memo[i][k][buy];
}
int maxProfit(int k, vector<int>& prices) {
    int n=prices.size();
    vector<vector<vector<int>>>memo(n,vector<vector<int>>(k+1,vector<int>(2,-1)));
    for(int i=0;i<memo.size();i++){
        for(int j=0;j<memo[0].size();j++){
            for(int k=0;k<memo[0][0].size();k++){
                cout<<memo[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    cout<<"hello"<<endl;
    int z=dp(0,k,prices,0,memo);
    return z;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    vector<int>prices={3,2,6,5,0,3};
    cout<<maxProfit(2,prices)<<endl;
    

    return 0;
}