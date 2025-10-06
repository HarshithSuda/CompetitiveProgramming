#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    cin>>n;
    vector<long long>arr(n);
    for(long long i=0;i<n;i++){
        cin>>arr[i];
    }
    if(n==1){
        cout<<1<<endl;
        cout<<arr[0]<<endl;
        return;
    }
    vector<long long>ans;
    ans.push_back(arr[0]);
    for(int i=1;i<arr.size();i++){
        if(arr[i-1]<=arr[i]){
            ans.push_back(arr[i]);
        }
        else{
            ans.push_back(1);
            ans.push_back(arr[i]);
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    return;
}

void solve2(){
    long long n;
    cin>>n;
    vector<long long>arr(n);
    vector<long long>res;
    for(long long i=0;i<n;i++){
        long long x;
        cin>>x;
        if( i && res.back() > x){
            res.push_back(1);
        }
        res.push_back(x);
    }
    cout<<res.size()<<"\n";
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
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
        solve2();
    }

    return 0;
}