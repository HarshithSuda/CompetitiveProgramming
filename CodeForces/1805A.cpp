#include<bits/stdc++.h>
using namespace std;

int solve(){
    int n;
    cin>>n;
    int x=0;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        x^=t;
    }
    if(n%2==1){
        return x;
    }
    else{
        if(x==0){
            return 1;
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