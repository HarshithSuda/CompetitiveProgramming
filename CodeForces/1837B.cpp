#include<bits/stdc++.h>
using namespace std;

int solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int consecutive=1,ans=0;
    for(int i=1;i<n;i++){
        if(s[i]!=s[i-1]){
            ans=max(ans,consecutive);
            consecutive=1;
        }
        else{
            consecutive++;
        }
    }
    ans=max(ans,consecutive);
    return ans+1;
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
        cout<<solve()<<"\n";
    }

    return 0;
}