#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,x,first=-1,last=-1;
    cin>>n>>x;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(v[i]==1){
            if(first==-1){
                first=i;
            }
            else{
                last=i;
            }
        }
    }
    if(x>=n || first==-1 || last==-1){
        cout<<"YES\n";
        return;
    }
    if((last-first+1)>x){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
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