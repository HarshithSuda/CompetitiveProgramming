#include<bits/stdc++.h>
using namespace std;

vector<int> NextGreaterElement(vector<int>arr){
    int n=arr.size();
    vector<int>ans(n,-1);
    stack<int>s;
    s.push(arr[n-1]);
    ans[n-1]=-1;
    for(int i=n-2;i>=0;i--){
        while(!s.empty() && s.top()<=arr[i]){
            s.pop();
        }
    int value=s.empty()?-1:s.top();
    ans[i]=value;
    s.push(arr[i]);
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int>arr1={5,15,10,8,6,12,9,18};
    vector<int>arr2={8,10,12};
    vector<int>arr3={12,10,8};
    vector<int>ans1=NextGreaterElement(arr1);
    vector<int>ans2=NextGreaterElement(arr2);
    vector<int>ans3=NextGreaterElement(arr3);
    for(int i=0;i<ans1.size();i++){
        cout<<ans1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<ans2.size();i++){
        cout<<ans2[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<ans3.size();i++){
        cout<<ans3[i]<<" ";
    }
    cout<<endl;
    return 0;
}