#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    if(min(a,c)>=min(b,d)){
        cout<<"Gellyfish\n";
        return;
    }
    else{
        cout<<"Flower\n";
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