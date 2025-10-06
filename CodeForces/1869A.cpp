#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int x=0;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(n%2==0){
        cout<<2<<endl;
        cout<<1<<" "<<n<<"\n"<<1<<" "<<n<<"\n";
        return;
    }
    else{
        cout<<4<<endl;
        cout<<1<<" "<<n-1<<"\n"<<1<<" "<<n-1<<"\n";
        cout<<n-1<<" "<<n<<"\n"<<n-1<<" "<<n<<"\n";
    }
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