#include<bits/stdc++.h>
using namespace std;

template <typename T>
    void printVectorOfVector(const vector<vector<T>>& v) {
        for (size_t i = 0; i < v.size(); i++) {
            for (size_t j = 0; j < v[i].size(); j++) {
                cout << v[i][j] << " ";
            }
            cout << "\n";
        }
    }
int maximalSquare(vector<vector<char>>& matrix) {
    int m=matrix.size();
    int n=matrix[0].size();
    vector<vector<int>>memo(m+1,vector<int>(n+1,0));
    int maxx=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(matrix[i-1][j-1]-'0'==0){
                memo[i][j]=0;
            }
            else{
                memo[i][j]=1+min(memo[i-1][j-1],min(memo[i][j-1],memo[i-1][j]));
                maxx=max(maxx,memo[i][j]);
            }
        }
    }
    // printVectorOfVector(memo);
    // cout<<m<<n<<endl;
    return maxx*maxx;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<char>>matrix{{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout<<maximalSquare(matrix)<<endl;
    return 0;
}