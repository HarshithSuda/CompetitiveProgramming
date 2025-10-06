#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    cin>>n;
    unordered_map<long long,long long>m;
    long long s=INT_MIN;
    for(long long i=0;i<n;i++){
        long long t;
        cin>>t;
        m[t]++;
        s=max(s,t);
    }
    if(m.size()==1){
        cout<<-1<<"\n";
        return;
    }
    
    vector<long long>b,c(m[s],s);
    for(auto x:m){
        if(x.first!=s){
            vector<long long>temp(x.second,x.first);
            b.insert(b.end(),temp.begin(),temp.end());
        }
    }
    
    cout<<b.size()<<" "<<c.size()<<"\n";
    for(auto x: b){
        cout<<x<<" ";
    }
    cout<<"\n";
    for(auto x:c){
        cout<<x<<" ";
    }
    cout<<"\n";
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