#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long a,b,c;
    cin>>a>>b>>c;
    if(a>b){
        cout<<"First\n";
        return;
    }
    else if(a<b){
        cout<<"Second\n";
        return;
    }
    else{
        if(c%2!=0){
            cout<<"First\n";
            return;
        }
        else{
            cout<<"Second\n";
            return;
        }
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