#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        cout<<n+1-t<<" ";
    }
    cout<<"\n";
    return;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input1.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}