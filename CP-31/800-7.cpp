#include<bits/stdc++.h>
using namespace std;

int match(string x,int i,string s,int m){
    int j=0;
    while(j<m){
        if(x[i]==s[j]){
            i++;
            j++;
        }
        else{
            return -1;
        }
    }
    return i-1;
}
void solve(){
    int n,m;
    cin>>n>>m;
    string x,s;
    cin>>x>>s;
    while(x.length()<=50){
        x=x+x;
    }
    int j=-1;
    for(int i=0;i<=((x.length()-m));i++){
        j=match(x,i,s,m);
        
        if(j!=-1){
            // cout<<"x: "<<x<<endl;
            // cout<<"s: "<<s<<endl;
            // cout<<"j: "<<j<<endl;
            if(j<n){
                cout<<0<<"\n";
                return;
            }
            int ans=ceil(log2(float(j+1)/n));
            cout<<ans<<"\n";
            return;
        }
    }
    cout<<-1<<"\n";
    return;
}
void solve2(){
    int n,m;
    cin>>n>>m;
    string x,s;
    cin>>x>>s;
    string temp=x;
    for(int i=0;i<6;i++){
        if(x.find(s)!=string::npos){
            cout<<i<<endl;
            return;
        }
        x+=x;
    }
    cout<<-1<<endl;
    return;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        solve2();
    }
    

    return 0;
}