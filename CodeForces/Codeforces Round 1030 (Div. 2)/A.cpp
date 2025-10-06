#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    if(n==k||k==0){
        for(int i=0;i<n;i++){
            cout<<((k)?"1":"0");
        }
        cout<<"\n";
        return;
    }
    arr[0]=1;
    arr[n-1]=0;
    k--;
    int j=n-2;
    while(k--){
        arr[j]=1;
        j--;
    }
    for(int i=1;i<=j;i++){
        arr[i]=0;
    }
    string s="";
    for(auto x:arr){    
        s+='0'+x;
    }
    cout<<s;
    cout<<"\n";
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