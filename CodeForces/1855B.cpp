#include<bits/stdc++.h>
using namespace std;
void findAllDivisors(long long n,vector<long long>&v){
    int i;
    for(i=1;i*i<n;i++){
        if(n%i==0){
            v.push_back(i);
        }
    }
    if(i-n/i==1){ //(30=(5,6)) if we dont do this we will get 
        i--;
    }
    for(;i>=1;i--){
        if(n%i==0){
            v.push_back(n/i);
        }
    }
    return;
}
void solve(vector<vector<long long>>&allFactors){
    long long n;
    cin>>n;
    if(n==1){
        cout<<1<<"\n";
        return;
    }
    long long ans=0;//keeps track of no. of counsecutive elements
    long long temp=0;
    vector<long long>v=allFactors[n];
    for(int i=1;i<v.size();i++){
        if(v[i]-v[i-1]==1){
            temp++;
        }
        else{
            ans=max(temp,ans);
            temp=0;
        }
    }
    ans=max(temp,ans);
    cout<<ans+1<<"\n";
    return;

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
    const long long N = 10001;
    vector<vector<long long>> allFactors(N);
    for (int i = 1; i < N; ++i)
        for (int j = i; j < N; j += i)
            allFactors[j].push_back(i);
    while(t--){
        solve(allFactors);
    }

    return 0;
}