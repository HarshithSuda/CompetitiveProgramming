#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k,x;
    cin>>n>>k>>x;
    if(k==1){
        cout<<"NO\n";
        return;
    }
    else if(k==2){
        if(x==2){
            cout<<"YES\n";
            cout<<n<<"\n";
            for(int i=0;i<n;i++){
                cout<<1<<" ";
            }
            cout<<"\n";
            return;
        }
        else{
            if(n%2==0){
                cout<<"YES\n";
                cout<<n/2<<"\n";
                for(int i=0;i<n/2;i++){
                    cout<<2<<" ";
                }
                cout<<"\n";
                return;
            }
            else{
                cout<<"NO\n";
                return;
            }
        }
    }
    else{ //k>=3
        cout<<"YES\n";
        if(x==1){
            if(n%2==0){
                cout<<n/2<<"\n";
                for(int i=0;i<n/2;i++){
                    cout<<2<<" ";
                }
                cout<<"\n";
                return;
            }
            else{
                cout<<1+(n-3)/2<<"\n";
                cout<<3<<" ";
                for(int i=0;i<(n-3)/2;i++){
                    cout<<2<<" ";
                }
                cout<<"\n";
                return;
            }
        }
        else{
            cout<<n<<"\n";
            for(int i=0;i<n;i++){
                cout<<1<<" ";
            }
            cout<<"\n";
            return;
        }
    }
    return;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}