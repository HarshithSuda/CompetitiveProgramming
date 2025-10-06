#include<bits/stdc++.h>
using namespace std;

int solve(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int cnt=1,res=1;
    for(int i=1;i<n;i++){
        // cout<<arr[i]<<" count:"<<cnt<<endl;
        if(arr[i]-arr[i-1]>k){
            res=max(res,cnt);
            cnt=1;
        }
        else{
            cnt++;
        }
        
        // cout<<endl;
        // cout<<arr[i]<<" count:"<<cnt<<endl;
    }
    res=max(res,cnt);
    return n-res;


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