#include<bits/stdc++.h>
using namespace std;
int M1theCelebrityProblem(vector<vector<int>>mat,int n){
    vector<int>knows(n,0),known(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==1){
                knows[i]++;
                known[j]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<knows[i]<<" "<<known[i]<<endl;
    }
    for(int i=0;i<n;i++){
        if(knows[i]==0 && known[i]==n-1){
            return i;
        }
    }
    return -1;
}
int M2theCelebrityProblem(vector<vector<int>>mat,int n){
    stack<int>s;
    for(int i=0;i<n;i++){
        s.push(i);
    }
    while(s.size()>1){
        int a=s.top();
        s.pop();
        int b=s.top();
        s.pop();
        if(mat[a][b]){
            s.push(b);
        }
        else{
            s.push(a);
        }
    }
    int c=s.top();
    s.pop();
    for(int i=0;i<n;i++){
        if(i==c){
            continue;
        }
        if(mat[c][i]==1 || mat[i][c]==0){
            return -1;
        }
    }
    return c;
}
int M3theCelebrityProblem(vector<vector<int> >& mat) {
    int n=mat.size();
    int i=0,j=n-1;
    while(i<j){
        if(mat[i][j]){//i knows j (i cant be celebrity)
            i++;
        }
        else{
            j--; //i doesn't know j(j cant be celebrity)
        }
    }
    int c=j;//c=i (since while loop terminated when both become equal)
    for(int i=0;i<n;i++){
    
        if(c!=i &&(mat[c][i]==1 || mat[i][c]==0)){
            return -1;
        }
    }
    return c;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>>mat={ {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 1, 0} };
    cout<<M2theCelebrityProblem(mat,4)<<endl;
    return 0;

}