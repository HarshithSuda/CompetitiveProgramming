#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    cin>>n;
    vector<long long>arr(n);
    for(long long i=0;i<n;i++){
        cin>>arr[i];
    }
    unordered_set<long long>curr,seen;
    long long ans=0;
    for(int i=0;i<n;i++){
        curr.insert(arr[i]);
        seen.insert(arr[i]);
        if(curr.size()==seen.size()){
            ans++;
            seen.clear();
        }
    }
    cout<<ans<<endl;
    return;
}
void solve2(){
    int n;
    cin>>n;
    vector<int>arr(n);
    vector<int>distinct(n),freq(n+1);//1<=ai<=n
    for(int i=0;i<n;i++){
        cin>>arr[i];
        freq[arr[i]]++;
        if(freq[arr[i]]==1){
            distinct[i]=1; //we have found a new element at i
        }
        distinct[i]+=(i?distinct[i-1]:0);
    }
    fill(freq.begin(),freq.end(),0);
    int ans=0,total=0,end=n-1;
    for(int i=n-1;i>=0;i--){
        freq[arr[i]]++;
        if(freq[arr[i]]==1){
            total++;
        }
        if(total==distinct[end]){
            ans++;
            // for(int j=i;j<=end;j++){
            //     freq[arr[j]]=0;
            // }
            fill(freq.begin(),freq.end(),0);
            end=i-1;
            total=0;
        }
    }
    cout<<ans<<"\n";
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