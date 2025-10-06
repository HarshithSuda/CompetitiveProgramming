#include<bits/stdc++.h>
using namespace std;

void solve(){
    int k,a,b,x,y;
    cin>>k>>a>>b>>x>>y;
    pair<int,int>one,two;
    if(min(x,y)==x){
        one={a,x};
        two={b,y};
    }
    else{
        one={b,y};
        two={a,x};
    }
    int cnt=0;
    if(k>=one.first){
            cnt+=((k-one.first)/one.second)+1;
    }
    k-=cnt*one.second;
    if(k>=two.first){
        cnt+=((k-two.first)/two.second)+1;
    }
    k-=(((k-two.first)/two.second)+1)*two.second;
    cout<<cnt<<"\n";
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