#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long n,k,x;
    cin>>n>>k>>x;
    long long total_sum=(n*(n+1))/2;
    long long diff_sum=((n-k)*(n-k+1))/2;
    long long k_sum=((k)*(k+1))/2;
    //cout<<"total sum:"<<total_sum<<"diff sum:"<<diff_sum<<endl;
    if((total_sum-diff_sum<x)||(k_sum>x)){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    return;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}