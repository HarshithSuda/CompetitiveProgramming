This repository is a comprehensive archive of my C++ solutions from my journey in competitive programming.

It features organized code submissions across various online judges and practice platforms, showcasing my progress in algorithms, data structures, and problem-solving techniques.

CP-31: CP-31 Sheet by Priyansh Agarwal.

CodeForces: Solutions for Codeforces rounds.

LeetCode: LeetCode daily challenges and study plan solutions.

GeeksForGeeks-DSA Practice Sheets: Core Data Structures and Algorithms practice from GeekForGeeks Website.

S AND F HALIM-CP TEXTBOOK: Solutions to exercises from the definitive CP textbook.


1.A Code Snippet of the UVA 11195.Another N-Queen Problem

```cpp
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
```


2.Code for LeetCode-714. Best Time to Buy and Sell Stock with Transaction Fee

```cpp
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int>&v){
    for(auto &x:v){
        cout<<x<<" ";
    }
    cout<<"\n";
}

int dp(int i,int fee,int holding,vector<int>&prices,vector<vector<int>>&boolMemo){
    if(i==prices.size())return 0;
    if(boolMemo[holding][i]!=-1)return boolMemo[holding][i];
    if(holding){
        boolMemo[holding][i]=max(prices[i]-fee+dp(i+1,fee,0,prices,boolMemo),dp(i+1,fee,1,prices,boolMemo));
    }
    else{
        boolMemo[holding][i]=max(-prices[i]+dp(i+1,fee,1,prices,boolMemo),dp(i+1,fee,0,prices,boolMemo));
    }
    return boolMemo[holding][i];
}
int maxProfit(vector<int>& prices, int fee) {
    vector<vector<int>>boolMemo(2,vector<int>(prices.size(),-1));
    int z=dp(0,fee,0,prices,boolMemo);
    int y=dp(0,fee,1,prices,boolMemo);
    return z;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int>prices={1,3,2,8,4,9};
    cout<<maxProfit(prices,2)<<endl;
    return 0;
}
```
