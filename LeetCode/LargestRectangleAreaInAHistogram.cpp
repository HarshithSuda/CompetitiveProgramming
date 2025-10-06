#include<bits/stdc++.h>
using namespace std;
vector<int> previousSmallerElement(vector<int>arr){
    int n=arr.size();
    vector<int>ans;
    stack<int>s;
    s.push(0);
    ans.push_back(-1);
    for(int i=1;i<n;i++){
        while(!s.empty() && arr[s.top()]>=arr[i]){
            s.pop();
        }
        int value=s.empty()?-1:s.top();
        ans.push_back(value);
        s.push(i);
    }
    return ans;
}
vector<int> NextSmallerElement(vector<int>arr){
    int n=arr.size();
    vector<int>ans;
    stack<int>s;
    s.push(n-1);
    ans.push_back(n);
    for(int i=n-2;i>=0;i--){
        while(!s.empty() && arr[s.top()]>=arr[i]){
            s.pop();
        }
        int value=s.empty()?n:s.top();
        ans.push_back(value);
        s.push(i);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
void printVector(vector<int>arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int largestRectangleAreaInHistogram(vector<int>arr){
    int n=arr.size();
    vector<int>ps=previousSmallerElement(arr);
    vector<int>ns=NextSmallerElement(arr);
    int res=0;
    for(int i=0;i<n;i++){
        int curr=arr[i];
        curr+=(i-ps[i]-1)*arr[i];
        curr+=(ns[i]-i-1)*arr[i];
        res=max(res,curr);
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int>arr1={6,2,5,4,1,5,6};
    vector<int>arr2={2,5,1};
    cout<<largestRectangleAreaInHistogram(arr1)<<endl;
    cout<<largestRectangleAreaInHistogram(arr2)<<endl;
    return 0;
}