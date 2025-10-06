#include<bits/stdc++.h>
using namespace std;

int solve(){
    long long n;
    cin>>n;

    vector<long long>v(n);
    
    long long c=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(i==0){
            if(n==1){
                return 0;
            }
            continue;
        }
        if((v[i]^v[i-1])%2==0){
            c++;
        }
    }
    return c;

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