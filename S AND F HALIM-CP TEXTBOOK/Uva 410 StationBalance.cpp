#include<bits/stdc++.h>
using namespace std;

void solve(int c,int s,int CaseNo){
    
    vector<int>v(2*c,0);
    double sum=0;
    // cout<<"here1\n";
    for(int i=0;i<s;i++){
        int t;
        scanf("%d",&t);
        v[i]=t;
        sum+=(double)t;
        // cout<<"here1\n";
    }
    // for(auto x: vVanilla){
    //     cout<<x<<endl;
    // }
    // for(auto x: v){
    //     cout<<x<<endl;
    // }
    sort(v.begin(),v.end());
    sum=sum/c;
    // cout<<"here2\n";
    double Imbalance=0;
    printf("Set #%d\n",CaseNo);
    // cout<<"here3\n";
    int cases=0;
    for(int i=0;i<c;i++){
        printf(" %d:",i);
        if(v[i]){
            printf(" %d",v[i]);
        }
        if(v[2*c-i-1]){
            printf(" %d",v[2*c-i-1]);
        }
        printf("\n");
        Imbalance+=abs(v[i]+v[2*c-i-1]-sum);
    }
    printf("IMBALANCE = %.5lf\n\n",Imbalance);
    return;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int c,s,caseNo=1;
    
    while(scanf("%d%d",&c,&s)==2){
        // if(caseNo>=2){
        //     printf("\n");
        // }
        solve(c,s,caseNo);
        caseNo++;
    }

    return 0;
}