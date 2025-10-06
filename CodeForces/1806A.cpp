#include<bits/stdc++.h>
using namespace std;

int solve(){
    long long a,b,c,d,ans=0;
    cin>>a>>b>>c>>d;
    if(b>d){
        return -1;
    }
    if(b<d){
        ans+=(d-b);
        a+=ans;
        b=d;
    }
    if(b==d){
        if(c>a){
            return -1;
        }
        else{
            return ans+abs(a-c);
        }
    }
    return -1;

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