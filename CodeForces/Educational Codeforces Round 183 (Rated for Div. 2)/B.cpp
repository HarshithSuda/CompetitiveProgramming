#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    string ans;
    vector<int>count(3,0);
    for(int i=0;i<s.size();i++){
        if(s[i]-'0'==0){
            count[0]++;
        }
        else if(s[i]-'0'==1){
            count[1]++;
        }
        else{
            count[2]++;
        }
    }
    if(n==k && k==count[2]){
        string s1(n,'-');
        cout<<s1<<"\n";return;
    }
    if(count[0]+count[2]-1>=n-1-(count[1]+count[2]-1)){
        string z(count[0],'-');
        ans+=z;
        // cout<<ans<<endl;
        string y(n-(count[0]+count[1]),'?');
        ans+=y;
        string p(count[1],'-');
        ans+=p;
    }
    else{
        string a(count[0],'-');
        ans+=a;
        string b(count[2],'?');
        ans+=b;
        // cout<<ans<<endl;
        string j(n-(count[0]+count[1]+2*count[2]),'+');
        // string z=(n-(count[0]+count[1]+2*count[2]))*"+";
        ans+=j;
        // cout<<n-(count[0]+count[1]+2*count[2])<<endl;
        // cout<<ans<<endl;
        string l(count[2],'?');
        ans+=l;
        // cout<<ans<<endl;
        string m(count[1],'-');
        ans+=m;
        // cout<<ans<<endl;
    }
    cout<<ans<<"\n";
    return;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}