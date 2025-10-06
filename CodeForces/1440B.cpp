#include<bits/stdc++.h>
using namespace std;

void solve(){
    // long long n,k;
    // cin>>n>>k;
    // vector<long long>v(n*k);
    // for(long long i=0;i<n*k;i++){
    //     cin>>v[i];
    // }
    // long long j=v.end()-v.begin()-n/2-1;
    // if(n==2){
    //     j=n*k-2;
    // }
    // long long ans=0;
    // while(k--){
    //     // cout<<"v[j] "<<v[j]<<endl;
    //     ans+=v[j];
    //     j-=(n/2+1);
    // }
    // cout<<ans<<"\n";
    // return;
    const int N=2e5+100;
    long long a[N];
    long long n, k;
    cin >> k >> n;
    for (int i=1;i<=n*k;i++){
        cin >> a[i];
    }
    long long x=(k+1)/2 - 1;
    x = k - x;
    long long z=n*k+1;
    long long ans=0;
    while(n--){
        z-=x;
        if (z<=0) break;
        ans+=a[z];
        cout<<"z:"<<z<<"a[z]: "<<a[z]<<endl;
        cout<<n<<endl;
    }
    cout << ans << endl;
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