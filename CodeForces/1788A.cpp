#include<bits/stdc++.h>
using namespace std;

int solve(){
    int n;
    cin>>n;
    vector<int>v(n);
    int count_twos=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(v[i]==2){
            count_twos++;
        }
    }
    if(count_twos==0){
        return 1;
    }
    if(count_twos%2==1){
        return -1;
    }
    int c=0;
    for(int i=0;i<n;i++){
        if(v[i]==2){
            c++;
        }
        if(c==count_twos/2){
            return i+1;
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