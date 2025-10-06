#include<bits/stdc++.h>
using namespace std;
int maxx;
void BackTracking(vector<int>&row,vector<vector<int>>&grid,int n,int c,bitset<15>&row_diag,bitset<15>&ld,bitset<15>&rd,int sum){
    if(c==n){
        // printf("sum: %d \n",sum);
        if(sum>maxx){
            maxx=sum;
        }
        return;
        // return;
        // sum=0;
    }
    for(int r=0;r<n;r++){
        if(!row_diag[r] && !ld[r-c+n-1] && !rd[r+c]){
            row[c]=r;
            row_diag[r]=ld[r-c+n-1]=rd[r+c]=true;
            sum+=grid[r][c];
            BackTracking(row,grid,n,c+1,row_diag,ld,rd,sum);
            sum-=grid[r][c];
            row_diag[r]=ld[r-c+n-1]=rd[r+c]=false;
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int k;
    int case_count=0;
    while(scanf("%d",&k)==1){
        
        while(k--){
        int sum=0;
        maxx=0;
        // getchar();//takes away the new line
        int n=8;
        char line[1000];
        vector<int>row(n,0);
        vector<vector<int>>grid(n,vector<int>(n));
        bitset<15>row_diag,ld,rd;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&grid[i][j]);
            }
        }
        BackTracking(row,grid,n,0,row_diag,ld,rd,sum);
        printf("%5d\n",maxx);
        maxx=0;
        }
        
    }
    

    return 0;
}