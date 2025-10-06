#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int even=0,odd=0;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        if(t%2!=0){
            odd++;
        }
    }
    if(odd%2==0){
        cout<<"YES\n";
        return;
    }
    else{
        cout<<"NO\n";
        return;
    }
    return;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}