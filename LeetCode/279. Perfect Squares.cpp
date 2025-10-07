#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int>&v){
    for(auto &x:v){
        cout<<x<<" ";
    }
    cout<<"\n";
}

int BinarySearch(vector<int>&squares,int n){
    int low=0,high=squares.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(squares[mid]==n){
            return mid;
        }
        else if(squares[mid]>n){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return high;
}
int dp(int i,int amount,vector<vector<int>>&memo,vector<int>&squares){
    if(memo[i][amount]!=INT_MAX){
        return memo[i][amount];
    }
    if(i==1){ //as we definetly have 1 
        memo[i][amount]=amount;
    }
    else if(amount<squares[i]){
        memo[i][amount]=dp(i-1,amount,memo,squares);
    }
    else{
        memo[i][amount]=min(dp(i-1,amount,memo,squares),1+dp(i,amount-squares[i],memo,squares));
    }
    return memo[i][amount];
}
int numSquares(int n){
    vector<int>squares(101);
    for(int i=0;i<=100;i++){
        squares[i]=i*i;
    }
    int index=BinarySearch(squares,n);
    if(squares[index]==n){
        return 1;
    }
    vector<vector<int>>memo(index+1,vector<int>(n+1,INT_MAX));
    return dp(index,n,memo,squares);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cout<<numSquares(25)<<endl;
    return 0;
}