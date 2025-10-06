#include<bits/stdc++.h>
using namespace std;
//Cover in Water
int solve(int n,string s){
    int c=0;
    for(int i=0;i<n;i++){
        if(s[i]=='.'){
            c++;
        }
        if(i!=0 && i!=n-1 && s[i-1]=='.' && s[i]=='.' && s[i+1]=='.'){
            return 2;
        }
    }
    return c;
}

int bonusSolve(int n,string s){
    int c=0,twoCount=0;
    for(int i=0;i<n;i++){
        if(s[i]=='.'){
            c++;
        }
        if(i!=0 && s[i-1]=='.' && s[i]=='.'){
            twoCount++;
        }
        if(i!=0 && i!=n-1 && s[i-1]=='.' && s[i]=='.' && s[i+1]=='.'){
            return 2;
        }
    }
    return twoCount+(c-2*twoCount);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        cout<<solve(n,s)<<endl;
    }

    return 0;
}