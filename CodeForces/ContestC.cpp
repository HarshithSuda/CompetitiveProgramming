#include<bits/stdc++.h>
using namespace std;
int countOfnonzero(vector<int>&arr){
    int cnt=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>0){
            cnt++;
        }
    }
    return cnt;
}
int solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>mat(n,vector<int>(m));
    int maxx=-1,secMax=-1;
    vector<int>row_max(n,0);
    vector<int>col_max(m,0);
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
            if(mat[i][j]>maxx){
                maxx=mat[i][j];
                cnt++;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==maxx){
                row_max[i]++;
                col_max[j]++;
            }
            if(mat[i][j]==secMax){
                row_sec_max[i]++;
                col_sec_max[j]++;
            }
        }
    }
    // cout<<"here1"<<endl;
    int index_max_element_row=max_element(row_max.begin(),row_max.end())-row_max.begin();
    // cout<<index_max_element_row<<endl;
    int index_max_element_col=max_element(col_max.begin(),col_max.end())-col_max.begin();
    // cout<<row_max[index_max_element_row]<<endl;
    // cout<<col_max[index_max_element_col]<<endl;
    int a=row_max[index_max_element_row];
    int b=col_max[index_max_element_col];
    // cout<<(a>=b)<<endl;
        // cout<<"here2"<<endl;
    if(a>=b){
        row_max[index_max_element_row]=0;
        
        for(int i=0;i<m;i++){
            if(col_max[i]!=0 && mat[index_max_element_row][i]==maxx){
                col_sec_max[i]++;
                row_sec_max[index_max_element_row]++;
                col_max[i]--;
            }
            if(maxx-secMax==1 && mat[index_max_element_row][i]==secMax){
                row_sec_max[index_max_element_row]=0;
                col_sec_max[i]--;
            }
        }
        
        int count_of=countOfnonzero(col_max);
        // cout<<(maxx-secMax>1)<<endl;
        // cout<<"count of nonzero:"<<count_of<<endl;
        
        if(maxx-secMax>1){
            
            if(count_of==0){
                if(maxx-2==-1){
                    return 0;
                }
                return maxx-2;
            }
            else if(count_of==1){
                
                return maxx-1;
                // cout<<"here3"<<endl;
            }
            else{
                return maxx;
            }
        }
        else{
            if(count_of>1){
                return maxx;
            }
            else if(count_of==1){
                return maxx-1;
            }
            else{
                int second_row_count=countOfnonzero(row_sec_max),second_col_count=countOfnonzero(col_sec_max);
                if(second_row_count==0 && second_col_count==0){
                    if(maxx-2==-1){
                        return 0;
                    }
                    return maxx-2;
                }
                else{
                    return maxx-1;
                }
            }
        }
    }
    else{
        col_max[index_max_element_col]=0;
        for(int i=0;i<n;i++){
            if(row_max[i]!=0 && mat[i][index_max_element_col]==maxx){
                row_sec_max[i]++;
                col_sec_max[index_max_element_col]++;
                row_max[i]--;
            }
            if(maxx-secMax==1 && mat[i][index_max_element_col]==secMax){
                col_sec_max[index_max_element_col]=0;
                row_sec_max[i]--;
            }
        }
        // cout<<(maxx-secMax>1)<<endl;
        int count_of=countOfnonzero(row_max);
        // cout<<"count of nonzero:"<<count_of<<endl;
        
        
        if(maxx-secMax>1){
            if(count_of==0){
                if(maxx-2==-1){
                        return 0;
                    }
                return maxx-2;
            }
            else if(count_of==1){
                return maxx-1;
            }
            else{
                return maxx;
            }
        }
        else{
            if(count_of>1){
                return maxx;
            }
            else if(count_of==1){
                return maxx-1;
            }
            else{
                int second_row_count=countOfnonzero(row_sec_max),second_col_count=countOfnonzero(col_sec_max);
                if(second_row_count==0 && second_col_count==0){
                    if(maxx-2==-1){
                        return 0;
                    }
                    return maxx-2;
                }
                else{
                    return maxx-1;
                }
            }
        }

    }
    return maxx;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }

    return 0;
}