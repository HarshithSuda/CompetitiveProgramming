#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    cin>>n;
    if(n<4||n%2==1){
        cout<<-1<<"\n";return;
    }
    long long maxx=0,minn=0;
    maxx=n/4;
    
    minn=(n%6)?n/6+1:n/6;
    cout<<minn<<" "<<maxx<<"\n";return;

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