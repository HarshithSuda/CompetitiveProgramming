#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int n=8,lineCounter,row[8],a,b;

bool isPlace(int r,int c){
    for(int prev=0;prev<c;prev++){
        if(row[prev]==r || abs(row[prev]-r)==abs(prev-c)){
            return false;
        }
    }
    return true;
}
void backTrack(int c){
    if(c==n && row[b-1]==a-1){
        lineCounter++;
        printf("%2d      %d",lineCounter,row[0]+1);
        for(int x=1;x<n;x++){
            printf(" %d",row[x]+1);
        }
        printf("\n");
    }
    for(int r=0;r<n;r++){
        if(isPlace(r,c)){
            row[c]=r;
            backTrack(c+1);
        }
    }
}


// void backTrack(vector<int>&row,int c,int n,bitset<8>&row_diag,bitset<15>&ld,bitset<15>&rd){
//     if(c==n && row[b-1]==a-1){
//         lineCounter++;
//         printf("%2d      %d",lineCounter,row[0]+1);
//         for(int x=1;x<n;x++){
//             printf(" %d",row[x]+1);
//         }
//         printf("\n");
//     }
//     for(int r=0;r<n;r++){
//         if(!row_diag[r] && !ld[r-c+n-1] && !rd[r+c]){
            // row[c]=r;
            // row_diag[r]=ld[r-c+n-1]=rd[r+c]=true;
            // backTrack(row,c+1,n,row_diag,ld,rd);
            // row_diag[r]=ld[r-c+n-1]=rd[r+c]=false;
        // }
//     }
// }

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    auto start=high_resolution_clock::now();
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&a,&b);
        memset(row,0,8);
        lineCounter=0;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        backTrack(0);
        if(t){printf("\n");}
    }
    auto end=high_resolution_clock::now();
    auto duration=duration_cast<microseconds>(end-start);
    printf("%d",duration.count());
    return 0;
}