#include<bits/stdc++.h>
using namespace std;

int solve(){
    long long n;
    cin>>n;
    long long z=ceil(log2(n));
    if(n==pow(2,z)){
        return 2*z+3;
    }
    return 2*z+1;

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