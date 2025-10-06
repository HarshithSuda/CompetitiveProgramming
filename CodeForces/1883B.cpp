#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    if(n==1){
        cout<<"YES\n";
        return;
    }
    unordered_map<char,int>m;
    for(auto x:s){
        m[x]++;
    }
    int count_odd=0;
    for(auto x:m){
        if(x.second%2==1){
            count_odd++;
        }
    }
    if((count_odd-1)>k){
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