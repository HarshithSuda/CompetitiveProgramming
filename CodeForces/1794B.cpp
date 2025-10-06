#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int i=0;
    while(i<n-1){
        if(v[i]==1){
            v[i]++;
            if(i!=0 && v[i]%v[i-1]==0){
                v[i]++;
            }
            continue;
        }
        if(v[i+1]%v[i]!=0){
            i++;
            continue;
        }
        if(v[i+1]%v[i]==0){
            v[i+1]++;
            if(i!=0 && v[i]%v[i-1]==0){
                v[i]++;
            }
            continue;
        }
    }
    for(auto x : v){
        cout<<x<<" ";
    }
    cout<<"\n";
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