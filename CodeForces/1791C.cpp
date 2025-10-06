#include<bits/stdc++.h>
using namespace std;

int solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n==1){
        return 1;
    }
    int i=0,j=s.size()-1;
    while(i<=j){
        if(s[i]==s[j]){
            return j-i+1;
        }
        i++;
        j--;
    }
    return 0;

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