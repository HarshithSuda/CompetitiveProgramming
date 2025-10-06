#include<bits/stdc++.h>
using namespace std;
void solve1(){
    long long n;
    cin>>n;
    vector<long long>arr(n);
    for(long long i=0;i<n;i++){
        cin>>arr[i];
    }
    long long diff=arr[1]-arr[0];
    for(long long i=2;i<n;i++){
        if(arr[i]-arr[i-1]!=diff){
            cout<<"NO\n";
            return;
        }
    }
    for(long long i=0;i<n;i++){
        arr[i]+=(diff<0)?diff*(n-i):-diff*(i+1);
    }
    cout<<(arr[0]>=0 && arr[0]%(n+1)==0?"YES":"NO");
    cout<<endl;
    return;
    // if(arr[0]>=0 && arr[0]%(n+1)==0){
    //     cout<<"YES\n";
    //     return;
    // }
    // cout<<"NO\n";
    // return;

}
void solve2(){
    long long n;
    cin>>n;
    vector<long long>arr(n);
    for(long long i=0;i<n;i++){
        cin>>arr[i];
    }
    long long x,y;
    y=(2*arr[0]-arr[1])/(n+1);
    x=y-arr[0]+arr[1];
    if(x<0 || 2*arr[0]-arr[1]<0 || (2*arr[0]-arr[1])%(n+1)!=0){
        cout<<"NO\n";
        return;
    }
    for(long long i=2;i<n;i++){
        if(arr[i]!=(i+1)*x+(n-i)*y){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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
        solve2();
    }

    return 0;
}