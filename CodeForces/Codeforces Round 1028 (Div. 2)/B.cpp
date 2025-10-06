#include<bits/stdc++.h>
using namespace std;

long long compute(long long x){
    if(x==0){
        return 1;
    }
    if(x==1){
        return 2;
    }
    long long val=compute(x/2);
    if(x%2==0){
        return (val)%998244353*(val)%998244353;
    }
    return ((val)%998244353*(val)%998244353*2)%998244353;
}
void solve(){
    long long n;
    cin>>n;
    vector<long long>arr1(n),arr2(n);
    for(long long i=0;i<n;i++){
        cin>>arr1[i];
    }
    for(long long i=0;i<n;i++){
        cin>>arr2[i];
    }

    long long i=0;
    long long s;
    long long value1_max=arr1[0],index1_max=0,value2_max=arr2[0],index2_max=0;
    while(i<n){
        if(value1_max<=arr1[i]){
            value1_max=arr1[i];
            index1_max=i;
        }
        if(value2_max<=arr2[i]){
            value2_max=arr2[i];
            index2_max=i;
        }
        if(value1_max>value2_max){
            s=(compute(value1_max)+compute(arr2[i-index1_max]))%998244353;
            cout<<s<<" ";
        }
        else if(value1_max<value2_max){
            s=(compute(value2_max)+compute(arr1[i-index2_max]))%998244353;
            cout<<s<<" ";
        }
        else{
            s=(compute(value1_max)+compute(max(arr1[i-index2_max],arr2[i-index1_max])))%998244353;
            cout<<s<<" ";
        }
        i++;
    }
    cout<<"\n";
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