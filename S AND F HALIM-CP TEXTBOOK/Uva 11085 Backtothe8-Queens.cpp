#include<bits/stdc++.h>
using namespace std;

void NqueenProblem(vector<vector<int>>&storage,vector<int>&row,int c,int n,bitset<8>&row_diag,bitset<15>&ld,bitset<15>&rd){
    if(c==n){
        storage.push_back(row);
        return;
    }
    for(int r=0;r<n;r++){
        if(!row_diag[r] && !ld[r-c+n-1] && !rd[r+c]){
            row[c]=r;
            row_diag[r]=ld[r-c+n-1]=rd[r+c]=true;
            NqueenProblem(storage,row,c+1,n,row_diag,ld,rd);
            row_diag[r]=ld[r-c+n-1]=rd[r+c]=false;
        }
    }
}
int minimizeShift(vector<vector<int>>&storage,vector<int>&arr){
    int minn=0,ans=INT_MAX;
    for(int i=0;i<storage.size();i++){
        for(int j=0;j<storage[i].size();j++){
            if(arr[j]!=(storage[i][j]+1)){
                minn++;
            }
        }
        ans=min(minn,ans);
        minn=0;
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
    vector<vector<int>>storage;
    vector<int>row(8);
    bitset<8>row_diag;
    bitset<15>ld,rd;
    NqueenProblem(storage,row,0,8,row_diag,ld,rd);
    // for(int i=0;i<storage.size();i++){
    //     for(int j=0;j<storage[i].size();j++){
    //         printf("%d ",storage[i][j]);
    //     }
    //     printf("\n");
    // }
    int n;
    int caseNo=1;
    // int nextLine=0;
    while(scanf("%d",&n)==1){
        // if(nextLine++){
        //     printf("\n");
        // }
        vector<int>arr(8);
        arr[0]=n;
        for(int i=1;i<8;i++){
            scanf("%d",&arr[i]);
        }
        printf("Case %d: %d\n",caseNo,minimizeShift(storage,arr));
        caseNo++;
    }
    

    return 0;
}