#include<bits/stdc++.h>
using namespace std;

int solve(){
    int n,s;
    cin>>n>>s;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(n==1){
        return abs(arr[0]-s);
    }
    if(s<arr[0]){
        return abs(arr[n-1]-s);
    }
    if(s>arr[n-1]){
        return abs(arr[0]-s);
    }
    int left=abs(s-arr[0]);
    int right=abs(s-arr[n-1]);
    int ans=left+right;
    if(left>right){
        return ans+right;
    }
    return ans+left;

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
        cout<<solve()<<endl;
    }

    return 0;
}