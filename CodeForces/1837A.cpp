#include<bits/stdc++.h>
using namespace std;

void solve(){
    int x,k;
    cin>>x>>k;
    if(x<k || x%k!=0){
        cout<<1<<"\n";
        cout<<x<<"\n";
        return;
    }
    else{
        cout<<2<<"\n";
        cout<<x-1<<" "<<1<<"\n";
        return;
    }
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