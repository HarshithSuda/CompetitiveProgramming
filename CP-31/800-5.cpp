#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    
    int arr[n];
    //i==0 value
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        arr[i]=t;
    }

    if(arr[0]!=1){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
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