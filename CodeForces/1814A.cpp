#include<bits/stdc++.h>
using namespace std;

void solve(){
    unsigned long long n,k;
    cin>>n>>k;
    if(k==1||k==n||n%2==0||(n%2==1 && k%2==1 && k!=n-1)){
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
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