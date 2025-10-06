#include<bits/stdc++.h>
using namespace std;

void solve(){
    string a,b;
    cin>>a>>b;
    vector<int>alpha(26,0);
    for(int i=0;i<b.size();i++){
        alpha[b[i]-65]++;
    }
    int i=a.size()-1,j=b.size()-1;
    while(i>=0 && j>=0){
        if(a[i]==b[j]){
            alpha[b[j]-65]--;
            i--;
            j--;
        }
        else{
            if(alpha[a[i]-65]!=0){
                cout<<"NO\n";return;
            }
            i--;
        }
    }
    if(j==-1){
        cout<<"YES\n";return;
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