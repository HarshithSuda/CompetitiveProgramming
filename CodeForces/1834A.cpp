#include<bits/stdc++.h>
using namespace std;

int solve(){
    int n,x=0,y=0,c=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        if(t==1){
            x++;
        }
        else{
            y++;
        }
    }
    while(!(x>=y) || !(y%2==0)){
        if(x>=y){
            return 1;
        }
        else if(y%2==0){
            x+=2;
            y-=2;
            c+=2;
        }
        else if(y%2==1){
            x++;
            y--;
            c++;
        }
    }
    return c;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input1.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<"\n";
    }

    return 0;
}