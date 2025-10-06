#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int>&v){
    for(auto &x:v){
        cout<<x<<" ";
    }
    cout<<"\n";
}

int numWays(int n, int k) {
    //Recurrence Relation --> an=(k-1)*(an-1+an-2) 
    //where an-1->adding one color fence to the end 
    //where an-2-->adding two fences of same color to the end 
    //color of fences (diff color compared to the fence)
    if(n>2 && k==1){
        return 0;
    }
    int a=k;
    if(n==1)return a;
    int b=a*k;
    if(n==2)return b;
    
    for(int i=3;i<=n;i++){
        int temp=b;
        b=(k-1)*(temp+a);
        a=temp;
    }
    return b;
}
//top down approach

int dp(int i,int k,vector<int>&memo){

    if(memo[i]!=-1){
        return memo[i];
    }
    memo[i]=(k-1)*(dp(i-1,k,memo)+dp(i-2,k,memo));
    return memo[i];
}
int numWaysMethod2(int n,int k){
    vector<int>memo(n+1,-1);
    memo[1]=k;
    memo[2]=k*k;
    return dp(n,k,memo);
    
}



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cout<<numWaysMethod2(3,3)<<endl;
    return 0;
}