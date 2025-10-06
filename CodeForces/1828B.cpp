#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    int ans;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(i==0){
            ans=abs(arr[i]-1-i);
        }
        else{
            ans=__gcd(ans,abs(arr[i]-1-i));
        }
    }
    cout<<ans<<"\n";
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