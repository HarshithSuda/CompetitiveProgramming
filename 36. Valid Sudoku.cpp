#include<bits/stdc++.h>
using namespace std;
bool isValidSudoku(vector<vector<char>>& board) {
    //ROW 
    for(int i=0;i<9;i++){
        unordered_map<char,int>m;
        for(int j=0;j<9;j++){
            if(board[i][j]!='.'){
                m[board[i][j]]++;
                if(m[(board[i][j])]>1){
                    return false;
                }
            }
            
        }
    }
    //COLUMN
    for(int i=0;i<9;i++){
        unordered_map<int,int>m;
        for(int j=0;j<9;j++){
            if(board[j][i]!='.'){
                m[board[j][i]]++;
                if(m[(board[j][i])]>1){
                    return false;
                }
            }
        }
    }
    //sub boxes
    for(int z=0;z<3;z++){
        for(int i=0;i<3;i++){
        unordered_map<int,int>m;
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(board[j+z*3][k+i*3]!='.'){
                    m[board[j+z*3][k+i*3]]++;
                    if(m[board[j+z*3][k+i*3]]>1){
                        return false;
                    }
                }
            }
        }
    }
    }
    
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

vector<vector<char>> board = {
    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
};

vector<vector<char>> board1 = {
    {'.', '.', '.', '.', '5', '.', '.', '1', '.'},
    {'.', '4', '.', '3', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '3', '.', '.', '1'},
    {'8', '.', '.', '.', '.', '.', '.', '2', '.'},
    {'.', '.', '2', '.', '7', '.', '.', '.', '.'},
    {'.', '1', '5', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '2', '.', '.', '.'},
    {'.', '2', '.', '9', '.', '.', '.', '.', '.'},
    {'.', '.', '4', '.', '.', '.', '.', '.', '.'}
};

    cout<<isValidSudoku(board)<<endl;

    return 0;
}