#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    cin>>n;
    bool flag=false; //check for zeros
    long long value=INT_MAX;
    for(long long i=0;i<n;i++){
        long long t;
        cin>>t;
        value=min(value,abs(t));
    }
    cout<<value<<"\n";
    return;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}