#include<bits/stdc++.h>
using namespace std;

void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    if(b-a==c-b){
        cout<<"YES\n";return;
    }
    if((a>b && b<c)){
        if(a==c){
            if(a%c==0){
                cout<<"YES\n";return;
            }
            else{
                cout<<"NO\n";return;
            }
        }
        if(abs(a-c)%b==0){
            cout<<"YES\n";return;
        }
        else{
            cout<<"NO\n";return;
        }
    }
    if((a<b && b>c)){
        if()
    }
    if(a==b){
        if(b<c){
            if(abs(a-c)%b==0){
                cout<<"YES\n";return;
            }
            else{
                cout<<"NO\n";return;
            }
        }
        else{
            if(a%c==0){
                cout<<"YES\n";return;
            }
            else{
                cout<<"NO\n";return;
            }
        }
    }
    if(b==c){
        if(a>b){
            if(abs(a-c)%b==0){
                cout<<"YES\n";return;
            }
            else{
                cout<<"NO\n";return;
            }
        }
        else{
            if(c%a==0){
                cout<<"YES\n";return;
            }
            else{
                cout<<"NO\n";return;
            }
        }
    }
    cout<<"NO\n";return;

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