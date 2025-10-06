#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long a,b,n;
    cin>>a>>b>>n;
    long long cnt=b;
    for(long long i=0;i<n;i++){
        long long t;
        cin>>t;
        cnt+=min(t,a-1);
    }
    cout<<cnt<<"\n";
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