#include<bits/stdc++.h>
using namespace std;

void solve(){
    long n;
    cin>>n;
    cout<<1<<" ";
    for(long i = n;i>=2;i--){
        cout<<i<<" ";
    }
    cout<<endl;
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