#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,ones=0,twos=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        if(t%2==0){
            twos++;
        }
        else{
            ones++;
        }
    }
    if((twos%2==0 && ones%2==0) || (twos%2==1 && ones%2==0 && ones!=0)){
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
    return;


}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input1.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}