#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int i=0,j=(n)/2,ans=n;
    while( i<n/2 &&j<n){
        if(v[j]-2*v[i]>=0){
            ans--;
            // cout<<"here"<<endl;
            i++;
            // j++;
        }
        j++;
    }
    cout<<ans<<endl;
    return;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    // int t;
    // cin>>t;
    // while(t--){
    //     solve();
    // }
    // vector<int>arr={3 99 24 46 75 63 57 55 10 62 34 52};5
    solve();

    return 0;
}