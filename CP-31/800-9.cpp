#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    long long s=0;
    for(int i=0;i<n-1;i++){
        long long t;
        cin>>t;
        s+=t;
    }
    cout<<-s<<endl;
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