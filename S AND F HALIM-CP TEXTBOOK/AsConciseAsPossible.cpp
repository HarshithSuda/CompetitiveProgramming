#include<bits/stdc++.h>
using namespace std;

void solve(){

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // int n;
    // scanf("%d",&n);
    // int arr[n];
    // int i=0;
    // while(i<n){
    //     cin>>arr[i];
    //     i++;
    // }
    // n=i;
    // sort(arr,arr+n);
    // printf("%d ",arr[0]);
    // for(int j=1;j<n;j++){
    //     if(arr[j]!=arr[j-1]){
    //         printf("%d ",arr[j]);
    //     }
    // }
    // if(arr[n-1]!=arr[n-2]){
    //     printf("%d ",arr[n-1]);
    // }
    //conversion of array into vector
    // int a[]={1,2,2,4,5,5,5,5,5};
    // vector<int>v(a,a+9);
    // sort(v.begin(),v.end());
    // for(auto x: v){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    // v.resize(unique(v.begin(),v.end())-v.begin());
    // for(auto x: v){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    // vector<pair<int,pair<int,int>>>v;
    // pair<int,pair<int,int>> A=make_pair(-1982,make_pair(4,25));
    // pair<int,pair<int,int>> B=make_pair(-2004,make_pair(1,20));
    // pair<int,pair<int,int>> E=make_pair(-2004,make_pair(1,19));
    // pair<int,pair<int,int>> F=make_pair(-2004,make_pair(3,19));
    // pair<int,pair<int,int>> C=make_pair(-1005,make_pair(8,18));
    // pair<int,pair<int,int>> D=make_pair(-1985,make_pair(2,10));
    // v.push_back(A);
    // v.push_back(E);
    // v.push_back(F);
    // v.push_back(B);
    // v.push_back(C);
    // v.push_back(D);
    // sort(v.begin(),v.end());
    // for(auto x :v){
    //     cout<<" day :"<<(x.second).second<<" month: "<<(x.second).first<<" year: "<<-(x.first)<<endl;
    // }
    // int n=5,target=10;
    // int L[]={10, 7, 5, 20, 8};
    // for(auto x:L){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    // sort(L,L+n);
    // for(auto x:L){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    // printf("%d\n ",binary_search(L,L+n,20));
    // int p[8];
    // for(int i=0;i<8;i++){p[i]=i;}
    // do{
    //     for(int i=0;i<8;i++){
    //         printf("%c",'a'+p[i]);
    //     }
    //     printf("\n");
    // }while(next_permutation(p,p+8));
    // int n=5;
    // int p[n];
    // for(int i=0;i<n;i++){p[i]=i+1;}
    // for(int i=0;i<(1<<n);i++){
    //     for(int j=0;j<n;j++){
    //         if(i&(1<<j)){ //checking if j bit is on in i
    //             printf("%d",p[j]);
    //         }
    //     }
    //     printf("\n");
    // }
    bitset<32>v(128);
    for(int i=0;i<32;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}