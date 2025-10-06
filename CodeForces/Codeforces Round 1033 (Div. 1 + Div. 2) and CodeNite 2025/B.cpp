#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,s;
    cin>>n>>s;
    int cnt=0;
    for(int i=0;i<n;i++){
        int x,y,a,b;
        cin>>x>>y>>a>>b;
        if(a+b==s ){
            cnt++;
        }
    }
    cout<<cnt<<endl;
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