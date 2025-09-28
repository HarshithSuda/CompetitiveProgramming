#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int>&v){
    for(auto &x:v){
        cout<<x<<" ";
    }
    cout<<endl;
}
bool exists(int a,int b,int m,int n){
    if(a>=0 && b>=0 && a<m && b<n){
        return true;
    }
    return false;
}
// vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
//     int m=mat.size();
//     int n=mat[0].size();
//     vector<int>v;
//     for(int i=0;i<=m+n-2;i++){
//         if(i>=n-1){
//             // if(i==2*(n-1)){
//             //     v.push_back(mat[n-1][n-1]);
//             //     continue;
//             // }
//             int a=n-1,b=i-a;
//             while(a!=i-(n-1)-1){
//                 if(!exists(a,b,m,n)){
//                     continue;
//                 }
//                 int temp=((i%2==0)?mat[a][b]:mat[b][a]);
//                 v.push_back(temp);
//                 a--;b++;
//             }
//         }
//         else{
//             int a=0,b=i;
//             // if(i==0){
//             //     v.push_back(mat[0][0]);
//             //     continue;
//             // }
//             while( a!=i+1){
//                 // cout<<"here1";
//                 if(!exists(a,b,m,n)){
//                     continue;
//                 }
//                 int temp=((i%2==0)?mat[b][a]:mat[a][b]);
//                 // cout<<"here2";
//                 v.push_back(temp);
//                 // cout<<"here3";
//                 a++;b--;
//             }
//         }
//     }
//         return v;
// }
vector<int> findDiagonalOrder(vector<vector<int>>& mat){
    int m=mat.size(),n=mat[0].size();
    vector<int>ans;
    vector<int>temp;
    int j,k;
    for(int i=0;i<=m+n-2;i++){
        if(i<min(m-1,n-1)){
            j=0,k=i;
            while(exists(j,k,m,n)){
                temp.push_back(mat[j][k]);
                j++;k--;
            }
        }
        else{
            j=min(m-1,n-1);k=i-j;
            if(j>k){
                swap(j,k);
            }
            while(exists(j,k,m,n)){
                temp.push_back(mat[j][k]);
                j++;k--;
            }
        }
        if(i%2!=0){
            ans.insert(ans.end(),temp.begin(),temp.end());
        }
        else{
            reverse(temp.begin(),temp.end());
            ans.insert(ans.end(),temp.begin(),temp.end());
        }
        temp.clear();
    }
    printVector(ans);
    return ans;
}

vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        int direction=1;
        vector<int>ans;
        int row=0,col=0;
        while(row<m && col<n){
            ans.push_back(mat[row][col]);
            int new_row=row+((direction==1)?-1:1);
            int new_col=col+((direction==1)?1:-1);
            if(new_row<0 || new_row==m || new_col<0|| new_col==n){
                //we have reached tail;
                if(direction==1){
                    row+=((col==n-1)?1:0);
                    col+=((col<n-1)?1:0);
                }
                else{
                    col+=((row==m-1)?1:0);
                    row+=((row<m-1)?1:0);
                    
                }
                direction=1-direction;
            }
            else{
                row=new_row;
                col=new_col;
            }
        }
        return ans;
    }
   
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>>mat={{2,3}};
    //={{1,2,3},{4,5,6},{7,8,9}};
    vector<int>ans=findDiagonalOrder(mat);

    return 0;
}