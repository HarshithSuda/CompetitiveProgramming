#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>v(n);
    int maxx=INT_MIN,minn=INT_MAX;
    for(int i=0;i<n;i++){
        cin>>v[i];
        maxx=max(v[i],maxx);
        minn=min(v[i],minn);
    }
    if(v[0]==minn || v[n-1]==maxx){
        cout<<maxx-minn<<"\n";
        return;
    }
    int ans=max(maxx-v[0],v[n-1]-minn);
    for(int i=0;i<n;i++){
        if(v[i]==maxx){
            ans=max(ans,v[i]-v[i+1]);
        }
        if(v[i]==minn){
            ans=max(ans,v[i-1]-v[i]);
        }
    }
    cout<<ans<<"\n";
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