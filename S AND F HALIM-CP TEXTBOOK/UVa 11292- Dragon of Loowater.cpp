#include<bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n,m;
    while(scanf("%d%d",&n,&m) ,(n||m)){
        vector<int>dragons(n),knights(m);
        for(int i=0;i<n;i++){
            scanf("%d",&dragons[i]);
        }
        for(int i=0 ;i<m;i++){
            scanf("%d",&knights[i]);
        }
        sort(dragons.begin(),dragons.end());
        sort(knights.begin(),knights.end());
        int i=0,j=0,height=0;
        while(i<n && j<m){
            if(dragons[i]<=knights[j]){
                height+=knights[j];
                i++;j++;
            }
            else{
                j++;
            }
        }
        if(i<n){
            cout<<"Loowater is doomed!\n";
        }
        else{
            cout<<height<<"\n";
        }
        
    }

    return 0;
}