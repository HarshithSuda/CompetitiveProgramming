#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    cin>>n;
    vector<long long>v(n);
    for(long long i=0;i<n;i++){
        cin>>v[i];
    }
    int ans=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            ans=__gcd(v[i],v[j]);
            if(ans==1||ans==2){
                cout<<"Yes\n";
                return;
            }
        }
    }
    cout<<"No\n";
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