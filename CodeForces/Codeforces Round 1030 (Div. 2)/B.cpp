#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    cout<<2*n-1<<"\n";
    cout<<1<<" "<<1<<" "<<n<<"\n";
    for(int i=1;i<n;i++){
            cout<<i+1<<" "<<1<<" "<<i<<"\n";
            cout<<i+1<<" "<<i+1<<" "<<n<<"\n";
    }
    cout<<"\n";
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