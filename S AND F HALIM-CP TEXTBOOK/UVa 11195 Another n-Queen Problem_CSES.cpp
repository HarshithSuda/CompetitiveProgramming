// #include<bits/stdc++.h>
// using namespace std;



// void BackTracking(vector<int>&row,set<pair<int,int>>&s,int c,int &count,int n,bitset<30>&row_diag,bitset<30>&ld,bitset<30>&rd){
//     if(c==n){
//         count++;
//     }
//     for(int r=0;r<n;r++){
//         if(s.find({r,c})==s.end() && !row_diag[r] && !ld[r-c+n-1] && !rd[r+c] ){
//             row[c]=r;
//             row_diag[r]=ld[r-c+n-1]=rd[r+c]=true;
//             BackTracking(row,s,c+1,count,n,row_diag,ld,rd);
//             row_diag[r]=ld[r-c+n-1]=rd[r+c]=false;
//         }
//     }
// }

// int main(){

//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     #ifndef ONLINE_JUDGE
//         freopen("input.txt", "r", stdin);
//         freopen("output.txt", "w", stdout);
//     #endif
//     int n=8;

//     char line[105];
//         // printf("here");
//         vector<vector<char>>grid(n,vector<char>(8));
//         bitset<30>row_diag,ld,rd;
//         int count=0;
//         vector<int>row(n,0);
//         set<pair<int,int>>s;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 char c;
//                 cin>>c;
//                 grid[i][j]=c;
//                 if(grid[i][j]=='*'){
//                     // cout<<"here"<<endl;
//                     s.insert({i,j});
//                 }
//             }
//         }
       
//         BackTracking(row,s,0,count,n,row_diag,ld,rd);

//         printf("%d\n",count);


//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
 
#define FREE '.'
#define RESERVED '*'
#define QUEEN 'q'
 
bool notAttacking(int board[8][8], int row, int col) {
    for (int i = 1; i <= row; i++) {
        if (board[row - i][col] == QUEEN) return false;
        if (col - i >= 0 && board[row - i][col - i] == QUEEN) return false;
        if (col + i < 8 && board[row - i][col + i] == QUEEN) return false;
    }
 
    return true;
}
 
int nQueens(int board[8][8], int row) {    
    if (row == 8) return 1;
    int total = 0;
    
    for (int i = 0; i < 8; i++) {
        if (board[row][i] != RESERVED) {
            if (notAttacking(board, row, i)) {
                board[row][i] = QUEEN;
                total += nQueens(board, row + 1);
            }
            board[row][i] = FREE;
        }
    }
 
    return total;
}
 
int main() {
    int board[8][8];
 
    char c;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> c;
            board[i][j] = c;
        }
    }
 
    cout << nQueens(board, 0);
}