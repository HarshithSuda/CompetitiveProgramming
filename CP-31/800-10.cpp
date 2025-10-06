#include<bits/stdc++.h>
using namespace std;

void solve(){
    unordered_map<int,int>m{{1,0},{2,0},{3,0},{4,0},{5,0}};
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            char c;
            cin>>c;
            if(c=='X'){
                if(i==0 || j==0|| i==9 ||j==9){
                    m[1]++;
                }
                else if(i==1 || j==1|| i==8 ||j==8){
                    m[2]++;
                }
                else if(i==2 || j==2|| i==7 ||j==7){
                    m[3]++;
                }
                else if(i==3 || j==3|| i==6 ||j==6){
                    m[4]++;
                }
                else{
                    m[5]++;
                }
            }
        }
    }
    int s=0;
    for(auto x: m){
        s+=(x.first)*x.second;
    }
    cout<<s<<"\n";
    return;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}