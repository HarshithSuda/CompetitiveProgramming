#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left,*right;
    Node(int k){
        key=k;
        left=right=NULL;
    }
};
void printVector(vector<int>v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
bool checkConsecutive(vector<int>temp){
    for(int i=0;i<temp.size()-1;i++){
        if((temp[i+1]-temp[i])!=1){
            return false;
        }
    }
    return true;
}
bool checkArray(vector<int>arr,int low,int high){
    if(low==high){
        return true;
    }
    vector<int>temp(arr.begin()+low,arr.begin()+high+1);
    // printVector(temp);
    sort(temp.begin(),temp.end());
    // printVector(temp);
    bool flag=checkConsecutive(temp);
    if(!flag){
        return false;
    }
    bool flag1=checkArray(arr,low,(low+high)/2);
    if(!flag1){
        return false;
    }
    return checkArray(arr,(low+high)/2+1,high);
}
int mergeCount(vector<int>&arr,int low,int high){
   if(arr[low]>arr[high]){
        sort(arr.begin()+low,arr.begin()+high+1);
        vector<int>temp(arr.begin()+low,arr.begin()+high+1);
        if(!checkConsecutive(temp)){
            return INT_MIN;
        }
        return 1;
   }
   else{
        sort(arr.begin()+low,arr.begin()+high+1);
        vector<int>temp(arr.begin()+low,arr.begin()+high+1);
        if(!checkConsecutive(temp)){
            return INT_MIN;
        }
        return 0;
   }
}
int mergeSortLogic(vector<int>&arr,int low,int high){
    int sum=0;
    if(low<high){
        sum+=mergeSortLogic(arr,low,(low+high)/2);
        if(sum<0){
            return -1;
        }
        sum+=mergeSortLogic(arr,(low+high)/2+1,high);
        if(sum<0){
            return -1;
        }
        sum+=mergeCount(arr,low,high);
        if(sum<0){
            return -1;
        }
    }
    return ((sum<0)?-1:sum);
}
//method -1
int sum(int )
int Solution_1741(vector<int>arr){
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        // if(!checkArray(arr,0,n-1)){
        //     cout<<-1<<endl;
        //     continue;
        // }
        cout<<mergeSortLogic(arr,0,n-1)<<endl;
    }
    return 0;
}