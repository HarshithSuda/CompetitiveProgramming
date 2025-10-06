#include<bits/stdc++.h>
using namespace std;
int* stockSpanProblem(int arr[],int n){
    int *ans=new int[n];
    fill(ans,ans+n,0);
    ans[0]=1;
    for(int i=1;i<n;i++){
        for(int j=i;j>=0;j--){
            
            if(arr[j]>arr[i]){
                break;
            }
            ans[i]++;
        }
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int arr[]={13,15,12,14,16,8,6,4,10,30};
    int *ans=stockSpanProblem(arr,10);
    for(int i=0;i<10;i++){
        cout<<ans[i]<<" ";
    }
    return 0;

}