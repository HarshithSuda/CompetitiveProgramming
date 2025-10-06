#include<bits/stdc++.h>
using namespace std;

bool isPlace(vector<int>&row,set<pair<int,int>>&s,int r,int c){
    for(int prev=0;prev<c;prev++){
        if(row[prev]==r|| abs(row[prev]-r)==abs(prev-c)){
            return false;
        }
    }
    return true;
}

void BackTracking(vector<int>&row,set<pair<int,int>>&s,int c,int &count,int n,bitset<30>&row_diag,bitset<30>&ld,bitset<30>&rd){
    if(c==n){
        count++;
    }
    for(int r=0;r<n;r++){
        if(s.find({r,c})==s.end() && !row_diag[r] && !ld[r-c+n-1] && !rd[r+c] ){
            row[c]=r;
            row_diag[r]=ld[r-c+n-1]=rd[r+c]=true;
            BackTracking(row,s,c+1,count,n,row_diag,ld,rd);
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
    int n;
    int newlinePrint=0;
    int caseNo=1;
    char line[105];
    while(scanf("%d",&n) && n!=0){
        // printf("%d value of n :\n",n);
        if(newlinePrint++){
            printf("\n");
        }
        // printf("here");
        getchar();
        vector<string>grid(n);
        bitset<30>row_diag,ld,rd;
        int count=0;
        vector<int>row(n,0);
        set<pair<int,int>>s;
        for(int i=0;i<n;i++){
            fgets(line,sizeof(line),stdin);
            line[strcspn(line,"\n")]=0;
            grid[i]=string(line);
            for(int j=0;j<n;j++){
                if(grid[i][j]=='*'){
                    s.insert({i,j});
                }
            }
        }
       
        BackTracking(row,s,0,count,n,row_diag,ld,rd);
        printf("Case %d: %d",caseNo,count);
        caseNo++;

        // printf("value of n is :%d",n);
    }


    return 0;
}