#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int>&v){
    for(auto &x:v){
        cout<<x<<" ";
    }
    cout<<"\n";
}

int binarySearch(vector<int>&days,int day){
    int low=0,high=days.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(days[mid]==day){
            return mid;
        }
        else if(days[mid]>day){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return high;
}
int dp(int i,vector<int>&days,vector<int>&costs,vector<int>&memo){
    // cout<<"i:"<<i<<endl;
    if(i<0){
        return 0;
    }
    if(i==0){
        return min(min(costs[1],costs[2]),costs[0]);
    }
    // cout<<i<<endl;
    if(memo[i]!=-1){return memo[i];}
    int currentDay=days[i];
    int z=costs[0]+dp(i-1,days,costs,memo);
    int y=costs[1];
    if(currentDay-7>0){
        int sevenDayIndex=binarySearch(days,currentDay-7);
        // cout<<sevenDayIndex<<endl;
        y+=dp(sevenDayIndex,days,costs,memo);
    }
    int x=costs[2];
    if(currentDay-30>0){
        int thirtyDayIndex=binarySearch(days,currentDay-30);
        x+=dp(thirtyDayIndex,days,costs,memo);
    }
    memo[i]=min(min(x,y),z);
    // cout<<"here"<<endl;
    return memo[i];
}

int mincostTickets(vector<int>& days, vector<int>& costs) {
    vector<int>memo(days.size(),-1);
    int z=dp(days.size()-1,days,costs,memo);
    // printVector(memo);
    return z;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int>days={6,8,9,18,20,21,23,25   },costs={2,10,41};
    cout<<mincostTickets(days,costs)<<endl;
    return 0;
}