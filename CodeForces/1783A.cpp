#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end(),greater<int>());
    if(v[0]!=v[1]){
        cout<<"YES\n";
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
        return;
    }
    else{
        if(v[1]==v[n-1]){
            cout<<"NO\n";
            return;
        }
        else{
            swap(v[1],v[n-1]);
            cout<<"YES\n";
            for(auto x:v){
                cout<<x<<" ";
            }
            cout<<"\n";
            return;
        }
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