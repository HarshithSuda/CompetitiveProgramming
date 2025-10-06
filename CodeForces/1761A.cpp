#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    if(n==a && n==b){
        cout<<"Yes\n";
        return;
    }
    if(a==b){
        if((n-a-b)>=2){
            cout<<"Yes\n";
            return;
        }
    }
    cout<<"No\n";
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