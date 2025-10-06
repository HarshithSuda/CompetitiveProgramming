#include<bits/stdc++.h>
using namespace std;

//TOP-DOWN-MEMOIZATION
unordered_map<int,int>memo;

int dp(int n){//process of filling the memo table
    if(n<=2){
        return n;
    }
    if(memo.find(n)==memo.end()){
        memo[n]=dp(n-1)+dp(n-2);
    }
    return memo[n];
}
int climbStairs(int n) {
    return  dp(n);
}

//METHOD-2
int climbStairs(int n){
    if(n<=2){
        return n;
    }
    vector<int>arr(n+1);
    arr[1]=1;arr[2]=2;
    for(int i=3;i<=n;i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    return arr[n];
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    cout<<climbStairs(10)<<endl;


    return 0;
}