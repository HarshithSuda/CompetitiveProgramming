#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    
    vector<long long>arr(n);
    unordered_map<long long,long long>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        m[arr[i]]++;
    }
    if(n==2 ||m.size()==1){
        cout<<"YES\n";
        return;
    }
    if(m.size()!=2){
        cout<<"NO\n";
        return;
    }
    long long a,b;
    for(auto it=m.begin();it!=m.end();it++){
        if(it==m.begin()){
            a=it->second;
        }
        else{
            b=it->second;
        }
    }
    if((n%2==0 && a-b==0) || n%2==1 && abs(a-b)==1){
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
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