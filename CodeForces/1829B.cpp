#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int res=0,c=0;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        if(t==1){
            res=max(res,c);
            c=0;
        }
        else{
            c++;
        }
        
    }
    cout<<max(res,c)<<"\n";
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