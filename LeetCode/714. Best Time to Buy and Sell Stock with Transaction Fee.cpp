#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int>&v){
    for(auto &x:v){
        cout<<x<<" ";
    }
    cout<<"\n";
}

int dp(int i,int fee,int holding,vector<int>&prices,vector<vector<int>>&boolMemo){
    // cout<<holding<<endl;
    if(i==prices.size())return 0;
    if(boolMemo[holding][i]!=-1)return boolMemo[holding][i];
    if(holding){
        // cout<<"here1";
        // int z=
        boolMemo[holding][i]=max(prices[i]-fee+dp(i+1,fee,0,prices,boolMemo),dp(i+1,fee,1,prices,boolMemo));
    }
    else{
        // cout<<"here2";
        boolMemo[holding][i]=max(-prices[i]+dp(i+1,fee,1,prices,boolMemo),dp(i+1,fee,0,prices,boolMemo));
    }
    return boolMemo[holding][i];
}
int maxProfit(vector<int>& prices, int fee) {
    // vector<int>memo(prices.size(),-1);
    vector<vector<int>>boolMemo(2,vector<int>(prices.size(),-1));
    int z=dp(0,fee,0,prices,boolMemo);

    int y=dp(0,fee,1,prices,boolMemo);
    // printVector(boolMemo[0]);
    // printVector(boolMemo[1]);
    return z;
        
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int>prices={1,3,2,8,4,9};
    cout<<maxProfit(prices,2)<<endl;
    // cout
    return 0;
}