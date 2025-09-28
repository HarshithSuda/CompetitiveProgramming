#include<bits/stdc++.h>
using namespace std;


void printVector(vector<int>&v){
    for(auto &x:v){
        cout<<x<<" ";
    }
    cout<<endl;
}

void recSprial(vector<vector<int>>&mat,int a,int b,int m,int n,vector<int>&ans){
        if(a==n-1){
            cout<<a<<endl;
            cout<<b<<endl;
            cout<<m<<endl;
            cout<<n<<endl;
            for(int i=b;i<m;i++){
                ans.push_back(mat[a][i]);
            }
            return;
        }
        if(b==m-1){
            cout<<a<<endl;
            cout<<b<<endl;
            cout<<m<<endl;
            cout<<n<<endl;
            for(int i=a;i<n;i++){
                ans.push_back(mat[i][b]);
            }
            return;
        }
    if(m<0 || n<0 || a>m || b>n){return;}
    for(int i=b;i<m;i++){
        ans.push_back(mat[a][i]);
    }
    for(int i=a+1;i<n;i++){
        ans.push_back(mat[i][m-1]);
    }
    if(n-1!=a){
        for(int i=m-2;i>=b;i--){
            ans.push_back(mat[n-1][i]);
        }
    
        for(int i=n-2;i>a;i--){
            ans.push_back(mat[i][b]);
        }
    }
    recSprial(mat,a+1,b+1,m-1,n-1,ans);
    return;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int>ans;
    recSprial(matrix,0,0,matrix[0].size(),matrix.size(),ans);
    printVector(ans);
    return ans;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<int>>mat={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int>ans=spiralOrder(mat);

    return 0;
}