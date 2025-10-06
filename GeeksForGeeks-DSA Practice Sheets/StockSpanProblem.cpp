#include<bits/stdc++.h>
using namespace std;
vector<int> stockSpan(vector<int>arr){
    int n=arr.size();
    vector<int>ans;
    stack<int>s;
    s.push(0);
    ans.push_back(1);//first element span is always 1
    for(int i=1;i<n;i++){
        while(!s.empty() && arr[s.top()]<=arr[i]){
            s.pop();
        }
        int span=(s.empty())?i+1:i-s.top();
        ans.push_back(span);
        s.push(i);
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int>arr={13,15,12,14,16,8,6,4,10,30};
    vector<int>ans=stockSpan(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}