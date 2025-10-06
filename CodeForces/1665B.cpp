#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>v(n);
    unordered_map<int,int>m;
    int maxx_freq=1;
    for(int i=0;i<n;i++){
        cin>>v[i];
        m[v[i]]++;
        maxx_freq=max(maxx_freq,m[v[i]]);
    }
    if(maxx_freq==n){
        cout<<0<<"\n";
        return;
    }
    if(n==2){
        cout<<2<<"\n";return;
    }
    if(n==3){
        if(maxx_freq==1){
            cout<<4<<"\n";return;
        }
        else{
            cout<<2<<"\n";return;
        }
    }
    if(maxx_freq==1){
        // cout<<log10(n-2)/log10(2)<<endl;
        cout<<n+ceil(log10(n-2)/log10(2))<<"\n";return;
    }
    if(maxx_freq>=(n+1)/2){
        cout<<n-maxx_freq+1<<"\n";return;
    }
    cout<<n-maxx_freq+ceil(log10(n-maxx_freq)/log10(maxx_freq))<<"\n";
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