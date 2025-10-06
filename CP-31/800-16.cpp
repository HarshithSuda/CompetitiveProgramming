#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    long long diff=INT_MAX;
    vector<long long>arr(n);
    for(int i=0;i<n;i++){
        long long t;
        cin>>t;
        if(i==0){
            arr[i]=t;
            continue;
        }
        arr[i]=t;
        diff=min(diff,arr[i]-arr[i-1]);
    }
    if(diff<0){ //not sorted
        cout<<0<<"\n";
        return;
    }
    else{
        cout<<diff/2+1<<"\n";
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