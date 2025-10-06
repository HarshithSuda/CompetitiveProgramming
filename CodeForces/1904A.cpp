#include<bits/stdc++.h>
using namespace std;

int solve(){
    int a,b,xK,yK,xQ,yQ;
    cin>>a>>b>>xK>>yK>>xQ>>yQ;
    set<pair<int,int>>King;
    set<pair<int,int>>Queen;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            King.insert({xK+pow(-1,i)*a,yK+pow(-1,j)*b});
            King.insert({xK+pow(-1,i)*b,yK+pow(-1,j)*a});
            Queen.insert({xQ+pow(-1,i)*a,yQ+pow(-1,j)*b});
            Queen.insert({xQ+pow(-1,i)*b,yQ+pow(-1,j)*a});
        }
    }
    int ans=0;
    for(auto x:King){
        if(Queen.find(x)!=Queen.end()){
            ans++;
        }
    }
    return ans;

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