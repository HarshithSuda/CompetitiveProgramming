#include<bits/stdc++.h>
using namespace std;

int solve(){
    int n;
    cin>>n;
    if(n<=9){
        return n;
    }
    int cnt=9;
    n/=10;
    while(true){
        int x=n%10;
        n/=10;
        if(n==0){
            cnt+=x;
            return cnt;
        }
        else{
            cnt+=9;
        }
    }
    return cnt;

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