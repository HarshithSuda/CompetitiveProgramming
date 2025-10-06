#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int>&v){
    for(auto &x:v){
        cout<<x<<" ";
    }
    cout<<"\n";
}



int minCostII(vector<vector<int>>& costs) {
    int n=costs.size();
    int k=costs[0].size();
    vector<int>curr=costs[costs.size()-1];
    for(int i=costs.size()-2;i>=0;i--){
        vector<int>prev=costs[i];
        for(int j=0;j<k;j++){
            int q=INT_MAX;
            for(int z=0;z<k;z++){
                if(z==j){
                    continue;
                }
                q=min(q,curr[z]);
            }
            prev[j]+=q;
        }
        curr=prev;
    }
    int minn=INT_MAX;
    for(int i=0;i<k;i++){
        minn=min(minn,curr[i]);
    }
    return minn;
}

int minCostII(vector<vector<int>>&costs){
    int n=costs.size();
    int k=costs[0].size();
    vector<int>curr=costs[costs.size()-1];
    for(int i=costs.size()-2;i>=0;i--){
        vector<int>prev=costs[i];
        int minn=curr[0],minnIndex=0;
        int secMinn=INT_MAX,secMinnIndex=-1;
        for(int j=1;j<k;j++){
            if(curr[j]<minn){
                secMinn=minn;
                secMinnIndex=minnIndex;
                minn=curr[j];
                minnIndex=j;
            }
            else if(curr[j]<secMinn){
                secMinn=curr[j];
                secMinnIndex=j;
            }
        }
        for(int j=0;j<k;j++){
            if(j!=minnIndex){
                prev[j]+=minn;
            }
            else{
                prev[j]+=secMinn;
            }
        }
        curr=prev;
    }
    int minn=INT_MAX;
    for(int i=0;i<k;i++){
        minn=min(minn,curr[i]);
    }
    return minn;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>>costs={{11,20,4,3,19,3,18,17,6,8,18,18},{6,14,13,4,8,12,16,4,14,15,11,12},{8,1,4,20,19,9,12,11,13,12,1,3},{8,12,9,3,1,14,3,16,12,13,4,10},{17,1,1,5,17,10,20,15,3,9,18,3},{16,3,18,11,1,16,3,10,19,6,11,13}};
    cout<<minCostII(costs)<<endl;
    return 0;
}