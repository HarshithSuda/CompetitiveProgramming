#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    bool flag=false;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(v[i]==k){
            flag=true;
        }
    }
    if(flag){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    return;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}