#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>v(n);
    int ans=0,index=-1;
    int cnt=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(v[i]==0){
            if(i-index!=1){
                ans++;
            }
            cnt++;
            index=i;
        }
    }
    if(cnt==n){
        cout<<0<<endl;
        return;
    }
    ans=(v[n-1])?ans+1:ans;
    if(ans>1){
        cout<<2<<endl;
        return;
    }
    cout<<1<<endl;
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