#include<bits/stdc++.h>
using namespace std;
vector<int> prevGreaterElement(vector<int>arr){
    int n=arr.size();
    vector<int>ans;
    stack<int>s;
    s.push(arr[0]);
    ans.push_back(-1);
    for(int i=1;i<n;i++){
        while(!s.empty() && s.top()<arr[i]){
            s.pop();
        }
        int span=s.empty()?-1:s.top();
        ans.push_back(span);
        s.push(arr[i]);
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int>arr1={15,10,18,12,4,6,2,8};
    vector<int>arr2={8,10,12};
    vector<int>arr3={12,10,8};
    vector<int>ans1=prevGreaterElement(arr1);
    vector<int>ans2=prevGreaterElement(arr2);
    vector<int>ans3=prevGreaterElement(arr3);
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